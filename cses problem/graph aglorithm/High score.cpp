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




















struct Edge {int u, v; ll c;};
vector <Edge> edges;
int n, m;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; ll c;
        cin >> u >> v >> c;
        edges.push_back({u, v, -c});
    }
}

ll bellman_ford(int n, int start, int target,const vector <Edge> &edges) {
    int m = edges.size();
    vector <ll> f(n + 1, INF);
    f[start] = 0;
    for (int i = 0; i < m; i++)
        for (auto [u, v, c] : edges)
            if (f[u] != INF)
                minimize(f[v], f[u] + c);

    auto cur_f = f;
    for (int i = 0; i < m; i++)
        for (auto [u, v, c] : edges)
            if (f[u] != INF)
                minimize(f[v], f[u] + c);

    for (int i = 1; i <= n; i++)
        if (f[i] != cur_f[i])
            f[i] = -INF;

    for (int i = 0; i < m; i++)
        for (auto [u, v, c] : edges)
            if (f[u] != INF)
                minimize(f[v], f[u] + c);

    if (f[target] != cur_f[target]) return -1;
    return -f[target];
}
void solve() {
    cout << bellman_ford(n, 1, n, edges);
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
