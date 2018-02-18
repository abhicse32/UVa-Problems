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
   int start[30],end[30];
    while(sc(n)!=EOF){
        repf(i,0,n) sc(start[i]);
        repf(i,0,n) sc(end[i]);
        int min_crosses=0;
        for(i=0;i<n;++i){
            if(start[i]!=end[i]){
                for(j=i+1;start[j]!=end[i];++j);
                min_crosses+=(j-i);
                for(;j>i;--j)
                   start[j]=start[j-1];
                start[j]= end[i]; 
            }
        }
       printf("%d\n",min_crosses); 
    } 
}
