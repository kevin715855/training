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


int n;
vector <ii> timeline;
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int arrive, leave;
        cin >> arrive >> leave;
        timeline.push_back(mp(arrive, -1));
        timeline.push_back(mp(leave, 1));
    }
}

void prepare() {

}
void solve() {
    sort(timeline.begin(), timeline.end());
    int num = 0, ans = 0;
    for (ii t : timeline) {
        num -= t.se;
        maximize(ans, num);
    }
    cout << ans;
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
