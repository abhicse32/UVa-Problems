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
#define gc getchar_unlocked
#define MAX_SIZE 1000005

int main(){
    int m,n,i,j,k;
    // using map makes it faster twice
    map<int,vi> ad_map;
    while(scanf("%d%d",&m,&n)!=EOF){
        ad_map.erase(ad_map.begin(), ad_map.end());
        repf(i,1,m+1){
            sc(k);
            ad_map[k].push_back(i);
        }
        repf(i,0,n){
            scanf("%d%d",&j,&k);
            if(ad_map[k].size()<j)
                printf("0\n");
            else printf("%d\n",ad_map[k][j-1]);
        }
        ad_map.erase(ad_map.begin(), ad_map.end());
    }
}
