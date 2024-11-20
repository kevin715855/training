#include <bits/stdc++.h>
using namespace std;



int sc(int n){
    return 2*n + n*(n-1);
}
int sl(int n){
    return 1*n + n*(n-1);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<sc(b/2)-sc((a-1)/2)-(sl((b+1)/2) - sl((a)/2));
}
