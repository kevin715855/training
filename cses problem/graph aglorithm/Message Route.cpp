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
vi adj[maxn];
int trace[maxn], dist[maxn];
bool visited[maxn];
vector <int> ans;
void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void solve() {
    memset(dist, -1, sizeof dist);
    queue <int> q;
    q.push(1);
    visited[1] = 1;
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
                dist[v] = dist[u] + 1;
                trace[v] = u;
            }
    }
    if (dist[n] == -1)
        cout << "IMPOSSIBLE";
    else {
        while (n != 1)
        {
            ans.push_back(n);
            n = trace[n];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() + 1 << "\n1 ";
        for (int v : ans) cout << v << ' ';
    }
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
