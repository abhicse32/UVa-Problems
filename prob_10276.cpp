#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define ll long long 
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)

int squares[55];
int get_number_of_balls(int current_num, int n_pegs){
    int i,j,k,sqrt_;
    while(true){
         repf(i,0,n_pegs){
             if(squares[i]==0 || (sqrt_=int(sqrt(j=current_num+squares[i])), sqrt_*sqrt_==j)){
                 squares[i]=current_num++;
                 break;
             }
         }
         if(i>=n_pegs) return (current_num-1);
    }    
    return -1;
}

int main(){
    int t,n;
    sc(t);
    while(t--){
        sc(n);
        memset(squares,0,sizeof squares);
        cout <<get_number_of_balls(1,n) <<endl;
    }
}
