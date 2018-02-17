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
    int i,j,k,t,n,q,closest,num;
    int counter=1;
    int arr[1005];
    while(sc(n),n){ 
       repf(i,0,n) sc(arr[i]);
       sort(arr,arr+n);
       sc(q);
       printf("Case %d:\n",counter++); 
       repf(i,0,q){
           sc(num);
           closest= INT_MAX;
           for(j=0,k=n-1;j<k;){
               int sum= arr[j]+arr[k];
               int abs_sum=abs(sum-num);
               int abs_closest= abs(closest-num);
               if(abs_sum< abs_closest)
                   closest= sum;
               //if(abs_sum==abs_closest && sum<closest)
               //    closest= sum;
               if(sum>num)--k;
               else ++j;
           }
            printf("Closest sum to %d is %d.\n",num,closest);
       }
    } 
}
