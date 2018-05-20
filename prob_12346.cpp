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
#include <bitset>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define ll long long 
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int main(){
    int i,j,k,l,m,n,t;
    ll V;
    sc(n);
    vii dam_desc;
    repf(i,0,n)
        scc(j,k),
        dam_desc.push_back(make_pair(j,k));
    sc(m);
    repf(i,1,m+1){
        scanf("%lld%d",&V,&t);
        ll min_cost=LONG_MAX;
        repf(l,0,(1<<n)){
            ll local_cost=0,water_quantity=0;
            for(k=l,j=0;k;k>>=1,++j){
               if(k&1)
                   water_quantity+=dam_desc[j].first*t,
                   local_cost+=dam_desc[j].second;
            }
            if(water_quantity>= V && local_cost<min_cost)
                min_cost= local_cost;
        }
        printf("Case %d: ",i);
        if(min_cost!=LONG_MAX)
           printf("%lld\n",min_cost); 
        else printf("IMPOSSIBLE\n");
    }
}
