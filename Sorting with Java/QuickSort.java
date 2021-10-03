import java.util.*;

public class QuickSort {
    int partition(int[] a, int s, int e) {
        int pivot = a[e];
        int p = s;
        int temp;
        for (int j = s; j < e; j++) {
            if (a[j] < pivot) {
                if (j != p) {
                    temp = a[p];
                    a[p] = a[j];
                    a[j] = temp;
                }
                p++;
            }
        }
        temp = a[p];
        a[p] = a[e];
        a[e] = temp;
        return p;
    }

    void quickSort(int[] arr, int start, int end) {
        if (start < end) {
            int p = partition(arr, start, end);
            quickSort(arr, start, p - 1);
            quickSort(arr, p + 1, end);
        }

    }

    public static void main(String[] args) {
        QuickSort q5 = new QuickSort();
        int n;
        Random r = new Random();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = r.nextInt(500);
        }
        System.out.println("The array before sorting is: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        long start = System.nanoTime();
        q5.quickSort(arr, 0, n - 1);
        long end = System.nanoTime();
        System.out.println("\nTime taken by merge sort is " + (end - start) + " ns");

        System.out.println("The array after sorting is: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}