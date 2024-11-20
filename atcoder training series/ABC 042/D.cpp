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

const int mod = 1e9+7;
const int MAX=2e5+2;
int gt[MAX+3],inv[MAX+3];

ll Pow(ll a,ll x){
    if(x==0)
        return 1;
    ll gt=Pow(a,x/2);
    gt=gt*gt%mod;
    if(x&1)
        return gt*a%mod;
    return gt;
}
void prepare(){
    gt[0]=inv[0]=1;
    for(ll i=1; i<=MAX;i++)
        gt[i]=1LL*gt[i-1]*i%mod;
    inv[MAX]=Pow(gt[MAX],mod-2);
    for(ll i=MAX-1; i>=1;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
}
ll comb(int k,int n){
    return 1LL*gt[n]*inv[k]%mod*inv[n-k]%mod;
}
ll go(int x, int y){
    return comb(x - 1, x + y - 2);
}

void add(ll &x, ll y) {
  x += y; if (x >= mod) x -= mod;
}
void runcase() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  ll an = 0;
  FOR(i, 1, h - a) {
    add(an, go(i, b) * go(h - i + 1, w - b) % mod);
  }
  cout << an;
}

int main()
{
  setIO("");
  numt = 1;
  prepare();
  while (numt--) runcase();
}
