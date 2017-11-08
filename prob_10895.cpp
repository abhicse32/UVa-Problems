#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d",&n)
#define repf(i,a,b) for(i=a;i<b;++i)
#define repb(i,a,b) for(i=a;i>b;--i)

int main(){
    int m,n,i,j,k;
    int col_nums;
    vvii transpose;
    while(scanf("%d%d",&m,&n)!=EOF){
       vi cols(n+1);
       transpose.erase(transpose.begin(),transpose.end());
       transpose.assign(n+1,vii{});
       repf(i,1,m+1){
           sc(col_nums);
           repf(j,0,col_nums)
               sc(cols[j]);
           repf(j,0,col_nums){
               sc(k);
               transpose[cols[j]].push_back(make_pair(k,i));
           }
       }
       printf("%d %d\n",n,m);
       repf(i,1,n+1){
           printf("%lu",transpose[i].size());
           for(auto &val: transpose[i])
               printf(" %d",val.second);
           printf("\n");
           if(transpose[i].size())
               printf("%d",transpose[i][0].first);
           repf(j,1,transpose[i].size())
               printf(" %d",transpose[i][j].first);
           printf("\n");
       } 
    }
}
