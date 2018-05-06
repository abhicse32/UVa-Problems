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

bool graph[3005][3005];

int main(){ 
    int i,j,k,l,m,n,t;
    sc(t);
    while(t--){
        memset(graph,false,sizeof graph);
        scc(n,m);
        repf(i,0,m)
            scc(j,k),
            graph[j][k]= graph[k][j] = true;
        l=0;
        repf(i,1,n-1){
            repf(j,i+1,n+1){
                if(graph[i][j]){
                    int tri_count=0;
                    repf(k,j+1,n+1){
                        if(graph[j][k] && graph[k][i]){
                            ++l, ++tri_count;
                            if(tri_count>=2) break;
                        }
                    }
                }
            } 
        } 
        printf("%d\n",l); 
    }  
}
