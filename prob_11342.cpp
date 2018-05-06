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

void print_triplets(int k){
    int i,j,l;
    for(i=0;i<=ceil(sqrt(k/3));++i){
        int i_2= i*i,end_j= ceil(sqrt((k-i_2)>>1));
        for(j=i;j<=end_j;++j){
            int j_2= j*j, end_l= sqrt(k-i_2-j_2);
            for(l=j;l<=end_l;++l){
                if(i_2+j_2+l*l==k){
                    printf("%d %d %d\n",i,j,l);
                    return;
                }
            }
        } 
    }
    printf("-1\n");
}

int main(){
    int i,j,k,l,m,n;
    sc(n);
    while(n--){
        sc(k);
        print_triplets(k);
    }
}
