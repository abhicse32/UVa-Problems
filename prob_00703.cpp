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

typedef struct Chain{
    int a,b,c;
    Chain(int a1,int b1, int c1):a(a1),b(b1),c(c1){};
}chain;

bool comp(chain& c1, chain& c2){
    if(c1.a < c2.a) return true;
    if(c1.a==c2.a){
        if(c1.b<c2.b) return true;
        if(c1.b==c2.b && c1.c<c2.c) return true;
    }
    return false;
}

int main(){
    int i,j,k,l,m,n;
    bool arr[105][105];
    vector<chain> vect;
    while(sc(n)!=EOF){
        repf(i,1,n+1){
            repf(j,1,n+1) 
                sc(arr[i][j]);
        } 
        for(i=1;i<=n-2;++i){
            for(j=i+1;j<=n-1;++j){
                for(k=j+1;k<=n;++k){
                    if((arr[i][j] && arr[j][k] && arr[k][i])||
                            !(arr[i][j] || arr[j][i]|| arr[j][k] || 
                                arr[k][j]|| arr[k][i] || arr[i][k]))
                        vect.push_back(chain(i,j,k));
                    if((arr[k][j] && arr[j][i] && arr[i][k]))
                        vect.push_back(chain(k,j,i));  
                }
            }
        }
        printf("%u\n",vect.size());
        sort(vect.begin(),vect.end(),comp);
        for(auto&val: vect)
            printf("%d %d %d\n",val.a,val.b,val.c);
        vect.erase(vect.begin(),vect.end());
    }
}
