package isp.lab5.exercise4;

public enum TicketStatus {
    VALID("Valid Ticket"),
    USED("Used Ticket"),
    INVALID("Invalid Ticket");

    private String displayName;

    TicketStatus(String displayName) {
        this.displayName = displayName;
    }

    @Override
    public String toString() {
        return this.displayName;
    }
}
