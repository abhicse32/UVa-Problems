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
#include <queue>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d\n",&n,&m)
#define pr(n) printf("%d ",n)
#define prr(n,m) printf("%d %d ",n,m);
#define repf(i,a,b) for(i=a;i<b;++i)

bool get_result(vi& arr, int idx, int X, int sum){
    if(idx<0){
        if(sum==X)
            return true;
    }else{
        return get_result(arr,idx-1,X,sum+arr[idx]) || get_result(arr,idx-1,X,sum);
    }
    return false;
}

int main(){
    int i,j,k,n,m,X;
    sc(n);
    vi arr(21);
    repf(i,0,n){
        scc(X,m);
        repf(j,0,m)
            sc(arr[j]);
        
        if(get_result(arr,m-1,X,0))
            printf("YES\n");
        else printf("NO\n");
    }
}
