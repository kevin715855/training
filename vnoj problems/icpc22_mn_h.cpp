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
using namespace std;
const int mod=1e9+7;
const int inf=1e9;
const ll INF=1e18;
const int maxn=1e6+3;
int numt;
template <class T> bool minimize(T &x,T y){if(x>y){x=y;return true;}return false;}
template <class T> bool maximize(T &x,T y){if(x<y){x=y;return true;}return false;}
template <class T> void add (T &x,T y) {x+=y;if(x >= mod)x-=mod;}
void setIO(string name = ""){
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		//freopen((name + ".out").c_str(), "w", stdout);
	}
}

int n;
string l, r;
ll dp[maxn][2][2];
ll DP(int i, bool okl, bool okr) {
  if (i == n)
    return 1;

  if (dp[i][okl][okr] != -1)
      return dp[i][okl][okr];

  ll res = 0;

  for (ll digit = 0; digit <= 9; digit++)
    if ((okl || digit >= l[i]) && (okr || digit <= r[i]))
      maximize(res, DP(i+1,okl||(digit>l[i]), okr||(digit<r[i]))*digit);
  return dp[i][okl][okr] = res%mod;
}

int main()
{
  setIO();
  cin >> l >> r;
  string ss;
  FOR(i, 1, sz(r) - sz(l))
    ss.pb('0');
  l = ss + l;
  for (char &c : l)
    c -= '0';
  for (char &c : r)
    c -= '0';
  n = r.size();
  memset(dp, -1, sizeof dp);
  cout << DP(0, 0, 0);
}
