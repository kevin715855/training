// Goten2308
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair <int, int>;
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define BIT(x, y) ((x >> y) & 1)
#define MASK(x) (1 << x)
#define MOD 1000000007
#define MULTI_TEST
template <class T> bool maximize(T& a, T b) { if(a < b) { a = b; return true; } return false; }
template <class T> bool minimize(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template <class T> void add(T& a, T b) { a += b; if(a >= MOD) a -= MOD; }
template <class T> void sub(T& a, T b) { a -= b; if(a <= 0) a += MOD; }

const int MAX = 50;
ll x, y, d;
ll dp[MAX + 5][2][2][2];
vector <int> xb, yb, db;

vector <int> ternaryConv(ll x) {
    vector <int> ans;
    for (int i = 0; i < MAX; i++) {
        ans.push_back(x%3);
        x/=3;
    }
    reverse(all(ans));
    return ans;
}


bool oddEven(int xyz) {
    return (xyz%3) & 1;
}
ll DP(int i, int mx, int my, int okr) {
    if (i == db.size()) {
        return (!mx && !my);
    }
    if (dp[i][mx][my][okr] != -1) return dp[i][mx][my][okr];
    ll res = 0;
    int lim = okr ? 2 : db[i];
    for (int nx = 0; nx <= lim; nx++)
        for (int nmx = 0; nmx < 2; nmx++)
            for (int nmy = 0; nmy < 2; nmy++) {
                if ((!mx || nx + xb[i] + nmx >= 3) && (!my || nx + yb[i] + nmy >= 3) && (mx || nx + xb[i] + nmx < 3) && (my || nx + yb[i] + nmy < 3))
                    if (oddEven(nx + xb[i] + nmx) == oddEven(nx + yb[i] + nmy))
                        res += DP(i + 1, nmx, nmy, (okr || nx < db[i]));
            }
    return dp[i][mx][my][okr] = res;
}

ll solve(ll x, ll y, ll d) {
    xb = ternaryConv(x);
    yb = ternaryConv(y);
    db = ternaryConv(d);
    memset(dp, -1, sizeof dp);
    return DP(0, 0, 0, 0);
}

signed main(){
    #define task ""
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    if(fopen("task.inp", "r")){
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    cin.tie(0)->ios_base::sync_with_stdio(0);
    int nTest = 1;
    #ifdef MULTI_TEST
    cin >> nTest;
    #endif
    while(nTest--) {
        cin >> d >> x >> y;
        cout << solve(x, y, d) << '\n';
    }
    return 0;
}
