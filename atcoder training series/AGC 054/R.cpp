#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define __builtin_popcount __builtin_popcountll
#define BIT(x,i) (((x)>>(i))&1)
#define sz(x) ((int)(x).size())
#define MASK(x) (1<<(x))
#define ll long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define all(c) ((c).begin()), ((c).end())
#define LOCAL_DEBUG
using namespace std;
const int inf=1e9;
const ll INF=1e18;
int numt;
typedef pair <int, int> ii;
typedef vector <int> vi;
template <class T> bool minimize(T &x,T y){if(x>y){x=y;return true;}return false;}
template <class T> bool maximize(T &x,T y){if(x<y){x=y;return true;}return false;}
void setIO(string name = ""){
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".inp").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

const int N = 5005;
const ll mod = (ll) 1e9 + 7;
const ll base = 311;
int pw[N];

struct HASH {
  int n;
  vector <int> hash;

  void init(string s) {
    n = sz(s);
    hash.resize(n + 1);
    hash[0] = 0;
    for (int i = 1; i <= n; i++)
      hash[i] = (1LL * hash[i - 1] * base + s[i - 1]) % mod;
  }

  int getHash(int l, int r) {
    int res = (hash[r] - 1LL*hash[l - 1] * pw[r - l + 1] + mod*mod) % mod;
    return res;
  }
  int getHash() {
    return getHash(1, n);
  }
};
void precHash() {
  pw[0] = 1;
  FOR(i, 1, N - 1)
    pw[i] = 1LL*pw[i - 1] * base % mod;
}


string s;
int dp[N], n;

int main()
{
  setIO("");
  cin >> s;
  n = sz(s);
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  precHash();
  HASH hashS;
  hashS.init(s);

  REP(i, n)
    FOR(len, 1, n - i) {
      int r = i + len;
      while (r <= n) {
        minimize(dp[r], dp[i] + len);
        if (r + len > n || hashS.getHash(i + 1, i + len) != hashS.getHash(r + 1, r + len)) break;
        r += len;
      }
    }
  cout << dp[n];
}

