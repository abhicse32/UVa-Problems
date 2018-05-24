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

typedef struct Common_area{
    vi towers;
    int count;
    Common_area(int n):towers(vi(n)),count(0){};
}common;

int tower_range[22];
vector<common> intersection;
vi best_comb;

int get_best_combinatiomn(int n, int b){
    int i,j,k,l;
    int max_covered=INT_MIN;
    repf(i,0,(1<<n)){
        if(__builtin_popcount(i)==b){
            int current_count=0;
            for(j=i,k=0;j;++k,j>>=1)
                if(j&1) current_count+=tower_range[k];
            for(auto& inter: intersection){
                for(j=0,l=0;j< inter.towers.size();++j)
                    if((i&(1<<inter.towers[j]))) ++l;
                if(l>1) current_count-=(inter.count*(l-1)); 
            }
            if(max_covered <= current_count){
                vi current_comb(b);
                for(j=i,k=1,l=0;j;++k,j>>=1) if(j&1) current_comb[l++]=k;
                if(max_covered < current_count) best_comb= current_comb;
                else if(current_comb< best_comb) best_comb= current_comb;
                max_covered= current_count;
            } 
        }
    }
    return max_covered;
}
int main(){
    int i,j,k,n,b,m,l,case_=1;
    while(scc(n,b),n|b){
        repf(i,0,n) sc(tower_range[i]);
        intersection.erase(intersection.begin(),intersection.end());
        sc(m);
        repf(i,0,m){
            sc(k);
            common com(k);
            repf(j,0,k) sc(l),com.towers[j]=l-1;
            sc(com.count);
            intersection.push_back(com); 
        }
        best_comb.assign(b,INT_MAX);
        j=get_best_combinatiomn(n,b);
        printf("Case Number  %d\nNumber of Customers: %d\n",case_++,j);
        printf("Locations recommended:");
        for(auto& val: best_comb) printf(" %d",val);
        printf("\n\n");
    }
}
