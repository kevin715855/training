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




#define _DEBUG1
#define TASK ""
int s,m;
string Min,Max;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //freopen(TASK".inp","w",stdin);
    //freopen(TASK".out","w",stdout);
    #ifdef _DEBUG
    cin>>numt;
    while (numt--){
    }
    #endif
    cin>>m>>s;
    if (m>1&&s==0 || 9*m < s) {
        cout << "-1 -1";
        return 0;
    }
    int s2=s;
    FOR(i,1,m){
    Max.pb(max(0,min(s,9)));
    Min.pb(max(0,min(s2-1,9)));
    s-=max(0,min(s,9));
    s2-=max(0,min(s2-1,9));
    }
    if (s2!=0)
        if (Min.back()==0)
            Min[SZ(Min)-1]=1;
        else
            Min.back()++;
    reverse(Min.begin(),Min.end());
    for(int i:Min)cout<<i;cout<<' ';
    for(int i:Max)cout<<i;
}
