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


const int N = 2e5+4;

struct Project {
  int starting, ending;
  long long p;
  bool inline operator < (const Project & other) const {
    return ending < other.ending;
  }
  void read() {
    cin >> starting >> ending >> p;
  }
} project[N];

long long f[N];
int a[N];

int main()
{
  setIO("");

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) project[i].read();
  sort(project + 1, project + n + 1);
  for (int i = 1; i <= n; i++) a[i] = project[i].ending;
  f[0] = 0;
  f[1] = project[1].p;
  for (int i = 2; i <= n; i++) {
    int k = lower_bound(a + 1, a + i, project[i].starting) - a - 1;
    f[i] = max(f[i - 1], project[i].p + f[k]);
  }
  cout << f[n];
}

