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

int n;
int a[maxn];
vi val[maxn];
#define _DEBUG
#define TASK ""
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","w",stdin);
    //freopen(TASK".out","w",stdout);
    #ifdef _DEBUG
    cin>>numt;
    while (numt--){
        cin >> n;
        FOR(i, 1, n) {
            cin >> a[i];
            val[a[i]].emplace_back(i);
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        int an = 0;
        set <int> ST;
        FORD(i, n - 1, 1)
            if (a[i] > a[i + 1])
                ST.insert(i);
        while (ST.size()) {
            int u = a[*ST.begin()];
            ST.erase(ST.begin());
            if (u == 0)
                continue;
            an++;

            for (auto &v : val[u])
                a[v]=0;
            while(val[u].size()) {
                int idx = val[u].back();
                val[u].pop_back();
                if (idx > 1 && a[idx - 1] > a[idx])
                    ST.insert(idx - 1);
            }
        }
        FOR(i, 1, n)
            val[i].clear();
        cout << an << '\n';
    }
    #endif
}
