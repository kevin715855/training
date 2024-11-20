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
struct EDGE {
  int u, v;
  ll c;
  int other(int x)  {
    return u ^ v ^ x;
  }
  bool inline operator < (const EDGE &o) const {
    return c < o.c;
  }
};

int n, k;
const int N = 1e5+2;
EDGE edges[N];
vector <int> adj[N];
ll fin[N], fout[N];
bool coffe[N];

void findfin(int u, int fu) {
  fin[u] = INF;
  for (int id : adj[u]) {
    int v = edges[id].other(u);
    if (v == fu) continue;
    findfin(v, u);
    if (coffe[v]) minimize(fin[u], edges[id].c);
    minimize(fin[u], fin[v] + edges[id].c);
  }
}

void findfout(int u, int fu) {
  ll first = INF, second = INF;
  for (int id : adj[u]) {
    int v = edges[id].other(u);
    if (v == fu) continue;
    ll val = coffe[v] ? edges[id].c : fin[v] + edges[id].c;
    if (first >= val) {
      second = first;
      first = val;
    }
    else minimize(second, val);
  }
  for (int id : adj[u]) {
    int v = edges[id].other(u);
    if (v == fu) continue;
    fout[v] = coffe[u] ? edges[id].c : fout[u] + edges[id].c;
    ll val = coffe[v] ? edges[id].c : fin[v] + edges[id].c;
    minimize(fout[v], edges[id].c + (first == val ? second : first));
    findfout(v, u);
  }
}
int main()
{
  setIO("");
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(i);
    adj[v].push_back(i);
    edges[i] = {u, v, w};
  }

  for (int i = 1; i <= k; i++) {
    int x; cin >> x;
    coffe[x] = true;
  }
  findfin(1, -1);
  memset(fout, 0x3f, sizeof fout);
  findfout(1, -1);
  for (int i = 1; i <= n; i++)
    cout << min(fin[i], fout[i]) << ' ';
}

