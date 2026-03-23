package isp.lab5.exercise4;

public abstract class User {
    //attributes
    private String userId;
    private String userName;

    //constructor
    public User(String userId, String userName) {
        this.userId = userId;
        this.userName = userName;
    }

    //methods
    public void setUserId(String userId) { this.userId = userId; }

    public String getUserId() { return userId; }

    public void setUserName(String userName) { this.userName = userName; }

    public String getUserName() { return userName; }

    public abstract void displayUserInfo();
}
