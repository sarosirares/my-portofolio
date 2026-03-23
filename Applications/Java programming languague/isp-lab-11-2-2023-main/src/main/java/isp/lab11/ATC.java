package isp.lab11;

import java.util.HashMap;
import java.util.Map;

public class ATC {
private Map<String, Aircraft> aircrafts = new HashMap<>();

    public void addAircraft(String id){
        if (!aircrafts.containsKey(id)) {
            Aircraft aircraft = new Aircraft(id);
            aircraft.start();
            aircrafts.put(id, aircraft);
            System.out.println("Aircraft with id: " + id + " added");
        } else {
            System.out.println("Aircraft with id: " + id + " already exists!");
        }
    }

    public void sendCommand(String id, AtcCommand command){
        Aircraft aircraft = aircrafts.get(id);
        aircraft.receiveAtcCommand(command);
        System.out.println("Aircraft with id " + id + " received command " + command);
    }

    public void showAircrafts(){
        System.out.println("Display aircrfats.");
        if (aircrafts.isEmpty()) {
            System.out.println("There is no aircraft stored!");
        } else {
            for (Map.Entry<String, Aircraft> aircraft : aircrafts.entrySet()) {
                System.out.println("Aircraft id: " + aircraft.getKey());
            }
        }
    }
}

class AtcCommand {
    String command;

    public AtcCommand(String command) {
        this.command = command;
    }

    public String getCommand() {
        return command;
    }

    @Override
    public String toString() {
        return "AtcCommand{" +
                "command='" + command + '\'' +
                '}';
    }
}
