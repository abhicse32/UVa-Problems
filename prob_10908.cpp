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

int main(){
    int i,j,k,a,b,m,n,q,t,r,c;
    char matrix[105][105];
    sc(t);
    while(t--){
        scanf("%d%d%d\n",&m,&n,&q);
        repf(i,0,m)
            scanf("%s",matrix[i]);
        printf("%d %d %d\n",m,n,q);
        repf(i,0,q){
            scc(r,c);
            for(j=1;r-j>=0 && r+j<m && c-j>=0 && c+j<n;++j){
                for(k=c-j;(k <= c+j) && matrix[r-j][k]==matrix[r][c]
                         && matrix[r+j][k]==matrix[r][c];++k);
                if(k<=c+j) break;
                for(k=r-j;k<=r+j && matrix[k][c-j]==matrix[r][c]
                        && matrix[k][c+j]==matrix[r][c]; ++k);

                if(k<=r+j) break;
            }
            --j;
            printf("%d\n",(j<<1)+1);
        }
    }
}
