#include <bits/stdc++.h>
#define TASK "Subarray Sums I"


using namespace std;

const int maxn = 2e5 + 3;
int n;
long long x, s[maxn], a[maxn], ans;
map <long long, int> Mp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen(TASK".inp", "r", stdin);
    //freopen(TASK".out", "w", stdout);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Mp[0] = 1;
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        ans += Mp[s[i] - x];
        Mp[s[i]]++;
    }
    cout << ans;
}
