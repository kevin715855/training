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
const int inf=1e9;
const ll INF=1e18;
int numt;
typedef pair <int, int> ii;
typedef vector <int> vi;
template <class T> bool minimize(T &x,T y){if(x>y){x=y;return true;}return false;}
template <class T> bool maximize(T &x,T y){if(x<y){x=y;return true;}return false;}
void setIO(string name = ""){
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".inp").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int N = 3e5+3, LG = 19;
int n, k;
vi adj[N];

struct QUERY {
  int x, y, dist;
};
struct ST {
  ii t[4*N];
  int lazy[4*N];
  ii combine(ii lc, ii rc) {
    return mp(min(lc.fi, rc.fi), max(lc.se, rc.se));
  }
  void build(int id, int l, int r) {
    id[lazy] = -1;
    if (l == r) {
      t[id] = mp(0, 0);
      return;
    }
    int m = (l + r) >> 1;
    build(id*2, l, m);
    build(id*2 + 1, m + 1, r);
    t[id] = combine(t[id*2], t[id*2 + 1]);
  }
  void push(int id) {
    if (lazy[id] == -1) return;
    FOR(i, 2*id, 2*id + 1) {
      lazy[i] = lazy[id];
      t[i] = mp(lazy[id], lazy[id]);
    }
    lazy[id] = -1;
  }
  void update(int id, int l, int r, int u, int v, int val) {
    if (l > r || r < u || l > v) return;
    if (u <= l && r <= v) {
      t[id] = mp(val, val);
      lazy[id] = val;
      return;
    }

    int m = (l + r) >> 1;
    push(id);
    update(id*2, l, m, u, v, val);
    update(id*2 + 1, m + 1, r, u, v, val);
    t[id] = combine(t[id*2], t[id*2 + 1]);
  }
  ii query(int id, int l, int r, int u, int v) {
    if (l > r || r < u || l > v) return mp(inf, -inf);
    if (u <= l && r <= v) return t[id];
    int m = (l + r) >> 1;
    push(id);
    return combine(query(id*2, l, m, u, v),
               query(id*2 + 1, m + 1, r, u, v));
  }
};

ST t;
int head[N], st[N], en[N], cntHld;
int dep[N], s[N], par[N][LG+1];

struct HLD {
  void build() {
    cntHld = 0;
    dfs1(1);
    head[1] = 1;
    dfs2(1);
    t.build(1, 1, n);
  }
  void dfs1(int u, int fu = 0) {
    dep[u] = dep[fu] + 1;
    par[u][0] = fu;
    s[u] = 1;
    FOR(i, 1, LG)
      par[u][i] = par[par[u][i - 1]][i - 1];
    if (fu) adj[u].erase(find(all(adj[u]), fu));

    for (int &v : adj[u]) {
      dfs1(v, u);
      s[u] += s[v];
      if (s[v] > s[adj[u][0]]) swap(v, adj[u][0]);
    }
  }
  void dfs2(int u) {
    st[u] = ++cntHld;
    for (int v : adj[u]) {
      head[v] = (v == adj[u][0] ? head[u] : v);
      dfs2(v);
    }
    en[u] = cntHld;
  }
  int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);

    FORD(i, LG, 0)
      if (dep[par[u][i]] >= dep[v])
        u = par[u][i];
    if (u == v) return u;

    FORD(i, LG, 0)
      if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
      }
    return par[u][0];
  }
  int kth(int u, int k) {
    FOR(i, 0, LG)
      if (BIT(k, i))
        u = par[u][i];
    return u;
  }
  ii queryUp(int u, int v) {
    ii ans = mp(inf, -inf);
    while (head[u] != head[v]) {
      ans = t.combine(ans, t.query(1, 1, n, st[head[u]], st[u]));
      u = par[head[u]][0];
    }
    ans = t.combine(ans, t.query(1, 1, n, st[v], st[u]));
    return ans;
  }
  ii queryPath(int u, int v) {
    int uv = lca(u, v);
    ii ans = queryUp(u, uv);
    if (v != uv) ans = t.combine(ans, queryUp(v, kth(v, dep[v] - dep[uv] - 1)));
    return ans;
  }
  void updateUp(int u, int v, int val) {
    while (head[u] != head[v]) {
      t.update(1, 1, n, st[head[u]], st[u], val);
      u = par[head[u]][0];
    }
    t.update(1, 1, n, st[v], st[u], val);
  }
  void updatePath(int u, int v, int val) {
    int uv = lca(u, v);
    updateUp(u, uv, val);
    if (v != uv) updateUp(v, kth(v, dep[v] - dep[uv] - 1), val);
  }
};

HLD hld;
int pathLen(int x, int y) {
  return dep[x] + dep[y] - 2*dep[hld.lca(x, y)];
}

bool inline cmp(const QUERY &x, const QUERY &y) {
  return x.dist > y.dist;
}

int main()
{
  setIO("");
  cin >> n;
  cin >> n;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  hld.build();
  cin >> numt;
  while (numt--) {
    vector <QUERY> qr;

    cin >> k;
    REP(i, k) {
      int x, y; cin >> x >> y;
      qr.pb({x, y, pathLen(x, y)});
    }

    sort(all(qr), cmp);
    int i = 0;
    bool ok = true;
    for(auto q : qr) {
      ii an = hld.queryPath(q.x, q.y);
      if (an.fi != an.se) {
        ok = false;
        break;
      }
      hld.updatePath(q.x, q.y, ++i);
    }
    t.lazy[1] = 0;
    cout << (ok ? "RO RANG\n" : "MAP MO\n");

  }
}
