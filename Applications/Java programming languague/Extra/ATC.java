package isp.lab11;

import java.util.HashMap;
import java.util.Map;

public class ATC {
    //map id for aircrafts
    private Map<String, AirCraft> aircraftMap=new HashMap<>();


    public void addAircraft(String id){
        if(!aircraftMap.containsKey(id)){
            AirCraft airCraft =  new AirCraft(id);
             airCraft.start();
             aircraftMap.put(id, airCraft);
            System.out.println("Aircraft with id " + id + " added");
        }else{
            System.err.println("Aircraft with id " + id + " already exists");
        }

    }

    public void sendCommand(String id, AtcCommand command){
        AirCraft airCraft = aircraftMap.get(id);
        airCraft.receiveAtcCommand(command);
        System.out.println("Aircraft with id " + id + " received command " + command);
    }

    public void showAircrafts(){
        System.out.println("Display aircrfats.");
        aircraftMap.forEach((id,airCraft)->System.out.println("Aircraft with id " + id + "Aircraft: " +airCraft.toString()));
    }
}

class AtcCommand {
    String command;
    private int altitude;

    public AtcCommand(String command) {
        this.command = command;
    }

    public String getCommand() {
        return command;
    }
    public int getAltitude(){
        return altitude;
    }

    @Override
    public String toString() {
        return "AtcCommand{" +
                "command='" + command + '\'' +
                ", altitude=" + altitude +
                '}';
    }
}
