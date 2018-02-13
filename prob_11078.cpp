#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int main(){
    int t,i,diff,k,max,n;
    sc(t);
    int size= 100005;
    vi vect(size);
    while(t--){
        sc(n);

        repf(i,0,n)
            sc(vect[i]);
        max= vect[0];
        diff= INT_MIN;
        for(i=1;i<n;++i){
            if((k=max-vect[i])>diff)
                diff= k;
            if (max<vect[i]) max= vect[i];
        }
        cout << diff <<endl;
    }
}
