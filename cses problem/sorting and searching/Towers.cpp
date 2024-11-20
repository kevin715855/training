#include <bits/stdc++.h>
#define TASK "Towers"


using namespace std;

const int maxn = 2e5 + 2;
int n;
int a[maxn], d[maxn], ans;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int j = upper_bound(d + 1, d + ans + 1, a[i]) - d - 1;
        if (j == ans)
            d[++ans] = a[i];
        d[j + 1] = min(d[j + 1], a[i]);
    }
    cout << ans;
}
