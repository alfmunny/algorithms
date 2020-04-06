package MergeSort;
import java.io.*;
import java.util.Scanner;
import libs.Input;
import libs.Output;

public class Merge {
    private Merge() {
    } 
    private static void merge(int[] a, int[] aux, int lo, int mid, int hi) {
        // copy to aux
        for (int k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }
        // merge back to a[]
        int i = lo, j = mid+1;
        for (int k = lo; k <= hi; k++) {
            if      (i > mid)           a[k] = aux[j++]; // copy the right rest
            else if (j > hi)            a[k] = aux[i++]; // copy the left rest
            else if (aux[j] < aux[i])   a[k] = aux[j++]; // copy the right one back
            else                        a[k] = aux[i++]; // copy the left one back
        }
    }

    private static void sort(int[] a, int[] aux, int lo, int hi) {
        if (hi <= lo) return;
        int mid = (lo + hi) / 2;
        sort(a, aux, lo, mid);      // ensure left part sorted 
        sort(a, aux, mid+1, hi);    // ensure right part sorted
        merge(a, aux, lo, mid, hi); // merge tow sorted part
    }

    public static void sort(int[] a) {
        int[] aux = new int[a.length];
        sort(a, aux, 0, a.length - 1);
    }

    public static void main(String[] args) {
        int[] a = Input.ReadIntegers(System.in);
        sort(a);
        Output.show(a);
    }
}
