#include <iostream>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#ifdef  __linux__
#define _get getchar_unlocked
inline int inp() {int n=0,s=1;char p=_get();if(p=='-')s=-1;while((p<'0'||p>'9')&&p!=EOF&&p!='-')p=_get();if(p=='-')s=-1,p=_get();while(p>='0'&&p<='9')n=(n<<3)+(n<<1)+(p-'0'),p=_get();return n*s;}
#else
inline int inp() {int x;scanf("%d",&x);return x;}
#endif
typedef vector <int> vi;
typedef pair<int,int> pii;
const int N = 1e5 + 11;
const int M = 2e5 + 11;

int MarkedEdge[M];
int par[N], siz[N];
int u[M], v[M];
pii arr[M];

inline int getPar (int x) {
    if(par[x] != x) par[x] = getPar (par[par[x]]);
    return par[x];
}

inline void unite (int x, int y) {
    int a = getPar(x), b = getPar(y);
    if(siz[a] >= siz[b]) siz[a] += siz[b], par[b] = a;
    else siz[b] += siz[a], par[a] = b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int testCase, t=inp();
    for(testCase=1; testCase<=t; testCase++) {
        int n=inp(), m=inp();
        for(int i=0; i<m; i++) MarkedEdge[i]=0;
        for(int i=0; i<m; i++) {
            u[i] = inp(); --u[i];
            v[i] = inp(); --v[i];
            arr[i] = mp(inp(),i);
        }
        sort(arr,arr+m);
        int cost=0;
        for(int i=0; i<n; i++) par[i] = i, siz[i] = 1;
        for(int i=0; i<m; i++) {
            int eno = arr[i].ss;
            int a = getPar(u[eno]);
            int b = getPar(v[eno]);
            arr[i].ss = ~arr[i].ss;
            if(a != b) {
                ++MarkedEdge[eno];
                unite(u[eno],v[eno]);
                cost += arr[i].ff;
            }
        }
        sort(arr,arr+m);
        for(int i=0; i<n; i++) par[i] = i, siz[i] = 1;
        for(int i=0; i<m; i++) {
            int eno = ~arr[i].ss;
            int a = getPar(u[eno]);
            int b = getPar(v[eno]);
            if(a != b) {
                --MarkedEdge[eno];
                unite(u[eno],v[eno]);
            }
        }
        bool ok=true;
        for(int i=0; i<m; i++) {
            if(MarkedEdge[i] != 0) {
                ok = false;
                break;
            }
        }
        if(ok) printf("%d\n",cost);
        else puts("Not Unique!");
    }
}
