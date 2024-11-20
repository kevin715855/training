#include <bits/stdc++.h>
#define TASK "VMREL6"


using namespace std;



const int maxn = 80;

int adj[maxn][maxn], num[maxn], n, a[maxn];



struct EDGE {
    int from, to, cost;
};
vector <EDGE> edges;
void add_edge(int u, int v, int cost) {
    adj[u].push_back(edges.size());
    edges.push_back({u, v, cost});
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen(TASK".inp", "r", stdin);
    //freopen(TASK".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int t;
            cin >> t;
            adj[i][j] = t;
            if (t == 0) {
                add_edge(i, j, 0);
                add_edge(j, i, 0);
            }
            if (abs(t) == 1)
                add_edge(t > 1 ? x : y, t > 1 ? y : x, 1);
            if (abs(t) == 2)
                add_edge(t > 1 ? x : y, t > 1 ? y : x, 0);
        }
    visit(1);
}
