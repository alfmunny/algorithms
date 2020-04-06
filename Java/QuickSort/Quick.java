package QuickSort;
import libs.Input;
import libs.Output;

public class Quick {
    public Quick() {
    }

    public static void sort(int[] a) {
        sort(a, 0, a.length - 1);
    }

    private static void sort(int[] a, int lo, int hi) {
        if (hi <= lo) return;

        int j = partition(a, lo, hi);
        sort(a, 0, j-1);
        sort(a, j+1, hi);
    }

    private static void exch(int[] a, int lo, int hi) {
        int tmp = a[lo];
        a[lo] = a[hi];
        a[hi] = tmp;
    }

    private static int partition(int[] a, int lo, int hi) {
        int i = lo, j = hi + 1;
        int v = a[lo];
        while(true) {
            while(a[++i] < v) if (i == hi) break;
            while(a[--j] > v) if (j == lo) break;
            if (i >= j) break;
            exch(a, i, j);
        }

        exch(a, lo, j);
        return j;
    }

    public static void main(String[] args) {
        int[] a = Input.ReadIntegers(System.in);
        sort(a);
        Output.show(a);
    }

}
