#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define ll long long 
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d\n",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)

bitset<20> rows,rd,ld;
vvi non_attacking_positions;
int n=8;
vi cols(n);

void get_non_attacking_configs(int c){
    if(c==n){
        non_attacking_positions.push_back(cols);         
    }else{
        for(int r=0;r<n;++r){
            if(!rows[r] && !ld[r+c] && !rd[r-c+n-1]){
                rows[r]=rd[r-c+n-1]=ld[r+c]=true;
                cols[c]=r+1;
                get_non_attacking_configs(c+1);
                rows[r]= ld[r+c]= rd[r-c+n-1]=false;
            }
        }          
    }
}

int get_min_moves(){
    int min_moves=INT_MAX;
    for(auto& config:non_attacking_positions){
        int moves=0;
        for(int i=0;i<n;moves+=(config[i]==cols[i]?0:1),++i);
        if(moves<min_moves) min_moves= moves;
    }
    //cout << endl;
    return min_moves;
}

int main(){
    int i,j,k=1,l;
    get_non_attacking_configs(0);
    while(cin >> cols[0], !cin.eof()){
        repf(i,1,n) cin >> cols[i];
        printf("Case %d: %d\n",k++,get_min_moves());
    }
}

