#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;


void setIO(string name = ""){
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".inp").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}



int main()
{
  setIO("");
  cin >> m >> n;
  REP(i, m)
    REP(j, n) {
      int x; cin >> x;
      id[i][j] = a.size();
      a.push_back(x);
      hmax = max(hmax, x);
    }

}
