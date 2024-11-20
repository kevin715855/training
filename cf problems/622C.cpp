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

const int N = 2e5+3, BL = 450;
int n, m;
int a[N];
map <int, int> block[BL];

int getAns(int l, int r, int x) {
  for (int j = l; j/BL == l/BL && j <= r; j++)
      if (a[j] != x) {
        return j + 1;
      }
    for (int j = r; j/BL == r/BL && j >= l; j--)
      if (a[j] != x) {
        return j + 1;
      }
    for (int ib = l/BL + 1; ib < r/BL; ib++)
      if (block[ib][x] < BL) {
        for (int j = ib*BL; j < (ib + 1) * BL; j++)
          if (a[j] != x) {
            return j + 1;
          }
      }
    return -1;
}

int main()
{
  setIO("");
  cin >> n >> m;
  REP(i, n) {
    cin >> a[i];
    block[i/BL][a[i]]++;
  }
  FOR(i, 1, m) {
    int l, r, x;
    cin >> l >> r >> x;
    l--; r--;
    cout << getAns(l, r, x) << '\n';
  }
}

