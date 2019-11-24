#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll extended_euclidean(ll a, ll m, ll &x, ll &y){
    if(!m){
        x = 1, y= 0;
        return a;
    }
    ll tmp_x, tmp_y;
    ll gc = extended_euclidean(m, a % m, tmp_x, tmp_y);
    x = tmp_y, y = tmp_x - (a/m) * tmp_y;
    return gc;
}

int main(){
   ll a, b, x, y;
    while(cin >> a >>b ){
        int gc = extended_euclidean(a, b, x, y);
        cout << x <<" " << y <<" " << gc <<endl;
    } 
}
