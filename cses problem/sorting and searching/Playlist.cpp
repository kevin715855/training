#include <bits/stdc++.h>

using namespace std;


int n, ans;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int l = 1;
    map <int, int> last;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        auto it = last.find(x);
        if (it != last.end())
            l = max(l, it->second + 1);
        ans = max(ans, i - l + 1);
        last[x] = i;
    }
    cout << ans;
}
