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
    cin >> n;
    while(n){
        cin >> i >> j;
        double log_ij = j*log10(i);
        int msd3 = int(pow(10, log_ij - int(log_ij))*100);
        cout <<msd3  <<"..." <<setw(3) << modex(i, j, 1000) <<endl;
        --n;
    }
    cin >> n;
}
