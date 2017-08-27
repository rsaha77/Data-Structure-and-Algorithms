#include <vector>
#include <iostream>
using namespace std;

template <class T>
class MaxHeap {
  private:
    vector <T> list;
    int getParent (int child);
    int getLeftChild ();
    int getRightChild ();
    void bubbleUp ();
    void bubbleDown ();
  public:
    bool empty();
    void insert (T);
    T remove ();
};

template <class T>
MaxHeap <T> Maxheap () {
  
}

template <class T>
bool MaxHeap <T> :: empty () {
  return list.size() == 0;
}

template <class T>
int MaxHeap <T> :: getParent (int child) {
  if (child % 2 == 0) {
    return child / 2 - 1;
  }
  return child / 2;
}

template <class T>
void MaxHeap <T> :: insert (T value) {
  list.push_back (value);
  bubbleUp();
}

template <class T>
void MaxHeap <T> :: bubbleUp () {
  int child = list.size() - 1;
  int parent = getParent (child);
  while (parent >= 0 && list [parent] < list [child]) {
    swap (list [child], list [parent]);
    child = parent;
    parent = getParent (child);
  }
}

template <class T>
T MaxHeap <T> :: remove () {
  T value = list[0];
  swap (list [0], list.back());
  list.pop_back();
  bubbleDown();
  return value;
}

template <class T>
void MaxHeap <T> :: bubbleDown () {
  int par = 0, lc, rc;
  while (true){
    lc = par * 2 + 1;
    rc = par * 2 + 2;
    int largestIdx = par;
    if (lc < list.size() && list [lc] > list [largestIdx]) {
      largestIdx = lc;
    }
    if (rc < list.size() && list [rc] > list [largestIdx]) {
      largestIdx = rc;
    }
    if (largestIdx == par) {
      break;
    } else {
      swap (list [largestIdx], list [par]);
      par = largestIdx;
    }
  }
}

int main () {
  int arr [] = {8, 1, 7, 12, 4, 9, 3, 77, 84, 32, 21, 132, 52};
  string str [] = {"hello", "darkness", "my", "old", "friend","ole", "olf", "olc"};
  
  MaxHeap <string> maxHeap;
  for (string value: str) {
    maxHeap.insert (value);
  }
  
  while (!maxHeap.empty()) {
    cout << maxHeap.remove () << ' ';
  }
}