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



























const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ch[] = {'R', 'D', 'L', 'U'};
const int maxn = 1004;
int m, n, numcomp;
char s[maxn][maxn];
bool visited[maxn][maxn];
int dist[maxn][maxn], trace[maxn][maxn];
string ans;
void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> s[i] + 1;
}

bool in(int r, int c) {
    return r >= 1 && r <= m && c >= 1 && c <= n;
}
void solve() {
    queue <ii> q;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s[i][j] == 'A') {
                q.push(mp(i, j));
                visited[i][j] = 1;
            }
    while (!q.empty()) {
        int r = q.front().fi;
        int c = q.front().se;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (!in(nr, nc) || visited[nr][nc] || s[nr][nc] == '#') continue;
            visited[nr][nc] = true;
            dist[nr][nc] = dist[r][c] + 1;
            trace[nr][nc] = i;
            q.push(mp(nr, nc));
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s[i][j] == 'B') {
                if (visited[i][j] == 0) {
                    cout << "NO";
                    return;
                }
                cout << "YES\n" << dist[i][j] << '\n';
                int r = i, c = j;
                for (int k = 1; k <= dist[i][j]; k++) {
                    ans.push_back(ch[trace[r][c]]);
                    int nr = r - dx[trace[r][c]];
                    int nc = c - dy[trace[r][c]];
                    r = nr, c = nc;
                }
                reverse(ans.begin(), ans.end());
                cout << ans;
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
