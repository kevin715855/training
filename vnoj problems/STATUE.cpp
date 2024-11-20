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
int numt;
typedef pair <int,int>ii;
typedef vector <int>vi;
template <class T> bool minimize(T &x,T y){if(x>y){x=y;return true;}return false;}
template <class T> bool maximize(T &x,T y){if(x<y){x=y;return true;}return false;}
template <class T> void add (T &x,T y) {x+=y;if(x >= mod)x-=mod;}




const int maxn=1e6+3;
int n;
int t[maxn];
int col[maxn], dd[maxn];
vi adj[maxn];
#define _DEBUG1
#define TASK ""


void addEdge(int u, int v) {
    adj[u].pb(v);
    adj[v].pb(u);
}
inline int row1(int u) {return u;}
inline int row2(int u) {return u+n;}
void DFS(int u,int mau) {
    col[u]=mau;
    for (int v : adj[u]) {
        if (col[v] != -1)
            continue;
        DFS(v, 1 - mau);
    }
}
vector<int> swap_statues(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> c(n, 0);
    if (n <= 16) {
        ll ans=INF;
        REP(mask, MASK(n)) {
            REP(i,n)
                if(BIT(mask,i)) swap(a[i],b[i]);
            ll s=0;
            REP(i,n)
                REP(j,n)
                   s+=abs(a[i]-b[j]);
            if (minimize(ans,s))
                REP(i,n)
                    c[i]=BIT(mask, i);
            REP(i,n)
                if(BIT(mask,i)) swap(a[i],b[i]);
        }
        return c;
    }
    map <ii, int> Map;
    REP(i,n){
        Map[mp(a[i],i)]=1;
        Map[mp(b[i],i+n)]=1;
    }
    int cnt=0;
    for(auto it=Map.begin(); it!=Map.end(); it++)
        it->se=cnt++;
    REP(i,n) {
        dd[Map[mp(a[i],i)]] = i;
        dd[Map[mp(b[i],i+n)]] = i+n;
    }

    /// đồ thị mới có 2n đỉnh && 2 giá trị nhỏ liên tiếp phải khác màu nhau

    for(int i=0; i<2*n-1; i+=2) {
        addEdge(dd[i], dd[i+1]);
    }
    REP(i,n)
        addEdge(i, i + n);
    memset(col,-1,sizeof col);
    for(int i=0; i < 2*n-1; i++)
        if (col[i]==-1)
            DFS(i,0);
    for(int i=0;i<n;i++)
        c[i]=col[i];
    return c;
}
//int main() {
//    vi a, b;
//    int n;
//    cin >> n;
//    REP(i,n) {
//        int x;
//        cin>>x;
//        a.pb(x);
//    }
//    REP(i,n) {
//        int x;
//        cin>>x;
//        b.pb(x);
//    }
//    swap_statues(a, b);
//}
