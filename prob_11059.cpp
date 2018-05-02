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
    int i,j,k,l,m,n,case_=1;
    long long matrix[21][21];
    int arr[21];
    while(sc(n)!=EOF){
        repf(i,1,n+1) sc(arr[i]);
        memset(matrix,0,sizeof(matrix));
        long long max_= 0;
        repf(i,1,n+1){
            matrix[i][i]=arr[i];
            if(max_< arr[i])
                max_= arr[i];
        }

        repf(i,2,n+1){
           for(j=1;(j+i)<=(n+1);++j){
               int col= j+i-1;
               matrix[j][col] = matrix[j][col-1]*((long long) arr[col]);
               if(matrix[j][col] >max_)
                   max_ = matrix[j][col];
           } 
        }
        /*repf(i,0,n+1){
            repf(j,0,n+1)
                printf("%lld ",matrix[i][j]);
            printf("\n");
        }*/
        printf("Case #%d: The maximum product is %lld.\n\n",case_++,max_);
    }
}
