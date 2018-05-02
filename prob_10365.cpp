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

int get_min_area(int a, int b){
    int min_area= (a*b+a+b)<<1;
    for(int i=(b&1)?3:2;i<=(b>>1);i+=2){
        if(!(b%i)){
            int x= b/i;
            int area= (i*x+x*a+i*a)<<1;
            if(area< min_area)
                min_area= area;
        }
    }
    return min_area;
}

int main(){
    int i,j,k,l,n,t;
    sc(t);
    while(t--){
        sc(n);
        int min_area= (1+(n<<1))<<1;
        //printf("%d\n",min_area);
        for(i=(n&1)?3:2;i<=(n>>1);i+=2){
            if(!(n%i)){
                int area= get_min_area(i,n/i);
                if(area< min_area)
                    min_area= area;
            }
        }
        printf("%d\n",min_area);    
    }
}
