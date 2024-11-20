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


int n, m, q;
ll adj[501][501];
void input() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v; ll c;
        cin >> u >> v >> c;
        minimize(adj[u][v], c);
        minimize(adj[v][u], c);
    }
}

void prepare() {
    memset(adj, 0x3f, sizeof adj);
    for (int i = 1; i <= 500; i++)
        adj[i][i] = 0;
}
void prin() {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (adj[i][j] > INF ? -1 : adj[i][j])<< ' ';
        cout << endl;
    }
}
void solve() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                minimize(adj[i][j], adj[i][k] + adj[k][j]);
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (adj[u][v] > INF ? -1 : adj[u][v])<< '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef _DEBUG
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif
    prepare();
    input();
    solve();
}
