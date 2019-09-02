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

char paths[10][10];
string commands[10],str="IEHOVA";
int m,n;
void get_commands(int r, int c,int str_idx){
    if(paths[r][c]=='#' && str_idx>str.size()) return;
    if(r>0 && (paths[r-1][c]=='#' || paths[r-1][c]==str[str_idx]))
        commands[str_idx]="forth",
        get_commands(r-1,c,str_idx+1);
    if(c+1<n && (paths[r][c+1]=='#' || paths[r][c+1]==str[str_idx]))
        commands[str_idx]="right",
        get_commands(r,c+1,str_idx+1);
    if(c>0 && (paths[r][c-1]=='#' || paths[r][c-1]==str[str_idx]))
        commands[str_idx]= "left",
        get_commands(r,c-1,str_idx+1);
}

int main(){
    int i,j,k,t;
    sc(t);
    while(t--){
        scc(m,n);
        repf(i,0,m)
            scanf("%s",paths[i]);
        repf(j,0,n) if(paths[m-1][j]=='@') break; 
        get_commands(m-1,j,0);
        cout << commands[0];
        repf(i,1,7)
            cout << " " << commands[i];
        cout <<endl; 
    }
}
