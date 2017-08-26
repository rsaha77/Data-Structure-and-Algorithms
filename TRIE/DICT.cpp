#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#else
#include "header.h"
#include "debug.h"
#endif
#define sz(s) int((s).size())
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int(i)=0; (i)<(n);++(i))
#define ru(i,a,b) for(int(i)=a;(i)<=(b);++(i))
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef pair <int,int> pii;
typedef int64_t LL;
template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));}
template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
const int MAX_STATES = 200010; // Decreased
 
int trie [MAX_STATES][26];
bool complete_word [MAX_STATES][26];
int idx;
 
inline void insert (string s) {
  int state = 0;
  for (int i = 0; i < sz (s); ++i) {
    int ch = s [i] - 'a';
    if (trie [state][ch] == 0) {
      trie [state][ch] = ++idx;
    }
    if (i == sz (s) - 1) {
      complete_word [state][ch] = 1;
    } else {
      state = trie [state][ch];
    }
  }
}
 
string test_str;
inline void printans (vector <char> &vec) {
  for (int i = 0; i < sz (test_str); ++i) {
    cout << test_str [i];
  }
  for (char ve : vec) {
    cout << ve;
  }
  cout << '\n';
}
 
vector <char> ans;
void dfs (int state) {
  for (int i = 0; i < 26; ++i) {
    if (trie [state][i] > 0) {
      ans.push_back (char (i + 'a'));
      if (complete_word [state][i] == true) {
        printans (ans);
      }
      dfs (trie [state][i]);
      ans.pop_back ();
    }
  }
}
 
inline bool solve (string s) {
  int state = 0;
  for (int i = 0; i < sz (s); ++i) {
    int ch = s [i] - 'a';
    if (trie [state][ch] == 0) {
      return 0;
    }
    state = trie [state][ch];
  }
  int cnt = 0;
  for (int i = 0; i < 26; ++i) {
    if (trie [state][i] == 0) {
      ++cnt;
    }
  }
  if (cnt < 26) {
    dfs (state);
    return 1;
  }
  return 0;
}
 
// Popping back from an empty vector was giving SIGABRT.
 
int main() {
  #ifndef ONLINE_JUDGE
    freopen ("in.txt","r",stdin);
  #endif
  cin.sync_with_stdio (0); cin.tie (0);
  int n;
  cin >> n;
  
  for (int i = 0; i < MAX_STATES; ++i) {
    for (int j = 0; j < 26; ++j) {
      trie [i][j] = 0;
      complete_word [i][j] = 0;
    }
  }
  
  idx = 0;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    insert (str);
  }
  
  int total_query;
  cin >> total_query;
  for (int query_number = 1; query_number <= total_query; ++query_number) {
    cout << "Case #" << query_number << ":\n";
    cin >> test_str;
    bool ok = solve (test_str);
    if (!ok) {
      cout << "No match.\n";
    }
  }
  
  return 0;
}
 