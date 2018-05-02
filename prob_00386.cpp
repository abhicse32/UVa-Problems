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

int cube(int a){
    return a*a*a;
}

int main(){
    int i,j,k,a,b,c,d;
    bitset<200> bits;
    repf(a,2,201){
        bits.reset();
        int sum1=0,sum2=0,sum3=0,cube_a= cube(a);
        for(b=2;(sum1=cube(b))<cube_a;++b){
            for(c=2;(sum2=sum1+cube(c))<cube_a;++c){
                for(d=2;(sum3=sum2+cube(d))<cube_a;++d);
                if(sum3==cube_a){
                    if(!(bits[b] && bits[c] && bits[d])){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                        bits[b] = bits[c] = bits[d] = 1;                 
                    }
                }
            }
        }
    }
    //    printf("Cube = %d, Triple = (%d,%d,%d)\n",val.first,val.second->b,val.second->c,val.second->d);
}
