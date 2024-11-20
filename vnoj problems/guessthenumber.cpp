#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define __builtin_popcount __builtin_popcountll
#define BIT(x, i) (((x) >> (i)) & 1)
#define SZ(x) ((int)(x).size())
#define MASK(x) (1 << (x))
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

void input() {

}

void prepare() {

}
void solve() {

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef _DEBUG
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif
    int l = 1, r = 1e6;
    while (l <= r) {
        int mid = (l + r) >> 1;
        cout << mid << '\n' << flush;
        string s;
        cin >> s;
        if (s == ">=") l = mid + 1;
        else r = mid - 1;
    }
    cout << "! " << r;
}
