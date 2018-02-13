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
    int i,j,k,n,V,V_0;
    while(scc(V,V_0), V && V_0){
        if(!(V%(V_0<<1)))
            cout << V/(V_0<<1) <<endl;
        else{
            double d= double(V)/(V_0<<1);
            int n1= floor(d),n2=ceil(d);
            //cout <<d <<" " << n1 <<" "<< n2 <<endl;
            unsigned long long r1= n1==0 || (V <= V_0*n1)?0:1e8*(n1*0.3*sqrt(double(V)/n1-V_0));
            unsigned long long r2= n2==0 || (V <= V_0*n2)?0:1e8*(n2*0.3*sqrt(double(V)/n2-V_0));
            //printf("%llu %llu\n",r1,r2);
            int result=0;
            if(r1<r2) result= n2;
            else if(r1>r2) result= n1;
            cout << result <<endl;            
        }
    }
}
