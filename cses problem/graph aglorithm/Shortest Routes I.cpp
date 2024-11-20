#include <bits/stdc++.h>
#define __builtin_popcount __builtin_popcountll
#define BIT(x, i) (((x) >> (i)) & 1)
#define SZ(x) ((int)(x).size())
#define MASK(x) (1LL << (x))
#define ll long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define _DEBUG1
#define TASK ""
using namespace std;
const int mod = 1e9 + 7;
template <class T> bool minimize(T &x, T y) {if (x > y) {x=y; return true;} return false;}
template <class T> bool maximize(T &x, T y) {if (x < y) {x=y; return true;} return false;}
void addll (long long &x, long long y) {x+=y; if (x >= mod) x -= mod;}
void add (int &x, int y) {x+=y; if (x >= mod) x -= mod;}
typedef pair <int, int> ii;
typedef vector <int> vi;
const int inf = 1e9;
const ll INF = 1e18;



























const int maxn = 1e6 + 3;


struct Edge {
    int u, v;
    ll c;
} edges[maxn];

int n, m;
vi adj[maxn];
ll ans[maxn];
void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; ll c;
        cin >> u >> v >> c;
        edges[i] = {u, v, c};
        adj[u].push_back(i);
    }
}
typedef pair <ll, int> pn;
void dijkstra(int s, int n, ll dist[]) {
    priority_queue <pn, vector <pn>, greater <pn>> pq;
    memset(dist, 0x3f, sizeof(ll) * (n + 1));
    dist[s] = 0;
    pq.push(mp(0, s));
    while (!pq.empty()) {
        int u = pq.top().se;
        ll du = pq.top().fi;
        pq.pop();
        if (dist[u] != du) continue;
        for (int id : adj[u]) {
            int v = edges[id].u ^ edges[id].v ^ u;
            ll uv = edges[id].c;
            if (minimize(dist[v], du + uv))
                pq.push(mp(du + uv, v));
        }
    }
}
void solve() {
    dijkstra(1, n, ans);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef _DEBUG1
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif
    input();
    solve();
}
