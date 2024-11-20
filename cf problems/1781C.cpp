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



void runcase() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<vector<int>> at(26);
  for (int i = 0; i < n; i++) {
    at[(int) (s[i] - 'a')].push_back(i);
  }
  vector<int> order(26);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return at[i].size() > at[j].size();
  });
  string res = "";
  int best = -1;
  for (int cnt = 1; cnt <= 26; cnt++) {
    if (n % cnt == 0) {
      int cur = 0;
      for (int i = 0; i < cnt; i++) {
        cur += min(n / cnt, (int) at[order[i]].size());
      }
      if (cur > best) {
        best = cur;
        res = string(n, ' ');
        vector<char> extra;
        for (int it = 0; it < cnt; it++) {
          int i = order[it];
          for (int j = 0; j < n / cnt; j++) {
            if (j < (int) at[i].size()) {
              res[at[i][j]] = (char) ('a' + i);
            } else {
              extra.push_back((char) ('a' + i));
            }
          }
        }
        for (char& c : res) {
          if (c == ' ') {
            c = extra.back();
            extra.pop_back();
          }
        }
      }
    }
  }
  cout << n - best << '\n';
  cout << res << '\n';
}
int main()
{
  setIO("");
  cin >> numt;
  while (numt--) runcase();
}

