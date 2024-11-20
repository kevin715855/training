#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn], tree[maxn];
int n, q;
void update(int k , long long x)
{
    while (k <= n)
    {
        tree[k] += x;
        k += k & (-k);
    }
}
long long sum(int k)
{
    long long s = 0;
    while (k >= 1)
    {
        s += tree[k];
        k -= k & (-k);
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        int t; cin >> t;
        if (t == 1)
        {
            int k; long long u;
            cin >> k >> u;
            update(k, u - a[k]);
            a[k] = u;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << sum(y) - sum(x - 1) << "\n";
        }
    }
    return 0;
}
