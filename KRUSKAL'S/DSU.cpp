#include <bits/stdc++.h>
using namespace std;

class DSU {
  vector <int> par, siz;
  
public:
  
  DSU (int n) {
    par.resize(n);
    siz.resize(n);
    for (int i = 0; i < n; ++i) {
      par [i] = i;
      siz [i] = 1;
    }
  }
  
  int get_par (int x) {
    if (par [x] != x) par [x] = get_par (par [x]); // Lazily updating par[x]
    return par[x];
  }
  
  bool join (int a, int b) {
    a = get_par(a);
    b = get_par(b);
    if (a == b) {
      return false;
    }
    if (siz [a] >= siz [b]) { // As it will take less time to **FIND** the root
      siz [a] += siz [b];
      par [b] = a;
    } else {
      siz [b] += siz [a];
      par [a] = b;
    }
    return true;
  }
};
