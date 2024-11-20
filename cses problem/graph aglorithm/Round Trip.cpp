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
///0bietdau


























const int maxn = 1e6 + 3;


int n, m, cnt;
vi adj[maxn];
int num[maxn], par[maxn];
void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void DFS(int u) {
    num[u] = ++cnt;
    for (int v : adj[u])
        if (v != par[u])
            if (num[v] == 0) {
                par[v] = u;
                DFS(v);
            }
            else
            {
                stack <int> ans;
                while (v != u) {
                    ans.push(u);
                    //cout << u << ' ';
                    u = par[u];
                }
                cout << ans.size() + 2 << '\n' << v << ' ';
                while (ans.size()) {
                    cout << ans.top() << ' ';
                    ans.pop();
                }
                cout << v << ' ';
                exit(0);
            }

}
void solve() {
    for (int i = 1; i <= n; i++)
        if (num[i] == 0) DFS(i);
    cout << "IMPOSSIBLE";
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
