package isp.lab5.exercise4;

import java.time.LocalDate;
import java.util.List;

public class Client extends User {
    //attributes
    private Ticket[] ticket = new Ticket[100];
    private int ticketCounter = 0;
    private TicketManager cTicketManager = new TicketManager();

    //constructor
    public Client(String userId, String userName) {
        super(userId, userName);
    }

    //methods
    public void buyTicket(String eventName, LocalDate date) {
        ticket[ticketCounter] = cTicketManager.generateTicket(eventName, date);
        ticketCounter++;
        System.out.println("Ticket bought!");
    }

    public void viewTickets() {
        System.out.println("This user's tickets are:");
        for (int i = 0; i < ticketCounter; i++) {
            System.out.println(ticket[i].toString());
        }
    }

    public Ticket[] getTicket() {
        return ticket;
    }

    @Override
    public void displayUserInfo() {
        System.out.println("Id: " + getUserId() +
                ", Client name: " + getUserName() +
                ", has " + (ticketCounter) + " tickets.");
    }
}
