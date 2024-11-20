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


const int N = 2e4+3;
string sgn = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int id[105][105];
int nxt[N];
void runcase() {
  int r, c, k, numPot = 0;
  vector <char> a;
  cin >> r >> c >> k;
  REP(i, r) {
    REP(j, c) {
      cin >> s;
      if (x == 'R') numPot++;
      id[i][j] = sz(a);
      a.pb(x);
    }
  }


  int pos = 0, t = 0;
  REP(i, numPot%k) {
    int d = 0;
    while (d < numPot/k + 1) {
      if (a[pos] == 'R') d++;
      a[pos] = sgn[t];
      pos = nxt[pos];
    }
    t++;
  }
  REP(i, k - numPot%k) {
    int d = 0;
    while (d < numPot/k) {
      if (a[pos] == 'R') d++;
      a[pos] = sgn[t];
      pos = nxt[pos];
    }
    t++;
  }
  t--;
  while (pos != -1) {
    a[pos] = sgn[t];
    pos = nxt[pos];
  }
  REP(i, r)
    {REP(j, c) cout << a[id[i][j]]; cout << '\n';}
}

int main()
{
  setIO("");
  cin >> numt;
  while (numt--) runcase();
}

