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
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked
#define MAX_K 50002
int calculated_results[MAX_K][3];

void precalc(){
    int i,j,k,l;
    repf(i,0,MAX_K)
        calculated_results[i][0]= -1;
    for(i=0;i<=floor(sqrt(MAX_K/3));++i){
        int i_2= i*i, end_j= floor(sqrt((MAX_K-i_2)>>1));
        for(j=i;j<=end_j;++j){
            int j_2= j*j, end_l= floor(sqrt(MAX_K-i_2-j_2));
            for(l=j;l<=end_l;++l){
                k= i_2+j_2+l*l;
                if(calculated_results[k][0]==-1){ 
                    calculated_results[k][0]= i;
                    calculated_results[k][1]= j;
                    calculated_results[k][2]= l;
                }
            }
        }
    }   
}

int main(){
    int i,j,k,l,m,n;
    sc(n);
    precalc();
    while(n--){
        sc(k);
        if(calculated_results[k][0]!=-1)
            printf("%d %d %d\n",calculated_results[k][0],calculated_results[k][1],calculated_results[k][2]);
        else printf("-1\n");
    }
}
