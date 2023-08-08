import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        main2();
        new LeetCode1295().result1295();
        new LeetCode88().run();
        new LeetCode27().run();
    }
    public static void main2() {
        // Create an ArrayList of numbers
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(5);
        numbers.add(2);
        numbers.add(8);
        numbers.add(1);
        numbers.add(10);

        // Print the unsorted ArrayList
        System.out.println("Unsorted ArrayList: " + numbers);

        // Sort the ArrayList in descending order
        Collections.sort(numbers, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                // Reverse the order of comparison for descending order
                return o2.compareTo(o1);
            }
        });

        // Print the sorted ArrayList in descending order
        System.out.println("Sorted ArrayList (Descending): " + numbers);

        // Create an ArrayList of strings
        ArrayList<String> names = new ArrayList<>();
        names.add("Alice");
        names.add("Bob");
        names.add("Charlie");
        names.add("David");
        names.add("Eve");

        // Print the unsorted ArrayList
        System.out.println("Unsorted ArrayList: " + names);

        // Sort the ArrayList in descending order
        Collections.sort(names, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        });

        // Print the sorted ArrayList in descending order
        System.out.println("Sorted ArrayList (Descending): " + names);
    }

}