package isp.lab7.safehome;

import java.util.Objects;

public class Tenant {
    //attributes
    private String name;

    //constructor
    public Tenant(String name) {
        this.name = name;
    }

    //method

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Tenant tenant = (Tenant) o;
        return Objects.equals(name, tenant.name);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(name);
    }
}
