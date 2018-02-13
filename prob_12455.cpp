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

bool get_sum(vi& arr, int n, int X){
    int i,max=(1<<n);
    repf(i,0,max){
        int sum=0,temp=i,j=0;
        while(temp){
            if(temp&1)
                sum+=arr[j];
            temp>>=1;
            ++j;
        }
       if(sum==X)
          return true; 
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
        
        if(get_sum(arr,m,X))
            printf("YES\n");
        else printf("NO\n");
    }
}
