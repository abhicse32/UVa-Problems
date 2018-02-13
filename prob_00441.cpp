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
#include <queue>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d\n",&n,&m)
#define pr(n) printf("%d ",n)
#define prr(n,m) printf("%d %d ",n,m);
#define repf(i,a,b) for(i=a;i<b;++i)

void solve(vi& S, int k){
    int a,b,c,d,e,f;
    repf(a,0,k-5){
        repf(b,a+1,k-4){
            repf(c,b+1,k-3){
                repf(d,c+1,k-2){
                    repf(e,d+1,k-1){
                        repf(f,e+1,k){
                            printf("%d %d %d %d %d %d\n",S[a],S[b],S[c],S[d],S[e],S[f]); 
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int k,i,j,l,m,n;
    vi S(14);
    sc(k);
    while(k){
        repf(i,0,k) sc(S[i]);
        solve(S,k);
        sc(k);
        if(k)
           printf("\n");
    }
}
