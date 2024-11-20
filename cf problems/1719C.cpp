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


const int N = 1e5+3;
vector <int> p[N];
int n;
int a[N], ans[N], res[N];
ii qr[N];
void runcase() {
  int n, q;
  cin >> n >> q;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) {
    p[i].clear();
    ans[i] = 0;
  }
  FOR(i, 1, q) {
    int x, y;
    cin >> x >> y;
    qr[i] = mp(x, y);
    if (y <= n - 1)
      p[y].pb(i);
    else
      p[n - 1].pb(i);
  }
  int Win = 1;
  FOR(i, 2, n) {
    if (a[Win] < a[i]) Win = i;
    ans[Win]++;
    for (auto id : p[i - 1]) {
        auto [x, y] = qr[id];
        res[id] = ans[x] + (Win == x ? y - min(n - 1, y) : 0);
    }
  }
  FOR(i, 1, q) cout << res[i] << '\n';
}

int main()
{
  setIO("");
  cin >> numt;
  while (numt--) runcase();
}

