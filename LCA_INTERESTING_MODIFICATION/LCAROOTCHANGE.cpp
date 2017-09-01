#include <map>
#include <set>
#include <list>
#include <cmath>
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
#define sz(s) int((s).size())
#define rep(i,n) for(int(i)=0; (i)<(n);++(i))
#define ru(i,a,b) for(int(i)=a;(i)<=(b);++(i))
#define rd(i,b,a) for(int(i)=b;(i)>=(a);--(i))
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long LL; typedef vector <int> vi; typedef pair<int,int> pii; typedef map <int,int> mii; template <class T> inline T sqr(T x) {return x*x;} inline int ins(int x,int y,int m,int n){return (x>=1&&x<=m&&y>=1&&y<=n);} template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));} template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
const int N = 200000 + 10;
 
vector <int> g[N];
int anc[N][24], dis[N], bb[N], ee[N], tim, logn;
 
void dfs (int u, int p) {
  bb[u] = tim++;
  anc[u][0] = p;
  for (int i = 1; i <= logn; ++i)
    if(anc[u][i-1] == -1) break;
    else anc[u][i] = anc[anc[u][i-1]][i-1];
  for (int v: g[u]) if(v != p) {
    dis[v] = dis[u] + 1;
    dfs(v,u);
  }
  ee[u] = tim-1;
}
 
inline bool upper (int p, int q) {
  return bb[q] >= bb[p] && ee[q] <= ee[p];
}
 
inline int lca (int a, int b) {
  if (upper (a,b)) return a;
  if (upper (b,a)) return b;
  for (int i = logn; i >= 0; --i) if (anc[a][i] > 0)
    if (!upper(anc[a][i],b))
      a = anc[a][i];
  return anc[a][0];
}
 
inline int dist (int a, int b) {
  return dis[a] + dis[b] - 2*dis[lca (a, b)];
}
 
inline int solve (int r, int a, int b) {
  pii arr[6];
  arr[0].ss = r;
  arr[1].ss = a;
  arr[2].ss = b;
  arr[3].ss = lca (r, a);
  arr[4].ss = lca (r, b);
  arr[5].ss = lca (a, b);
  for (int i = 0; i < 6; ++i) {
    int x = arr[i].ss;
    arr[i].ff = dist (x, r) + dist (x, a) + dist (x, b);
  }
  sort (arr, arr + 6);
  return arr[0].ss;
}
 
int main() {
  #ifndef ONLINE_JUDGE
    freopen ("in.txt","r",stdin);
  #endif
  cin.sync_with_stdio(0); cin.tie(0);
  int t = 1;
  for (int tc = 0; tc < t; ++tc) {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    int root = 1;
    logn = 1; while ((1 << logn) <= n) ++logn;
    memset(anc,-1,sizeof(anc));
    tim = dis[root] = 0, dfs(root,-1);
    int quora;
    cin >> quora;
    while (quora--) {
      int root, a, b;
      cin >> root >> a >> b;
      cout << solve (root, a, b) << '\n';
    }
  }
}