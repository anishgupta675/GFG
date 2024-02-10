import java.lang.*;
import java.util.*;

class Solution {

    private static final Solution sol = new Solution();
    private static final Scanner sc = new Scanner(System.in);

    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private static void reverse(int[] a, int start, int end) {
        while(start < end) {
            swap(a, start, end);
            start++;
            end--;
        }
    }

    private static void nextPermutation(int[] a) {
        int i, j;
        for(i = a.length - 2; i >= 0; i--) if(a[i] < a[i + 1]) break;
        if(i < 0) reverse(a, 0, a.length - 1);
        else {
            for(j = a.length - 1; j > i; j--) if(a[j] > a[i]) break;
            swap(a, i, j);
            reverse(a, i + 1, a.length - 1);
        }
    }

    public static void main(String[] args) throws Exception {
        int i = 0, n = sc.nextInt();
        int[] a = new int[(int)Math.ceil(Math.log10(n))];
        while(n > 0) {
            a[i++] = n % 10;
            n/= 10;
        }
        nextPermutation(a);
        for(i = 0; i < a.length; i++) n = (10 * n) + a[i];
        System.out.println(n);
    }
}