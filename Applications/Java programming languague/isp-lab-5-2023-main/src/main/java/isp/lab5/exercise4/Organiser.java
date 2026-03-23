package isp.lab5.exercise4;

public class Organiser extends User {
    //attributes
    private TicketManager oticketManager = new TicketManager();

    //constructor
    public Organiser(String userId, String userName) {
        super(userId, userName);
    }

    //methods
    public void scanTicket(Ticket ticket) {
        if(oticketManager.validateTicket(ticket)) {
            ticket.setTicketStatus(TicketStatus.USED);
            System.out.println("Ticket validated!");
        } else if(ticket.getTicketStatus() == TicketStatus.INVALID) {
            System.out.println("Ticket is invalid!");
        } else if(ticket.getTicketStatus() == TicketStatus.USED) {
            System.out.println("Ticket was already used!");
        }
    }

    @Override
    public void displayUserInfo() {
        System.out.println("Id: " + getUserId() +
                ", Organiser name: " + getUserName());
    }
}
