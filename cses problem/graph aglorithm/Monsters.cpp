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


























const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};
const int maxn = 1003;

int m, n;
char s[maxn][maxn];
int f[maxn][maxn], dist[maxn][maxn], trace[maxn][maxn];
void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> s[i] + 1;
}
queue <ii> q, me;
bool in(int r, int c) {
    return r >= 1 && r <= m && c >= 1 && c <= n;
}
void tracing(int row, int col) {
    string ans;
    if (dist[row][col] == -1) return;
    while (s[row][col] != 'A') {
        ans.push_back("RDLU"[trace[row][col]]);
        int nr = row - dr[trace[row][col]];
        int nc = col - dc[trace[row][col]];
        row = nr, col = nc;
    }
    cout << "YES\n" << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    cout << ans;
    exit(0);
}
void solve() {
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == 'M') {
                q.push(mp(i, j));
                f[i][j] = 0;
            }
            if (s[i][j] == 'A')
                me.push(mp(i, j));
        }
    while (!q.empty()) {
        int r = q.front().fi;
        int c = q.front().se;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!in(nr, nc) || s[nr][nc] == '#') continue;
            if (minimize(f[nr][nc], f[r][c] + 1))
                q.push(mp(nr, nc));
        }
    }
    memset(dist, -1, sizeof dist);
    dist[me.front().fi][me.front().se] = 0;
    while (!me.empty()) {
        int r = me.front().fi;
        int c = me.front().se;
        me.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!in(nr, nc) || s[nr][nc] == '#' || dist[r][c] + 1 >= f[nr][nc]) continue;
            if (dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                trace[nr][nc] = i;
                me.push(mp(nr, nc));
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (s[i][1] != '#') tracing(i, 1);
        if (s[i][n] != '#') tracing(i, n);
    }
    for (int i = 1; i <= n; i++) {
        if (s[1][i] != '#') tracing(1, i);
        if (s[m][i] != '#') tracing(m, i);
    }
    cout << "NO";
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
