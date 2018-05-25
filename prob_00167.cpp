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
#include <iomanip>
#include <bitset>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define ll long long 
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

bitset<20> cols,rd,ld;
vvi non_attacking_positions;
int board[9][9],n;
vi vect(9);

void get_valid_configs(int r){
    if(r==n){
        non_attacking_positions.push_back(vect); 
    }else{
        for(int i=0;i<n;++i){
            if(!cols[i] && !ld[r+i] && !rd[r-i+n-1]){
                cols[i]= ld[r+i]= rd[r-i+n-1]= true;
                vect[r]=i;
                get_valid_configs(r+1);
                cols[i]= ld[r+i] = rd[r-i+n-1]= false; 
            }
        } 
    }
}

int get_max(){
    int global_max=0,current=0;
    for(auto&val: non_attacking_positions){
        current=0;
        for(int i=0;i<n;++i) current+=board[i][val[i]];
        if(global_max< current) global_max= current;
    }
    return global_max;
}
int main(){
    int i,j,k,l;
    n=8;
    get_valid_configs(0);
    sc(k);
    while(k--){
        repf(i,0,8)
            repf(j,0,8)
                sc(board[i][j]);
        cout << setw(5) <<get_max() <<endl;
    }
}
