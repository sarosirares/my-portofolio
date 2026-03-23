package isp.lab7.safehome;

import java.util.Objects;

public class AccessKey {
    //attributes
    private String pin;

    //constructor
    public AccessKey(String pin) {
        this.pin = pin;
    }

    //methods
    public void setPin(String pin) {
        this.pin = pin;
    }

    public String getPin() {
        return pin;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        AccessKey accessKey = (AccessKey) o;
        return Objects.equals(pin, accessKey.pin);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(pin);
    }
}
