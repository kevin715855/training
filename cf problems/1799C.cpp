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


int dd[200];

void runcase() {
  string s;
  cin >> s;
  FOR(i, 'a','z') dd[i] = 0;
  for (int i = 0; i < sz(s); i++)
    dd[s[i]]++;
  string suff, pref;
  for (int i = 'a'; i <= 'z'; i++) {
    REP(kk, dd[i]/2) {
      pref.pb(i);
      suff.pb(i);
    }
    dd[i] &= 1;
    if (dd[i]) {
      bool e = false;
      for (int j = i + 1; j <= 'z'; j++) if (dd[j] > 0 && dd[j] + 1 + sz(pref) + sz(suff) == sz(s)) {
        REP(time, (dd[j] + 1)/2) pref.pb(j);
        pref.pb(i);
        REP(time, dd[j]/2) pref.pb(j);
        dd[i] = 0; dd[j] = 0;
        e = true;
        break;
      }
      if (!e) {
        for (int j = i + 1; j <= 'z'; j++)
          while (dd[j]-- > 0) pref.push_back(j);
        suff.push_back(i);
        break;
      }
        else break;
    }
  }
  reverse(all(suff));
  cout << pref; cout << suff << '\n';
}

int main()
{
  setIO("");
  cin >> numt;
  while (numt--) runcase();
}
