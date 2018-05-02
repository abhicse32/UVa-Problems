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
#define scc(n,m) scanf("%d%d\n",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

char database[1005][105];
int main(){
    int i,j,k,l,m,q,l1,l2;    
    int a,b,c,xyz,local_hamming,idx;
    char query[105];
    scc(m,q);
    repf(i,0,m)
        scanf("%s\n",database[i]);
    repf(i,0,q){
        scanf("%s\n",query);
        int min_hamming=INT_MAX,idx=-1; 
        repf(j,0,m){
            local_hamming=INT_MAX;
            if((l1=strlen(query))<=(l2=strlen(database[j]))){
                for(a=0;a<=l2-l1;++a){
                     xyz=0;
                     for(b=a,c=0;c<l1;++b,++c)
                         if(database[j][b]!=query[c]) ++xyz;
     
                     if(xyz<local_hamming)
                         local_hamming=xyz;
                }
            }
            if(local_hamming<min_hamming)
                min_hamming=local_hamming,
                    idx=j+1;
        }
        printf("%d\n",idx);
    }
}
