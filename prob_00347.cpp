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

int arr[10],digs;
bool get_digs(int n){
    digs=0;
    int k=0,temp;
    while(n){
        temp= n%10;
        if((k&(1<<temp))!=0) return false;
        k|=(1<<temp);
        arr[digs++]= temp;
        n/=10;
    }
    for(int i=0,j=digs-1;i<=j;++i,--j)
        swap(arr[i],arr[j]);
    return true;
}

int main(){
    int i,j,k,l,n,case_=1;
    while(sc(n),n){
       for(i=n;;++i){
           if(!get_digs(i)) continue;
           int final_=((1<<digs)-1),k=0;
           for(j=0;k!=final_;){
               int next= (arr[j]+j)%digs;
               if((k&(1<<next))!=0)
                   break;
               else{
                   k|=(1<<next);
                   j=next;
               }
           }
           if(k==final_) break;
       }
       printf("Case %d: %d\n",case_++,i);
    }
}
