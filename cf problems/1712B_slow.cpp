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
const int maxn=1e6+3;
int numt;
typedef pair <int,int>ii;
typedef vector <int>vi;
template <class T> bool minimize(T &x,T y){if(x>y){x=y;return true;}return false;}
template <class T> bool maximize(T &x,T y){if(x<y){x=y;return true;}return false;}
template <class T> void add (T &x,T y) {x+=y;if(x >= mod)x-=mod;}


int n, an;
int a[maxn], f[maxn];
bool used[maxn];

void back_track(int i) {
    if (i == n) {
        int k = 0;
        FOR(j, 1, n)
            k += j * a[j] / __gcd(j, a[j]);
        if (maximize(an, k))
            FOR(j, 1, n)
                f[j] = a[j];
        return;
    }
    FOR(j, 1, n) {
        if (used[j])
            continue;
        used[j] = 1;
        a[i + 1] = j;
        back_track(i + 1);
        used[j] = 0;
    }
}

#define _DEBUG
#define TASK ""
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".ans","w",stdout);
    #ifdef _DEBUG
    cin>>numt;
    while (numt--){
        cin >> n;
        an = 0;
        back_track(0);
        FOR(i, 1, n)
            cout << f[i] << ' ';
        cout << endl;
    }
    #endif

}
