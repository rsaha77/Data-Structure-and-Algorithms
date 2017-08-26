#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


#define ff first
#define ss second
typedef long long LL;
typedef pair<int,int> pii;

// Optimise Input Speed
#ifdef  __linux__
#define _get getchar_unlocked
inline int inp() {int n=0,s=1;char p=_get();if(p=='-')s=-1;while((p<'0'||p>'9')&&p!=EOF&&p!='-')p=_get();if(p=='-')s=-1,p=_get();while(p>='0'&&p<='9')n=(n<<3)+(n<<1)+(p-'0'),p=_get();return n*s;}
#else
inline int inp() {int x;scanf("%d",&x);return x;}
#endif
const int N = 1e4 + 11; // max nodes


int par[N];
int siz[N];

inline int getPar(int x) {
  if(par[x] != x) par[x]=getPar(par[x]); // Lazily updating par[x]
  return par[x];
}
inline void Union(int a, int b) {
  a = getPar(a), b = getPar(b);
  if (siz[a] >= siz[b]) siz[a] += siz[b], par[b] = a; // doing this bcz it will take less time to **FIND** the root
  else siz[b] += siz[a], par[a] = b;
}

int main() {
  int testCase, t=1, i;
  for(testCase=1; testCase<=t; testCase++) {
    int nodes = inp(), m = inp();
    for (int i=1; i<=nodes; ++i) {
      par[i]=i;
      siz[i]=1;
    }
    vector <pair<int, pii> > v;
    for (int i=1; i<=m; ++i) {
      int x=inp(), y=inp(), c=inp();
      v.push_back (make_pair (c,make_pair (x,y)));
    }
    sort (v.begin(), v.end());
    LL ans=0;
    int opti=0;
    for (i=0; i<int(v.size()); i++) {
      pair<int, pii> it = v[i];
      if (getPar(it.ss.ff) != getPar(it.ss.ss)) {
        ++opti;
        ans += LL(it.ff);
        Union(it.ss.ff, it.ss.ss);
      }
      if(opti == nodes-1) break;
    }
    printf("%lld\n",ans);	
  }
}
