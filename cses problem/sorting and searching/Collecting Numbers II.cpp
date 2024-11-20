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

int n, q;
int a[maxn], dd[maxn];

void input() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void prepare() {

}
void solve()
{
    dd[0] = 0, dd[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)
        dd[a[i]] = i;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
        if (dd[i + 1] < dd[i]) cnt++;

    for (int i = 1; i <= q; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        int x = a[p1], y = a[p2];
        swap(a[p1], a[p2]);
        if (dd[x - 1] > dd[x] && dd[x - 1] <= dd[y]) cnt--;
        if (dd[x - 1] <= dd[x] && dd[x - 1] > dd[y]) cnt++;
        if (dd[x + 1] > dd[x] && dd[x + 1] <= dd[y]) cnt++;
        if (dd[x + 1] <= dd[x] && dd[x + 1] > dd[y]) cnt--;


        cerr << "   " << cnt << endl;
        if (dd[y - 1] > dd[y] && dd[y - 1] <= dd[x]) cnt--;
        if (dd[y - 1] <= dd[y] && dd[y - 1] > dd[x]) cnt++;
        if (dd[y + 1] > dd[y] && dd[y + 1] <= dd[x]) cnt++;
        if (dd[y + 1] <= dd[y] && dd[y + 1] > dd[x]) cnt--;
        dd[x] = p2;
        dd[y] = p1;
        cout << cnt << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef _DEBUG123
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif
    input();
    solve();
}
