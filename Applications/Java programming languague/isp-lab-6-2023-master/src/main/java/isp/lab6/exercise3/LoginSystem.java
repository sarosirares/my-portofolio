package isp.lab6.exercise3;

import java.util.HashSet;
import java.util.Set;

public class LoginSystem {
    //attributes
    private Set<User> users = new HashSet<>();
    private OnlineStore store;

    //constructors
    public LoginSystem(OnlineStore store) {
        this.store = store;
    }

    //methods
    public void register(String username, String password) {
        User user = new User(username, password);
        if (users.add(user)) {
            System.out.println("User added!");
        } else {
            System.out.println("User already exists!");
        }
    }

    public boolean login(String username, String password) {
        User user = new User(username, password);
        if (users.contains(user)) {
            for (User aux : users) {
                if(aux.getUsername().equals(username)) { //or we could've used a method to search user
                    if (aux.getPassword().equals(password)) {
                        System.out.println("Login successful!");
                        store.addSession(username);
                        return true;
                    } else {
                        System.out.println("Password is incorrect!");
                    }
                }
            }
        } else {
            System.out.println("There is no user with that username!");
        }
        return false;
    }

    public boolean logout(String username) {
        User user = new User(username, "");
        //the password is not important because I overrode the methods equals() and hashCode()
        //to check only for username
        if (users.contains(user)) {
            System.out.println("Logged out!");
            store.removeSession(username);
            return true;
        }
        System.out.println("There is no user with that username!");
        return false;
    }

    public Set<User> getUsers() {
        return users;
    }
}
