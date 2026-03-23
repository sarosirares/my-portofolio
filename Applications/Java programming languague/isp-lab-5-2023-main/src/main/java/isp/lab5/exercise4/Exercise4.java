package isp.lab5.exercise4;

import java.time.LocalDate;

public class Exercise4 {
    public static void main(String[] args) {
        //initializing 2 users, one of type client and one of type organiser
        Client client = new Client("1", "Rares");
        Organiser organiser = new Organiser("2", "Dan");

        //using abstract function form abstract class user
        client.displayUserInfo();
        organiser.displayUserInfo();

        System.out.println();
        client.buyTicket("Music Concert", LocalDate.of(2025,12,3));
        client.buyTicket("Tennis Open", LocalDate.of(2025,1,17));
        client.buyTicket("Football Match", LocalDate.of(2025,10,11));

        //after buying some tickets
        System.out.println();
        client.displayUserInfo();

        //displaying all tickets that user "Rares" has
        System.out.println();
        client.viewTickets();

        //scanning the first ticket
        System.out.println();
        organiser.scanTicket(client.getTicket()[0]);

        System.out.println();
        client.viewTickets();

        //scanning the first ticket
        System.out.println();
        organiser.scanTicket(client.getTicket()[0]);
    }
}
