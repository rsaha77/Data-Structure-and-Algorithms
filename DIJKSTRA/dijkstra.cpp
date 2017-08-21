#include <map>
#include <queue>
#include <iostream>
using namespace std;
#define SS(n) scanf("%s",n)
#define pn putchar('\n');
#define ps putchar(' ')
#define sz(s) int((s).size())
#define rep(i,a,b) for(int(i)=a;(i)<=(b);++(i))
#define per(i,b,a) for(int(i)=b;(i)>=(a);--(i))
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long LL; typedef vector <int> vi; typedef pair<int,int> pii; typedef map <int,int> mii; template <class T> inline T max(T a,T b,T c) {return (max(max(a,b),c));} template <class T> inline T min(T a,T b,T c) {return (min(min(a,b),c));} template <class T> inline T sqr(T x) {return x*x;} inline int inp() {int n=0,s=1;char p=getchar();if(p=='-')s=-1;while((p<'0'||p>'9')&&p!=EOF&&p!='-')p=getchar();if(p=='-')s=-1,p=getchar();while(p>='0'&&p<='9')n=(n<<3)+(n<<1)+(p-'0'),p=getchar();return n*s;} inline void out(int x){if(x<0)putchar('-'),x=-x;int ll=0,dd[10];while(x)dd[ll++]=x%10,x/=10;if(!ll)dd[ll++]=0;while(ll--)putchar(dd[ll]+48);} inline int ins(int x,int y,int m,int n){return (x>=1&&x<=m&&y>=1&&y<=n);} template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));} template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
const int N = 1e4 + 11;
const int inf = INT_MAX;

vector <pii> edge[N];
int dis[N];

void solve(int so, int si) {
  priority_queue <pii> qq;
  qq.push (mp (-1,so));
  while (!qq.empty()) {
    int udis = ~qq.top().ff, u = qq.top().ss; qq.pop();
    if (u == si) break;
    for (int i=0; i<sz(edge[u]); ++i) {
      int v = edge[u][i].ff;
      int uv = edge[u][i].ss;
      if (dis[v] > udis + uv) {
        dis[v] = udis + uv;
        qq.push (mp (~dis[v],v));
      }
    }
  }
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
  int tc, t=inp();
  for(tc=1; tc<=t; ++tc) {
    int n=inp(), m=inp();
    for(int i=1; i<=n; ++i) {
      dis[i]=inf;
      edge[i].clear();
    }
    while(m--) {
      int u=inp(), v=inp(), c=inp();
      edge[u].pb (mp (v,c));
    }
    int so=inp(), si=inp();
    solve (so,si);
    if (dis[si] != inf) {
      out(dis[si]);
    } else {
      printf("NO PATH");
    }
    putchar_unlocked('\n');
  }
}
