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
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int main(){
    int n,i,j,k,l,d;
    int arr[10005];
    while(sc(n),n){
        char ch=getchar();
        memset(arr,0,sizeof(arr));
        repf(i,0,n)
            sc(j),arr[j]=i;
        d= (n>>1)+1;
        k=0;
        for(i=1;i<=d && !k;++i){
            for(j=0;j+(i<<1)<n;++j){
                 if((arr[j]<arr[j+i] && arr[j+i]<arr[j+(i<<1)])||
                         (arr[j]>arr[j+i] && arr[j+i]>arr[j+(i<<1)]))
                 {k=1; break;}
            }
        }
        if(k) printf("no\n");
        else printf("yes\n");
    }
}
