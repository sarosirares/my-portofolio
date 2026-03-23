package isp.lab5.exercise4;

import org.junit.Assert;
import org.junit.Test;

import java.time.LocalDate;

public class Exercise4Test {
    @Test
    public void validateTest() {
        Client clientTest = new Client("1", "testclient");
        TicketManager ticketManager = new TicketManager();
        Organiser organiserTest = new Organiser("2", "testorganiser");

        clientTest.buyTicket("testEvent1", LocalDate.of(2025,12,24)); //valid ticket in terms of date
        clientTest.buyTicket("testEvent2", LocalDate.of(2022,1,10)); //invalid ticket in terms of date (outdated)

        //checking if the ticket is valid or invalid

        Assert.assertTrue(ticketManager.validateTicket(clientTest.getTicket()[0])); //valid ticket
        Assert.assertFalse(ticketManager.validateTicket(clientTest.getTicket()[1]));//invalid ticket

        //validating the ticket
        organiserTest.scanTicket(clientTest.getTicket()[0]);

        //validating the ticket that is invalid
        organiserTest.scanTicket(clientTest.getTicket()[1]);

        Assert.assertEquals(TicketStatus.INVALID ,clientTest.getTicket()[1].getTicketStatus());

        Assert.assertEquals(clientTest.getTicket()[0].toString(), "Ticket{ticketId=0, eventName='testEvent1', date=2025-12-24, ticketStatus=Used Ticket}");
    }
}
