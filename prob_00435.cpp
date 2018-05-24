#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int power_index[25],parties[25];
int majority_votes;
void power_index_calc(int p){
    int i,coalition_sum,j,k,end=(1<<p);
    repf(i,1,end){
        coalition_sum=0;
        for(k=0,j=i;j;j>>=1,++k)
            if(j&1) coalition_sum+=parties[k];
        if(coalition_sum>=majority_votes){
            for(j=i,k=0;j;j>>=1,++k){
                if(j&1 && (coalition_sum-parties[k])<majority_votes)
                   ++power_index[k]; 
            }        
        }
    } 
}

int main(){
    int i,j,k,l,p,t;
    sc(t);
    while(t--){
        sc(p);
        repf(i,0,p) sc(parties[i]);
        //total_votes=0;
        //for_each(parties,parties+p,[&](int a){total_votes+=a;});
        k= accumulate(parties,parties+p,0);
        majority_votes=((k&1)?(k>>1)+1:k>>1);
        memset(power_index,0,sizeof power_index);
        power_index_calc(p);
        repf(i,0,p)
            printf("party %d has power index %d\n",i+1,power_index[i]);
        printf("\n");
    }
}
