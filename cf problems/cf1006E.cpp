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

const int N = 2e5+3;
int n, m, sta[N], fin[N], par[N], cntEuler, vt[N];
vi child[N];


void dfs(int u) {
  sta[u] = ++cntEuler;
  vt[cntEuler] = u;
  for (int v : child[u])
    dfs(v);
  fin[u] = cntEuler;
}

int main()
{
  setIO("");
  cin >> n >> m;
  FOR(i, 2, n) {
    cin >> par[i];
    child[par[i]].pb(i);
  }
  dfs(1);
  FOR(i, 1, m) {
    int x, y; cin >> x >> y;
    cout << (sta[x] + y - 1 <= fin[x] ? vt[sta[x] + y - 1] : -1) << '\n';
  }
}

