#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

char board[5][5];
int n;
bool check_if_possible(int row,int col, int p){
    for(int i=col+1;i<n && board[row][i]!='X';++i) if(p&(1<<(row*n+i))) return false;
    for(int i=col-1;i>=0 && board[row][i]!='X';--i) if(p&(1<<(row*n+i))) return false;
    for(int i=row+1;i<n && board[i][col]!='X';++i) if(p&(1<<(i*n+col))) return false;
    for(int i=row-1;i>=0 && board[i][col]!='X';--i)if(p&(1<<(i*n+col))) return false; 
    return true;
}

int get_max_placings(){
    int end=(1<<(n*n)),i,j,k=0,l,row,col;

    repf(i,1,end){
       if(__builtin_popcount(i)>k){
           int current_count=0;
           for(j=i,l=0;j;++l,j>>=1){
               if(j&1 && board[row=l/n][col=l%n]!='X' && check_if_possible(row,col,i))
                  ++current_count; 
           }
           if(current_count>k) k= current_count;
       }
    }
    return k;
}
int main(){
    int i,j,k,l;
    while(sc(n),n){     
        repf(i,0,n)
            scanf("%s",board[i]);
        cout << get_max_placings()<<endl;
    }
}
