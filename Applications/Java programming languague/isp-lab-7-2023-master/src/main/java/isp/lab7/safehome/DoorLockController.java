package isp.lab7.safehome;

import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DoorLockController implements ControllerInterface {
    //attributes
    private Map<Tenant, AccessKey> validAccess = new HashMap<>();
    private List<AccessLog> accessLogs;
    private Door door;
    private int tries = 0;

    //constructor
    public DoorLockController(List<AccessLog> accessLogs, Door door) {
        this.accessLogs = accessLogs;
        this.door = door;
    }

    //methods
    public DoorStatus enterPin(String pin) throws InvalidPinException, TooManyAttemptsException {
        AccessKey checkPin = new AccessKey(pin);
        if (pin.equals(MASTER_KEY)) {
            System.out.println("MasterKey used! Tries reset to 0!");
            tries = 0;
            door.unlockDoor();
            accessLogs.add(new AccessLog("UNKNOWN", LocalDateTime.now(), "Unlocking door using MASTER KEY", door.getStatus(), ""));
            return door.getStatus();
        }
        if (tries != 2) {
            for (Map.Entry<Tenant, AccessKey> entry : validAccess.entrySet()) {
                if (entry.getValue().equals(checkPin)) {
                    tries = 0;
                    if (door.getStatus() == DoorStatus.OPEN) {
                        door.lockDoor();
                        accessLogs.add(new AccessLog(entry.getKey().getName(), LocalDateTime.now(), "Locking door using key " + checkPin.getPin(), door.getStatus(), ""));
                    } else {
                        door.unlockDoor();
                        accessLogs.add(new AccessLog(entry.getKey().getName(), LocalDateTime.now(), "Unlocking door using key " + checkPin.getPin(), door.getStatus(), ""));
                    }
                }
            }
            if (!validAccess.containsValue(checkPin)) {
                tries++;
                accessLogs.add(new AccessLog("UNKNOWN", LocalDateTime.now(), "Trying to unlock door with pin " + checkPin.getPin(), door.getStatus(), "InvalidPinException"));
                System.out.println("Tries left: " + (3 - tries));
                throw new InvalidPinException("Invalid Pin introduced!");
            }
        } else {
            accessLogs.add(new AccessLog("UNKNOWN", LocalDateTime.now(), "Trying to unlock door too many times", door.getStatus(), "TooManyAttemptsException"));
            throw new TooManyAttemptsException("You failed 3 times in a row! Master key must be used to unlock door!");
        }
        return door.getStatus();
    }

    public void addTenant(String pin, String tenantName) throws TenantAlreadyExistsException {
        AccessKey newAccessKey = new AccessKey(pin);
        Tenant newTenant = new Tenant(tenantName);
        if (validAccess.containsKey(newTenant)) {
            throw new TenantAlreadyExistsException("There already exists a tenant with this name");
        } else {
            validAccess.put(newTenant, newAccessKey);
        }
    }

    public void removeTenant(String name) throws TenantNotFoundException {
        Tenant deleteTenant = new Tenant(name);
        if (validAccess.containsKey(deleteTenant)) {
            validAccess.remove(deleteTenant);
        } else {
            throw new TenantNotFoundException("There is no tenant with this name");
        }
    }

    public List<AccessLog> getAccessLogs() {
        return accessLogs;
    }
}
