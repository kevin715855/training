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
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)

#ifdef LOCAL_DEBUG
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) {
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
void setIO(string name = ""){
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name + ".inp").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int N = 1e5+3;
int n;
int t[N];


struct QUERY {
  int time, dt, l, r;

  bool inline operator < (const QUERY &o) const {
    return time < o.time;
  }
};
struct FT {

  void add(int pos, int val) {
    while (pos < N) {
      t[pos] += val;
      pos += pos&-pos;
    }
  }
  int getSum(int pos) {
    int T = 0;
    while (pos > 0) {
      T += t[pos];
      pos -= pos&-pos;
    }
    return T;
  }
  int sumRange(int l, int r) {
    if (l > r) return 0;
    return getSum(r) - getSum(l - 1);
  }

};
FT s;
vector <QUERY> upd;
vector <ii> qr, ask;
vi ans;

void runcase() {
  cin >> n;
  FOR(i, 1, n) {
    int m; cin >> m;
    vector<int> x(m),y(m);
    for (int i = 0;i < m;++i) cin >> x[i] >> y[i];
    bool f = false;
    int x_min = 1e5;
    for (int i = 0;i < m;i += 2) if (x[i] < x_min) {
      x_min = x[i];
      f = (y[i] < y[i+1]);
    }
    for (int j = 0; j < m; j += 2) {
      if (f == (y[j] < y[j+1]))
        upd.pb({x[j], 1, min(y[j + 1], y[j]), max(y[j + 1], y[j])});
      else upd.pb({x[j], -1, min(y[j + 1], y[j]), max(y[j + 1], y[j])});
    }

  }
  int nq; cin >> nq;
  qr.resize(nq);
  ask.resize(nq);
  ans.resize(nq);

  REP(i, nq) {
    cin >> ask[i].fi >> ask[i].se;
    qr[i] = mp(ask[i].fi, i);
  }
  sort(all(qr));
  sort(all(upd));

//  REP(i, sz(upd)) {
//    clog << db(upd[i].time) << db(upd[i].dt)
//    << db(upd[i].l) << db(upd[i].r) << '\n';
//  }

  int j = -1;
  REP(i, nq) {
    int askId = qr[i].se;
    while (j + 1 < sz(upd) && upd[j + 1].time <= qr[i].fi) {
      j++;
      int val = upd[j].dt;
      s.add(upd[j].l + 1, val);
      s.add(upd[j].r + 1, -1*val);
    }
    ans[askId] = s.getSum(ask[askId].se + 1);
  }
  for (int v : ans)
    cout << v << '\n';
}

int main()
{
  setIO("");
  runcase();
}
