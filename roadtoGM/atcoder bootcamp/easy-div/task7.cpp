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


struct type {
  int x, ai, aj;
};
vector <type> a;
const int N = 50;
int n;
int row[N], col[N], dia1[N], dia2[N];
int main()
{
  setIO("");
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      int x; cin >> x;
      a.push_back({x, i, j});
    }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    for (auto [ax, ai, aj] : a)
      if (x == ax) {
        row[ai]++;
        col[aj]++;
        dia1[ai + aj]++;
        dia2[ai - aj + 6]++;
      }
  }
  for (int i = 1; i < N; i++)
    if (row[i] == 3 || col[i] == 3 || dia1[i] == 3 || dia2[i] == 3) return cout << "Yes", 0;

  cout << "No";
}


