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


const int N = 5e3+5, mod = 1e9 + 7, LG = 15;
template <const ll MOD>
struct modint {
  ll value;
  modint() = default;
  modint(ll value_) : value(value_) {}
  inline modint<MOD> operator + (modint<MOD> other) const { ll c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
  inline modint<MOD> operator - (modint<MOD> other) const { ll c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
  inline modint<MOD> operator * (modint<MOD> other) const { ll c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
  inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
  inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
  inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
  inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
  modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
  modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
  inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
  inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
  inline bool operator == (modint<MOD> other) const { return value == other.value; }
  inline bool operator != (modint<MOD> other) const { return value != other.value; }
  inline bool operator < (modint<MOD> other) const { return value < other.value; }
  inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <ll MOD> modint<MOD> operator * (ll value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <ll MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <ll MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;


int n, s;
int a[N];
vector <int> arr, b;
long long f[LG][5005];
struct combi{
  int n; vector<mint> facts, finvs, invs;
  combi(int _n): n(_n), facts(_n), finvs(_n), invs(_n){
    facts[0] = finvs[0] = 1;
    invs[1] = 1;
    for (int i = 2; i < n; i++) invs[i] =  invs[mod % i] * (-mod / i);
    for(int i = 1; i < n; i++){
      facts[i] = facts[i - 1] * i;
      finvs[i] = finvs[i - 1] * invs[i];
    }
  }
  inline mint fact(int n) { return facts[n]; }
  inline mint finv(int n) { return finvs[n]; }
  inline mint inv(int n) { return invs[n]; }
  inline mint ncr(int n, int k) { return n < k or k < 0 ? 0 : facts[n] * finvs[k] * finvs[n-k]; }
};


long long Pow(long long a, long long x) {
  if (x == 0) return 1;
  long long gt = Pow(a, x/2);
  gt = gt*gt%mod;
  if (x % 2 == 1) return gt*a%mod;
  return gt;
}
void genS(int s) {
  while (s%2==0) {
    arr.push_back(s);
    b.push_back(a[s]);
    s/=2;
  }
  arr.push_back(s);
  b.push_back(a[s]);
  reverse(all(arr));
  reverse(all(b));
}
void add(long long &x, long long y) {x += y; if (x >= mod) x -= mod;}

int main()
{
  setIO("slime");

  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }

  genS(s);
  combi C(n + 3);


  int m = arr.size();
  for (int i = 0; i < MASK(m - 1); i++)
    f[0][i] = C.ncr(b[0], i).value;

  for (int i = 0; i < m; i++) {
    int Max = Pow(2, m - i - 1);
    for (int j = 0; j < Max; j++)
        for (int k = 0; k + j/2 < Max/2 && k <= b[i + 1]; k++)
          add(f[i + 1][k + j/2], f[i][j] * C.ncr(b[i + 1], k).value % mod);
  }

  int left = n;
  for (int x : arr)
    left -= a[x];
  f[m - 1][0] *= Pow(2, left);
  f[m - 1][0] %= mod;

  long long ans = Pow(2, n);
  ans -= f[m - 1][0];
  if (ans < 0) ans += mod;
  cout << ans;
}

