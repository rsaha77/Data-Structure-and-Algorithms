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
using namespace std;
#define SS(n) scanf("%s",n)
#define pn putchar_unlocked('\n')
#define ps putchar_unlocked(' ')
#define sz(s) int((s).size())
#define rep(i,n) for(int(i)=0; (i)<(n);++(i))
#define ru(i,a,b) for(int(i)=a;(i)<=(b);++(i))
#define rd(i,b,a) for(int(i)=b;(i)>=(a);--(i))
#define clr(a) memset(a,0,sizeof(a))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define tm pv1
typedef long long LL; typedef vector <int> vi; typedef pair<int,int> pii; typedef map <int,int> mii; template <class T> inline T max(T a,T b,T c) {return (max(max(a,b),c));} template <class T> inline T min(T a,T b,T c) {return (min(min(a,b),c));} template <class T> inline T sqr(T x) {return x*x;} inline int inp() {int n=0,s=1;char p=getchar_unlocked();if(p=='-')s=-1;while((p<'0'||p>'9')&&p!=EOF&&p!='-')p=getchar_unlocked();if(p=='-')s=-1,p=getchar_unlocked();while(p>='0'&&p<='9')n=(n<<3)+(n<<1)+(p-'0'),p=getchar_unlocked();return n*s;} void out(int x){if(x<0)putchar_unlocked('-'),x=-x;int ll=0,dd[10];while(x)dd[ll++]=x%10,x/=10;if(!ll)dd[ll++]=0;while(ll--)putchar_unlocked(dd[ll]+48);} inline int ins(int x,int y,int m,int n){return (x>=1&&x<=m&&y>=1&&y<=n);} template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));} template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
const int N = 1e4 + 11;
 
vector <int> g[N];
int anc[N][42], dis[N], b[N], e[N], tm, logn;
 
void dfs(int u, int p) {
  b[u] = tm++;
  anc[u][0] = p;
  for(int i=1; i<=logn; ++i)
    if(anc[u][i-1] == -1) break;
    else anc[u][i] = anc[anc[u][i-1]][i-1];
  for(int i=0; i<sz(g[u]); ++i) {
    int v = g[u][i];
    if(v != p) {
      dis[v] = dis[u] + 1;
      dfs(v,u);
    }
  }
  e[u] = tm-1;
}
 
bool upper(int p, int q) {
  return b[q] >= b[p] && e[q] <= e[p];
}
 
int lca(int a, int b) {
  if(upper(a,b)) return a;
  if(upper(b,a)) return b;
  for(int i=logn; i>=0; --i) if(anc[a][i] > 0)
    if(!upper(anc[a][i],b))
      a = anc[a][i];
  return anc[a][0];
}
 
int main() {
  #ifndef ONLINE_JUDGE
    freopen("in4.txt","r",stdin);
  #endif
  for(int tc=1,t=inp(); tc<=t; ++tc) {
    int n=inp();
    if(tc > 1) for(int i=1; i<=n; ++i) g[i].clear();
    ru(i,1,n) {
      int k = inp();
        while(k--) {
        int v = inp();
        g[i].pb(v);
      }
    }
    int root = 1;
    logn = log2(n)+1;
    memset(anc,-1,sizeof(anc));
    tm = dis[root] = 0, dfs(root,-1);
    printf("Case %d:\n",tc);
    int Quora=inp();
    while(Quora--) {
      int p=inp(), q=inp();
      out(lca(p,q)); pn;
    }
  }
}
