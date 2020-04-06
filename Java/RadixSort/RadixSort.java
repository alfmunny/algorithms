package RadixSort;
import java.util.ArrayList;
import java.util.List;

public class RadixSort {
    public static void radixSort(int[] arr) {

    }

    public void sort(int[] array) {
        int max = array[0];

        for (int i = 0; i < array.length; i++) {
            if (array[i] > max) { max = array[i]; }
        }

        int time = 0;

        while (max > 0) {
            max /= 10;
            time++;
        }

        List<ArrayList> queue = new ArrayList<ArrayList>();

        for(int i = 0; i < 10; i++) {
            ArrayList<Integer> queue1 = new ArrayList<Integer>();
            queue.add(queue1);
        }

        for (int i = 0; i < time; i++) {
            for ( int j = 0; j < array.length; j++) {
                int x = array[j] % (int) Math.pow(10, i+1) / (int) Math.pow(10, i);
                ArrayList<Integer> queue2 = queue.get(x);
                queue2.add(array[j]);
                queue.set(x, queue2);
            }
        }
        int count = 0;

        for (int k = 0; k < 10; k++)
        {
            while(queue.get(k).size() > 0) {
                ArrayList<Integer> queue3 = queue.get(k);
                array[count] = queue3.get(0);
                queue3.remove(0);
                count++;
            }
        }
    }
}
