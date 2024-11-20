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
using namespace std;
const int inf=1e9;
const ll INF=1e18;
int numt;
typedef pair <int, int> ii;
typedef vector <int> vi;
template <class T> bool minimize(T &x,T y){if(x>y){x=y;return true;}return false;}
template <class T> bool maximize(T &x,T y){if(x<y){x=y;return true;}return false;}
void setIO(string name = ""){
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".inp").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int N = 1e5+3;
int n, a[N], f[N], cnt[N];

struct DS{
  multiset <int> st;
  void init() {
    FOR(i, 1, n) if (a[i] <= n) {
      f[i] = (a[i] + n - i) % n;
      cnt[f[i]]++;
    }
    FOR(i, 0, n - 1)
      st.insert(i + n - cnt[i]);
  }
  void update(int pos, int val) {
    if (a[pos] <= n) {
      st.erase(st.find(f[pos] + n - cnt[f[pos]]));
      --cnt[f[pos]];
      st.insert(f[pos] + n - cnt[f[pos]]);
    }

    a[pos] = val;

    if (a[pos] <= n) {
      f[pos] = (a[pos] + n - pos) % n;
      st.erase(st.find(f[pos] + n - cnt[f[pos]]));
      ++cnt[f[pos]];
      st.insert(f[pos] + n - cnt[f[pos]]);
    }
  }
  int getMin() {
    return *st.begin();
  }
};



int main()
{
  setIO("");
  cin >> n;
  DS minTree;
  FOR(i, 1, n)
    cin >> a[i];
  minTree.init();
  int q;
  cin >> q;
  FOR(i, 1, q) {
    int j, x;
    cin >> j >> x;
    minTree.update(j, x);
    cout << minTree.getMin() << '\n';
  }
}
