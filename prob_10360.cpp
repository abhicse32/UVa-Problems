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

typedef struct Pos_num{
    int x,y,num;
}pos_num;

int main(){
    int d,i,j,k,t,n,l,m;
    sc(t);
    int area[1030][1030];
    vector<pos_num> vect;
    while(t--){
        sc(d);
        sc(n);
        memset(area,0,sizeof area);
        vect.erase(vect.begin(),vect.end());
        repf(i,0,n){
            pos_num var;
            scanf("%d%d%d",&var.x,&var.y,&var.num);
            vect.push_back(var);
        }
        for(auto& var: vect){        
            int start_row= var.x-d>=0?var.x-d:0;
            int end_row= var.x+d<=1024?var.x+d:1024;
            int start_col= var.y-d>=0?var.y-d:0;
            int end_col= var.y+d<=1024?var.y+d:1024;

            for(int a=start_row;a<=end_row;++a)
                for(int b=start_col;b<=end_col;++b)
                    area[a][b]+=var.num;
        }

        m= INT_MIN;
        k=l=-1;
        repf(i,0,1025)
            repf(j,0,1025)
                if(area[i][j]>m){
                    m= area[i][j];
                    k=i;l=j;            
                }
        printf("%d %d %d\n",k,l,m);
    }      
}
