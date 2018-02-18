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
    int i,j,k,l,t,n;
    char names[505];
    int arr[100];
    sc(t);
    repf(i,1,t+1){
       memset(arr,-1,sizeof(arr));
       scanf("%d%d %s",&n,&k,names);
       l=0;
       repf(j,0,n){
           if(arr[names[j]]!=-1 && (j-arr[names[j]])<=k)
               ++l;
           arr[names[j]]=j;
       } 
       printf("Case %d: %d\n",i,l);
    } 
}
