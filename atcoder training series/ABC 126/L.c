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

typedef priority_queue <int> pq;

pq St[maxn];
pq *dfs(int u, int fu) {
  pq *root;
  root = &St[u];
  for (int v : adj[u]) {
    if (v == fu) continue;

    pq *address = dfs(v, u);
    if (sz(*address) < sz(*root)) {
      for (auto it = (*address).begin(); it != (*address).end(); it++)
        (*root).insert(*it);

    }
    else {
      for (auto it = (*root).begin(); it != (*root).end(); it++)
        (*address).insert(*it);
      root = address;
    }
  }
  s[u] = sz(*root);
  return root;
}

int main()
{
  setIO("");
  cin >> n >> m;
  FOR(i, 1, n) {
    int cost;
    cin >> b[i] >> cost >> l[i];
    c[i].push(cost);
    t[i] = cost;
  }

  FORD(i, n, 2)  {

  }
}
