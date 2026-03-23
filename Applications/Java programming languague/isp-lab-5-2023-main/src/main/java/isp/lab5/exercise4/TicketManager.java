package isp.lab5.exercise4;

import java.time.LocalDate;

public class TicketManager {
    //attributes
    private int id = 0;

    //methods
    public Ticket generateTicket(String eventName, LocalDate date) {
        return new Ticket(id++, eventName, date);
    }

    public boolean validateTicket(Ticket ticket) {
        return ticket.getTicketStatus() == TicketStatus.VALID;
    }
}
