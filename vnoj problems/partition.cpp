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

const int maxn = 2e5 + 3;
int n, q;
ll a[maxn];
ll IT[4*maxn];
ll lazy[4*maxn];




int main()
{
  setIO("");
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  ///
  map <int, int> compress;
  for (int i = 1; i <= n; i++) {
    compress[l[i]];
    compress[r[i]];
  }
  int numKey = 0;
  for (auto it = compress.begin(); it != compress.end(); it++)
    it->se = ++numKey;
  for (int i = 1; i <= n; i++) {
    l[i] = compress[l[i]];
    r[i] = compress[r[i]];
  }
  ///

  int j = 1;
  for (int i = 1; i <= n; i++) {
  }


}

