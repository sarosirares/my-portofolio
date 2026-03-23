package isp.lab5.exercise1;

public class Customer {
    //attributes
    private String customerId;
    private String name;
    private String phone;
    Address custAddress;

    //constructor
    public Customer(String customerIDC, String nameC, String phoneC, Address custAddressC) {
        this.customerId = customerIDC;
        this.name = nameC;
        this.phone = phoneC;
        this.custAddress = custAddressC;
    }
}
