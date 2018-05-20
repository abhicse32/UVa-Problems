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

int main(){
    int i,j,k,l,t,p,q;
    sc(t);
    for(i=1;i<=t;++i){ 
        scc(p,q);
        printf("Case %d: ",i);
        long long smallest=LONG_MAX,largest=LONG_MAX,num;
        --p;
        int divisor= (1<<q)-1,upper_limit=(1<<p);
        for(j=0;j<upper_limit;++j){
            for(k=p-1,num=0;k>=0;--k)
                num=(num<<1)+(num<<3)+(j&(1<<k)?2:1);
            num=(num<<3)+(num<<1)+2;
            if(!(num&divisor)){
                if(smallest==LONG_MAX)
                    smallest= num;
                else largest= num;
            }
        }
        if(smallest==LONG_MAX && largest==LONG_MAX)
            printf("impossible\n");
        else{
            printf("%lld",smallest);
            if(largest!=LONG_MAX)
                printf(" %lld",largest);
            printf("\n");
        }
    }           
}
