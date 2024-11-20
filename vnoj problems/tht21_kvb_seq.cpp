#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define __builtin_popcount __builtin_popcountll
#define BIT(x,i) (((x)>>(i))&1)
#define SZ(x) ((int)(x).size())
#define MASK(x) (1<<(x))
#define ll long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define all(c) ((c).begin()), ((c).end())
using namespace std;
const int mod=1e9+7;
const int inf=1e9;
const ll INF=1e18;
const int maxn=101, maxv = 1e3 + 1;
int numt;
typedef pair <int,int>ii;
typedef vector <int>vi;
template <class T> bool minimize(T &x,T y){if(x>y){x=y;return true;}return false;}
template <class T> bool maximize(T &x,T y){if(x<y){x=y;return true;}return false;}
template <class T> void add (T &x,T y) {x+=y;if(x >= mod)x-=mod;}


int n, s;
int a[maxn];
ll f[maxn][2*maxn*maxv];
int p(int x) {return x + 1e5;}


#define _DEBUG
#define TASK "tht21_kvb_seq"
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    #ifdef _DEBUG
    while (cin >> n){
        s = 0;
        FOR(i, 1, n) {
                cin >> a[i];
                s += a[i];
            }
        if (n <= 24) {
            memset(eq, 0, sizeof eq);
            REP(mask, MASK(n)) {
                ll s1 = 0, s2 = 0;
                REP(i, n)
                    if (BIT(mask, i))
                        s1 += a[i + 1];
                    else
                        s2 += a[i + 1];
                if (s1 == s2)
                    eq[mask] = 1;
            }
            REP(mask, MASK(n))

        }
        else {
            FOR(i, 0, n)
                FOR(j, -s, s)
                    f[i][p(j)] = INF;
            f[0][p(0)] = s;
            REP(i, n)
                FOR(j, -s, s) {
                    minimize(f[i + 1][p(j + a[i + 1])], f[i][p(j)] - a[i + 1]);
                    minimize(f[i + 1][p(j - a[i + 1])], f[i][p(j)] - a[i + 1]);
                    minimize(f[i + 1][p(j)], f[i][p(j)]);
                }
            cout << f[n][p(0)] << '\n';
        }
    }
    #endif

}
