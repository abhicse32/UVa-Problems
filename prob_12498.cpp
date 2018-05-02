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

char matrix[55][55];
int m,n;

int get_left_count(int r, int c){
    int i;
    for(i=c-1;i>=0 && matrix[r][i]=='1';--i);
    return (i>=0?c-i:-1);
}

int get_right_count(int r, int c){
    int i;
    for(i=c+1;i<n && matrix[r][i]=='1';++i);
    return (i<n?i-c:-1);
}

int main(){
    int t,i,j,k,l,a,b,l_,r_;
    sc(t);
    repf(l,1,t+1){
        scc(m,n);
        repf(i,0,m) scanf("%s\n",matrix[i]);
        //repf(i,0,m) printf("%s\n",matrix[i]);
        bool nopath_flag= true;
        int b=INT_MAX;
        repf(j,0,n){
            a=0;
            repf(i,0,m){
                if(matrix[i][j]=='1'){
                    l_=get_left_count(i,j);
                    r_=get_right_count(i,j);
                    if(l_==-1 && r_==-1)
                        break;
                    else a+=(l_==-1 || r_==-1?abs(r_*l_):l_>r_?r_:l_);
                }
            } 
            if(i>=m){
                nopath_flag= false;
                if(a<b) b=a;
            }
        }
        if(nopath_flag) b=-1;
        printf("Case %d: %d\n",l,b);
    }
}
