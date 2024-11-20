#include <bits/stdc++.h>
#define TASK "Traffic Lights"


using namespace std;

int n, x;
set <int> st;
multiset <int> len;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(TASK".inp", "r", stdin);
//    freopen(TASK".out", "w", stdout);
    cin >> x;
    cin >> n;
    st.insert(0);
    st.insert(x);
    len.insert(x);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        int r = *st.upper_bound(x);
        int l = *(--st.lower_bound(x));
        //cerr << " " << r << ' ' << l << '\n';
        len.erase(len.find(r - l));
        len.insert(x - l);
        len.insert(r - x);
        st.insert(x);
        cout << *len.rbegin() << ' ';
        //cerr << i << '\n';
    }


}
