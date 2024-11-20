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

const int maxn = 1004;
int m, n, numcomp;
char s[maxn][maxn];
bool visited[maxn][maxn];
void input() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> s[i] + 1;
}
bool in(int r, int c) {
    return r >= 1 && r <= m && c >= 1 && c <= n;
}
void DFS(int row, int col) {
    visited[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = row + dx[i], nc = col + dy[i];
        if (!in(nr, nc) || s[nr][nc] == '#' || visited[nr][nc]) continue;
        DFS(nr, nc);
    }
}
void solve() {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s[i][j] == '.' && !visited[i][j]) {
                numcomp++;
                DFS(i, j);
            }
    cout << numcomp;
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
