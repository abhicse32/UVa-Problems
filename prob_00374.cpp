#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll modex(ll a, ll b, ll m){
    ll res=1;
    a %= m;
    while(b){
        if(b & 1)
            res = (res * a) % m;
        b >>= 1;
        a = (a * a) %m;
    }
    return res;
}

int main(){
    int n,i,j,k;
    while(cin >> i >> j >> k){
        cout << modex(i, j, k) <<endl;
    }
    cin >> n;
}
