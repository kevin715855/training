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


void minimize(int &x, int y) {
  x = min(x, y);
}
void add(int &x, int y) {x = min(inf, x + y);}
const int N = 105;
int M[N], b[N][N];
int f[N][N];

int main()
{
  setIO("baric");
  int n, E;
  cin >> n >> E;

  for (int i = 1; i <= n; i++) cin >> M[i];

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      for (int k = i + 1; k < j; k++)
        add(b[i][j], abs(2*M[k] - (M[i] + M[j])) );
    }
  memset(f, 0x3f, sizeof f);
  for (int i = 1; i <= n; i++) {
    int dt = 0;
    for (int k = 1; k < i; k++)
        add(dt, 2*abs(M[k] - M[i]));
    f[1][i] = dt;
  }

  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++)
      if (f[i][j] <= E)
        for (int k = j + 1; k <= n; k++) {
          int det = f[i][j] + b[j][k];
          minimize(f[i + 1][k], det);
        }

  int best = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) if (f[i][j] <= E) {
      int dt = f[i][j];
      for (int k = j + 1; k <= n; k++)
        add(dt, 2*abs(M[j] - M[k]));
      minimize(best, dt);
    }
    if (best <= E) {
      cout << i << ' ' << best;
      return 0 ;
    }
  }
}

