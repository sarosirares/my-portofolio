package isp.lab6.exercise3;

import java.util.*;

public class OnlineStore {
    //attributes
    private List<Product> products = new ArrayList<>();
    private Map<String, ActiveSession> sessions = new HashMap<>();

    //methods
    public void addProducts(Product product) {
         products.add(product);
    }

    public List<Product> getProducts() {
        return products;
    }

    public List<Product> getProductsSorted(Comparator<Product> sortCriteria) {
        List<Product> sortedList = new ArrayList<>(products);
        sortedList.sort(sortCriteria);
        return sortedList;
    }

    protected void addSession(String username) {
        if (!sessions.containsKey(username)) {
            sessions.put(username, new ActiveSession(username));
            System.out.println("Session added!");
        } else {
            System.out.println("Session already exists!");
        }
    }

    protected void removeSession(String username) {
        if (sessions.containsKey(username)) {
            sessions.remove(username);
            System.out.println("Session removed!");
        } else {
            System.out.println("Session doesn't exist!");
        }
    }

    public void addToCart(String username, Product product, int quantity) {
        if (products.contains(product)) {
            sessions.get(username).addToCart(product, quantity);
        } else {
            System.out.println("We don't have this product in this store!");
        }
    }

    public String checkout(String username) {
        ActiveSession session = sessions.get(username);
        String checkoutText = "";
        double totalPrice = 0.0;
        //going through each product, and it's quantity from the Map shoppingCart
        for (Map.Entry<Product, Integer> product : session.getShoppingCart().entrySet()) {
            totalPrice += (double)(product.getKey().getPrice() * product.getValue());
            checkoutText = checkoutText
                    + product.getKey().toString() + ", quantity: "
                    + product.getValue() + " = "
                    + (double)(product.getKey().getPrice() * product.getValue())
                    + "\n";
        }
        removeSession(username);
        return checkoutText + "Total price: " + totalPrice;
    }

    public Product searchProduct(String name) {
        for (Product product : products) {
            if (product.getName().equals(name)) {
                return product;
            }
        }
        return null;
    }

    //adding types of comparators
    Comparator<Product> ascName = new Comparator<Product>() {
        @Override
        public int compare(Product o1, Product o2) {
            return o1.getName().compareTo(o2.getName());
        }
    };

    Comparator<Product> desName = new Comparator<Product>() {
        @Override
        public int compare(Product o1, Product o2) {
            return o2.getName().compareTo(o1.getName());
        }
    };

    Comparator<Product> ascPrice = new Comparator<Product>() {
        @Override
        public int compare(Product o1, Product o2) {
            return Double.compare(o1.getPrice(), o2.getPrice());
        }
    };

    Comparator<Product> desPrice = new Comparator<Product>() {
        @Override
        public int compare(Product o1, Product o2) {
            return Double.compare(o2.getPrice(), o1.getPrice());
        }
    };

    //used for unit test
    public Map<String, ActiveSession> getSessions() {
        return sessions;
    }
}
