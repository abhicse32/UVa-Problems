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

unsigned long long pow_x(unsigned long long a, int exp){
    unsigned long long pow_= 1, pow_2= a;
    while(exp){
        if(exp&1) pow_*=pow_2;
        pow_2*= pow_2;
        exp>>=1; 
    }    
    return pow_;
}

int main(){
    unsigned long long n;
    while(scanf("%llu",&n)!=EOF){
        unsigned long long n_2= pow_x(n,2), n_3= pow_x(n,3),n_4= pow_x(n,4);
        unsigned long long n_12= pow_x(n+1,2), n_13 = pow_x(n+1,3), n_14= pow_x(n+1,4);
        unsigned long long S2= (n*(n+1)*(2*n+1))/6;
        unsigned long long S3= (n_2*n_12)>>2;
        unsigned long long R2= S3 - S2;
        unsigned long long R3= ((n_3*n_13)>>3)- S3;
        unsigned long long S4= (n*(6*n_4 + 15*n_3 + 10*n_2 - 1))/30;
        unsigned long long R4 = ((n_4*n_14)>>4) - S4;
        printf("%llu %llu %llu %llu %llu %llu\n",S2,R2,S3,R3,S4,R4); 
    }
}
