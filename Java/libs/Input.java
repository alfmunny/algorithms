package libs;
import java.io.*;
import java.util.Scanner;

public class Input {
    public static int[] ReadIntegers(InputStream in) {
        Scanner s = new Scanner(in);
        String[] input = s.nextLine().split("\\s+");
        int[] a = new int[input.length];
        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
        return a;
    }

    public static void main(String[] args) {
        System.out.println("Input class");
    }
}
