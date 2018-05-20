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
#define vs vector<string>
#define ll long long 
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int main(){
    int i,j,k,l,t,n,m;
    sc(t);
    int matrix[10][10];
    while(t--){
        sc(n);
        repf(i,0,n)
            repf(j,0,n)
                sc(matrix[i][j]);
        vi vect(n);
        i=-1;
        generate(vect.begin(),vect.end(),[&i]{return ++i;});
        int won= INT_MAX;
        do{
            int local_res=0;
            repf(i,0,n)
                local_res+=matrix[i][vect[i]];
            if(local_res<won) won= local_res;
        }while(next_permutation(vect.begin(),vect.end()));
        printf("%d\n",won);
    }
}
