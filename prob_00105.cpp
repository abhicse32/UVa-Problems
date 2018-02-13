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
    int i,j,k=0,l,h,r;
    int* arr= new int[10005];
    while(scanf("%d%d%d",&l,&h,&r)!=EOF){
        if(r>k) k=r;
         for(i=l;i<r;++i)
             if(h>arr[i]) arr[i]=h;
    }
    i=1;j=i+1;
    while(j<=k && arr[j]==arr[j-1]) ++j;
    printf("%d %d",i,arr[i]);i=j;
    for(;i<=k;){
        j=i+1;
        while(j<=k && arr[j]==arr[j-1]) ++j;
        printf(" %d %d",i,arr[i]); 
        i=j;
    }
    printf("\n");
}
