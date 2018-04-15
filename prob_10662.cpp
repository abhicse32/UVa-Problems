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

void take_input(int a, int b, int arr[21][21]){
    for(int i=0;i<a;++i){
        for(int j=0;j<=b;++j)
            sc(arr[i][j]);
    }
}

void print_matrices(int a, int b, int m[21][21]){
    for(int i=0;i<a;++i){
        for(int j=0;j<=b;++j)
            printf("%d ",m[i][j]);
        printf("\n");
    }
    printf("\n");    
}

int main(){
    int t,r,h,i,j,k,l;
    int afford_t,afford_r,afford_h;
    int T[21][21],R[21][21],H[21][21];
    
    while(scanf("%d%d%d",&t,&r,&h)!=EOF){
        take_input(t,r,T);
        take_input(r,h,R);
        take_input(h,t,H);
        //print_matrices(t,r,T);
        //print_matrices(r,h,R);
        //print_matrices(h,t,H);
        int min_price= INT_MAX;
        for(i=0;i<t;++i){
            for(j=1;j<=r;++j){
                if(T[i][j]==0){
                    for(k=1;k<=h;++k){
                        if(R[j-1][k]==0){
                            for(l=1;l<=t;++l){
                                if(H[k-1][l]==0 && (l-1)==i){
                                    int budget= T[i][0]+R[j-1][0]+H[k-1][0];
                                    if(budget<min_price){
                                        min_price= budget;
                                        afford_t=i;
                                        afford_r= j-1;
                                        afford_h= k-1;
                                    }
                                }
                            }
                        }
                    } 
                }
            } 
        }
        if(min_price==INT_MAX)
          printf("Don't get married!\n");
       else printf("%d %d %d:%d\n",afford_t,afford_r,afford_h,min_price);
    }  
}
