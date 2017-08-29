package MERGESORT;
import java.util.ArrayList;

public class MergeSort {
	static int []arr = new int [] {4,1,5,22,55,231,5,44,66,8,2,6,7};
	public static void main (String [] args) {
		mergeSortMethod (0, arr.length - 1);
		for (int a : arr) {
			System.out.println(a);
		}
	}
	
	static void mergeSortMethod (int l, int r) {
		if (l == r) {
			return;
		}
		int mid = (l + r) / 2;
		mergeSortMethod (l, mid);
		mergeSortMethod (mid + 1, r);
		int lptr = l, rptr = mid + 1;
		ArrayList <Integer> temp = new ArrayList <> ();
		while (lptr <= mid && rptr <= r) {
			while (lptr <=  mid && arr [lptr] <= arr [rptr]) {
				temp.add(arr [lptr++]);
			}
			while (lptr <=  mid && rptr <=  r && arr [rptr] < arr [lptr]) {
				temp.add(arr [rptr++]);
			}
		}
		while (lptr <= mid) temp.add (arr[lptr++]);
		while (rptr <= r) temp.add (arr[rptr++]);
		for (int i = l, j = 0; i <= r; ++i, ++j) {
			arr [i] = temp.get (j);
		}
	}
}
