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

typedef struct Constraints cons;
struct Constraints{
    int a, b,c;
};

int get_pos(int a, vi&goers, int n){
    for(int i=0;i<n;++i)
        if(a==goers[i])
            return i;
    return -1;
}

bool check_constraints(vi& goers, int n, vector<cons>& constraints, int m){
    int i;
    repf(i,0,m){
        int index_a= get_pos(constraints[i].a,goers,n);
        int index_b= get_pos(constraints[i].b,goers,n);
        //printf("%d %d : %d %d\n",index_a,index_b,constraints[i].a, constraints[i].b);
        if((constraints[i].c >0 && abs(index_a - index_b)>constraints[i].c) ||
                (constraints[i].c<0 && abs(index_a-index_b)<abs(constraints[i].c)))
            return false;
    }
    return true;
}

int main(){
    int i,j,k,l,m,n;
    vi goers(9);
    vector<cons> constraints(22);

    while(scc(n,m), n){
        repf(i,0,m)
            scanf("%d%d%d",&constraints[i].a, &constraints[i].b, &constraints[i].c);
        repf(i,0,n)
            goers[i]=i;
        int res=0;
        do{
           // print_permutation(goers,n);
            if(check_constraints(goers,n,constraints,m))
               ++res; 
        }while(next_permutation(goers.begin(),goers.begin()+n));      
        printf("%d\n",res);
    }
}
