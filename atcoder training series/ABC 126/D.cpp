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

///2023-01-04-14.18

const int N = 1e5+3;



struct EDGE {
  int u, v, c;
  int other(int x)  {
    return u ^ v ^ x;
  }
};
vector <EDGE> edges;
vi adj[N];
int n;
bool c[N];

void dfs(int u, int fu, bool col) {
  c[u] = col;
  for (int id : adj[u]) {
    int v = edges[id].other(u);
    if (v == fu) continue;
    if (edges[id].c & 1)
      dfs(v, u, col^1);
    else
      dfs(v, u, col);
  }

}

int main()
{
  setIO("");
  cin >> n;
  REP(i, n - 1) {
    int u, v, c; cin >> u >> v >> c;
    edges.pb({u, v, c});
    adj[u].pb(i);
    adj[v].pb(i);
  }

  dfs(1, -1, 0);
  FOR(i, 1, n) cout << c[i] << '\n';
}

