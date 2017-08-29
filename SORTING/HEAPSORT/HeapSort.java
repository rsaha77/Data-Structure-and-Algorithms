package HEAPSORT;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Map;

// HeapSort using Min Heap
public class HeapSort {

	public static void main (String [] args) {
		int [] arr = new int [] {8, 1, 7, 12, 4, 9, 3, 77, 84, 32, 21, 132, 52};
		MinHeapService minHeapService = new MinHeapService();
		for (int value : arr) {
			minHeapService.insert(value);
		}
		while (!minHeapService.empty()) {
			System.out.println (minHeapService.remove ());
		}
	}

	static interface MinHeapInterface {
		void swap (int a, int b);
		int getParent (int child);
		void insert (int value);
		int remove ();
		void bubbleUp ();
		void bubbleDown ();
		boolean empty();
	}

	static class MinHeapService implements MinHeapInterface {
		ArrayList <Integer> list = new ArrayList<>();

		public boolean empty() {
			return list.isEmpty();
		}

		public void swap (int a, int b) {
			int temp = list.get(a);
			list.set (a, list.get(b));
			list.set (b, temp);
		}

		public int getParent (int child) {
			if (child % 2 == 0) {
				return child / 2 - 1;
			}
			return child / 2;
		}

		public void insert (int value) {
			list.add (value);
			bubbleUp();
		}

		public void bubbleUp() {
			int child = list.size() - 1;
			int parent = getParent (child);
			while (parent >= 0 && list.get(parent) > list.get(child)) {
				swap (child, parent);
				child = parent;
				parent = getParent (child);
			}
		}

		public int remove() {
			int value = list.get(0);
			swap (0, list.size() - 1);
			list.remove (list.size() - 1);
			bubbleDown();
			return value;
		}

		public void bubbleDown() {
			int par = 0, lc, rc;
			while (true) {
				lc = par * 2 + 1;
				rc = par * 2 + 2;
				int smallestIdx = par;
				if (lc < list.size() && list.get(lc) < list.get(smallestIdx)) {
					smallestIdx = lc;
				}
				if (rc < list.size() && list.get(rc) < list.get(smallestIdx)) {
					smallestIdx = rc;
				}
				if (smallestIdx == par) {
					break;
				} else {
					swap (smallestIdx, par);
					par = smallestIdx;
				}
			}
		}
	}
}