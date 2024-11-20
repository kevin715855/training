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

int n, m;
ll dist[maxn][3];
vi adj[maxn];
struct Edge {int u, v; ll c;};
struct pn {
    ll du;
    int used;
    int u;
    bool inline operator > (const pn & o) const {
        return du > o.du;
    }
};
vector <Edge> edges;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; ll c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
        adj[u].push_back(i);
        //adj[v].push_back(i);
    }
}


void solve() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue <pn, vector <pn>, greater <pn>> pq;
    pq.push({0, 0, 1});
    dist[1][0] = 0;
    while (!pq.empty()) {
        ll du = pq.top().du;
        int used = pq.top().used;
        int u = pq.top().u;
        pq.pop();
        if (dist[u][used] != du)
            continue;
        for (int id : adj[u]) {
            int v = edges[id].u ^ edges[id].v ^ u;
            ll uv = edges[id].c;
            if (minimize(dist[v][used], du + uv))
                pq.push({du + uv, used, v});
            if (used == 0)
                if (minimize(dist[v][1], du + uv/2))
                    pq.push({du + uv/2, 1, v});
        }
    }
    cout << min(dist[n][1], dist[n][0]);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef _DEBUG
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif
    input();
    solve();
}
