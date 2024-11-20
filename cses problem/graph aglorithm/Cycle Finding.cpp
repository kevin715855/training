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
#define _DEBUG
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


struct Edge {int u, v; ll c;};

int n, m;
vector <Edge> edges;
ll dist[maxn], par[maxn];
void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; ll c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
}

void prepare() {

}
void Bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int trace = 0;
    ///

    for (int i = 0; i <= n; i++) {
        trace = 0;
        for (auto [u, v, c] : edges)
            if (minimize(dist[v], dist[u] + c)) {
                trace = v;
                par[v] = u;
            }
    }
    if (trace == 0) {
        cout << "NO";
        return;
    }
    else {
        cout << "YES\n";
        vi cycle;
        for (int i = 0; i <= n; i++)
            trace = par[trace];
        for (int x = trace;; x = par[x]) {
            cycle.push_back(x);
            if (x == trace && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
        for (int u : cycle) cout << u << ' ';
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef _DEBUG1
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif
    input();
    Bellman_ford();
}
