package main;
import java.util.ArrayList;
public class MaxHeap {
	
	public static void main (String [] args) {
		int [] arr = new int [] {8, 1, 7, 12, 4, 9, 3, 77, 84, 32, 21, 132, 52};
		MaxHeapService maxHeapService = new MaxHeapService();
		for (int value : arr) {
			maxHeapService.insert(value);
		}
		while (!maxHeapService.empty()) {
			System.out.print(maxHeapService.remove () + " ");
		}
	}

	static interface MaxHeapInterface {
		void swap (int a, int b);
		int getParent (int child);
		void insert (int value);
		int remove ();
		void bubbleUp ();
		void bubbleDown ();
		boolean empty();
	}

	static class MaxHeapService implements MaxHeapInterface {
		ArrayList <Integer> list = new ArrayList<>();
		@Override
		
		public boolean empty() {
			return list.isEmpty();
		}

		@Override
		public void swap (int a, int b) {
			int temp = list.get(a);
			list.set (a, list.get(b));
			list.set (b, temp);
		}

		@Override
		public int getParent (int child) {
			if (child % 2 == 0) {
				return child / 2 - 1;
			}
			return child / 2;
		}

		@Override
		public void insert (int value) {
			list.add (value);
			bubbleUp();
		}

		@Override
		public void bubbleUp() {
			int child = list.size() - 1;
			int parent = getParent (child);
			while (parent >= 0 && list.get(parent) < list.get(child)) {
				swap (child, parent);
				child = parent;
				parent = getParent (child);
			}
		}

		@Override
		public int remove() {
			int value = list.get(0);
			swap (0, list.size() - 1);
			list.remove (list.size() - 1);
			bubbleDown();
			return value;
		}

		@Override
		public void bubbleDown() {
			int par = 0, lc, rc;
			while (true){
				lc = par * 2 + 1;
				rc = par * 2 + 2;
				int largestIdx = par;
				if (lc < list.size() && list.get(lc) > list.get(largestIdx)) {
					largestIdx = lc;
				}
				if (rc < list.size() && list.get(rc) > list.get(largestIdx)) {
					largestIdx = rc;
				}
				if (largestIdx == par) {
					break;
				} else {
					swap (largestIdx, par);
					par = largestIdx;
				}
			}
		}
	}
}
