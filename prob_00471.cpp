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
#define MAX 9999999999

bool check_if_different(unsigned long long N){
    int k=0,temp;
    while(N){
        temp= N%10;
        if((k&(1<<temp))!=0) return false;
        k|=(1<<temp);
        N/=10;
    }
    return true;
}

int main(){
    int t;
    unsigned long long N,s1,s2;
    sc(t);
    while(t--){
        scanf("%llu",&N);
        for(s1=N,s2=1;s1<MAX;s1+=N,++s2){
            if(check_if_different(s1) && check_if_different(s2))
                printf("%llu / %llu = %llu\n",s1,s2,N);            
        }
        if(t)
            printf("\n"); 
    }
}
