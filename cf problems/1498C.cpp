#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define __builtin_popcount __builtin_popcountll
#define BIT(x,i) (((x)>>(i))&1)
#define sz(x) ((int)(x).size())
#define MASK(x) (1<<(x))
#define ll long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define all(c) ((c).begin()), ((c).end())
#define LOCAL_DEBUG
using namespace std;
const int inf=1e9;
const ll INF=1e18;
int numt;
typedef pair <int, int> ii;
typedef vector <int> vi;
template <class T> bool minimize(T &x,T y){if(x>y){x=y;return true;}return false;}
template <class T> bool maximize(T &x,T y){if(x<y){x=y;return true;}return false;}
void setIO(string name = ""){
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".inp").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

const int mod = 1e9+7;
void add(int &x, int y) {x += y; if (x >= mod) x -= mod;}
const int N = 1003;
int dp[N][N], n, k;

void runcase() {

  int n, k; cin >> n >> k;
    FOR(i, 0, n + 1) dp[i][0] = 1;
    FOR(i, 1, k) {
        dp[0][i] = 1;
        FOR(j, 1, n+1) {
            dp[j][i] = dp[n-j][i-1];
            if (j > 0) add(dp[j][i], dp[j-1][i]);
        }
    }
    cout << dp[n][k-1] << '\n';
}

int main()
{
  setIO("");
  cin >> numt;
  while (numt--) runcase();
}
