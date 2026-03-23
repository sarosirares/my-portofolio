package isp.lab5.exercise4;

import java.time.LocalDate;

public class Ticket {
    //attributes
    private int ticketId;
    private String eventName;
    private LocalDate date;
    private TicketStatus ticketStatus;

    //constructor (in the image, it's corespondent is Generate ticket)
    public Ticket(int ticketId, String eventName, LocalDate date) {
        this.ticketId = ticketId;
        this.eventName = eventName;
        this.date = date;
        if (date.isBefore(LocalDate.now())) {
            this.ticketStatus = TicketStatus.INVALID; //if the ticket date is after current date, the ticket is invalid
        } else {
            this.ticketStatus = TicketStatus.VALID; //when a ticket is generated it is valid
        }
    }

    public TicketStatus getTicketStatus() {
        return ticketStatus;
    }

    public void setTicketStatus(TicketStatus ticketStatus) {
        this.ticketStatus = ticketStatus;
    }

    @Override
    public String toString() {
        return "Ticket{" +
                "ticketId=" + ticketId +
                ", eventName='" + eventName + '\'' +
                ", date=" + date +
                ", ticketStatus=" + ticketStatus +
                '}';
    }
}
