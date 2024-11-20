// ඞඞඞඞඞඞ you sus
#include <bits/stdc++.h>

#define __builtin_popcount __builtin_popcountll
#define BIT(x, i) (((x)>> (i))& 1)
#define MASK(x) (1LL<< (x))
#define sqr(x) ((x)* (x))
#define MOD 1000000007

using namespace std;

typedef long long ll;

template<class X,class Y>
    void minimize(X &x,const Y y) {
        if (x>y) x= y;
    }
template<class X,class Y>
    void maximize(X &x,const Y y) {
        if (x<y) x= y;
    }
template<class T>
    T Abs(const T x) {
        return (x<0?-x:x);
    }

template <class T>
    void Mod(T &t) {
        if(t>= MOD) t-= MOD;
    }

template <class X, class Y>
    ll Gcd(const X a, const Y b){
        if(b== 0)   return a;
        else return Gcd(b, a% b);
    }

template <class X, class Y>
    ll Lcm(const X a, const Y b){
        return ((a*b)/gcd(a, b));
    }

template <class X, class Y>
    void Add(X &x, const Y y){
        if((x+= y)>= MOD) x-= MOD;
    }

void input(){
    cin>> n>> x>> y;
    for(long long i= 1; i<= n; i++){
        cin>> b[i];
    }
    ///
    ///
    ///
    ///
}

int main()

{   ios_base::sync_with_stdio(0);cin.tie(0);
    #define task ""
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    if(fopen("task.inp", "r")){
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    input();
    return 0;
}
/*
5
-1254
16276726
1000000000 -1000000000 1000000000 -1000000000 -16472233
*/
