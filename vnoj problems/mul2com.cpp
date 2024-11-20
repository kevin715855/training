#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define __builtin_popcount __builtin_popcountll
#define BIT(x,i) (((x)>>(i))&1)
#define SZ(x) ((int)(x).size())
#define MASK(x) (1<<(x))
#define ll long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define all(c) ((c).begin()), ((c).end())
using namespace std;
const int mod=1e9+7;
const int inf=1e9;
const ll INF=1e18;
const int maxn=1e6+3;
int numt;
typedef pair <int,int>ii;
typedef string bignum;
typedef vector <int>vi;
template <class T> bool minimize(T &x,T y){if(x>y){x=y;return true;}return false;}
template <class T> bool maximize(T &x,T y){if(x<y){x=y;return true;}return false;}

int n, dau;
bignum a, b, Min;

bignum add(bignum a, bignum b) {
    while(b.size() < n)
        b = '0' + b;
    while (a.size() < n)
        a = '0' + a;
    bignum ans(n, '0');
    int rem = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = a[i] + b[i] - '0' + rem;
        if (ans[i] > '1') {
            ans[i] -= 2;
            rem = 1;
        }
        else
            rem = 0;
    }
    return ans;
}
bignum dec(bignum a, bignum b) {
    while(b.size() < n)
        b = '0' + b;
    while (a.size() < n)
        a = '0' + a;
    bignum ans(n, '0');
    int rem = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = a[i] - b[i] + '0' - rem;
        if (ans[i] < '0') {
            ans[i] += 2;
            rem = 1;
        }
        else
            rem = 0;
    }
    return ans;
}
///string == vector <char> ++
bignum mul(bignum a, bignum b) {
    bignum ans(n, '0');
    for (int i = 0; i < n/2; i++) {
        if (b[SZ(b) - i - 1] == '0') continue;
        bignum sa = a.substr(i);
        while (sa.size() < n)
            sa.pb('0');
        ans = add(ans, sa);
    }
    Min = "";
    REP(i,n/2)
        Min.pb('0');
    Min.pb('1');
    FOR(i, 1, n/2 - 1)
        Min.pb('0');
    if (dau&1)
        if (ans == Min)
            return Min;
    for (int i = 0; i <= n/2; i++)
        if (ans[i] == '1')
            return "overflow";
    if (dau&1) {
        ans = dec(Min, ans);
        ans[n/2] = '1';
    }
    return ans.substr(n/2);
}
#define _DEBUG
#define TASK "mul2com"
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    #ifdef _DEBUG

    while (cin >> n){
        if (n == 0)
            return 0;
        cin >> a >> b;
        dau=0;
        n=2*n;
        if (a[0] == '1') {
            for (char &ch : a)
                ch = (ch == '1' ? '0' : '1');
            a = add(a, "1");
            dau++;
        }
        else
            a = add(a, "0");
        if (b[0] == '1') {
            for (char &ch : b)
            ch = (ch == '1' ? '0' : '1');
            b = add(b, "1");
            dau++;
        }
        else
            b = add(b, "0");
        cout << mul(a, b) << '\n';
    }
    #endif
}
