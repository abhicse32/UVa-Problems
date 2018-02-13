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
    int i,j,k,l,n,t;
    int arr[1005];
    sc(t);
    while(t--){
       sc(n); 
       repf(i,0,n)sc(arr[i]);
       //insertion sort and count the number of shifts for each integer
       k=0;
       for(i=1;i<n;++i){
          l= arr[i];
          for(j=i-1;j>=0 && arr[j]<=l;--j) arr[j+1]=arr[j];
          arr[j+1]= l;
          k+=(i-j-1);
       }
       printf("%d\n",k);
    }
}

