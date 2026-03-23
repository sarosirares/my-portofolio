package isp.lab6.exercise3;

import java.util.Objects;

public class User {
    //attributes
    private String username;
    private String password;

    //constructor
    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    //methods

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        User user = (User) o;
        return Objects.equals(username, user.username);
    }

    @Override
    public int hashCode() {
        return Objects.hash(username);
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }
}
