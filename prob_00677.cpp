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

vector<vector<bool> > matrix(15,vector<bool>(15));
int m,n;
vector<int> nodes(15);
vector<bool> visited(15);
bool flag=false;

void print_n_walks(int src,int dist){
    if(dist==m){
        flag=true;
        printf("(%d",nodes[0]);
        for(int i=1;i<=m;i++) printf(",%d",nodes[i]);
        printf(")\n");
    }else{
         for(int i=0;i<n;++i){
            if(matrix[src][i] && !visited[i]){
                visited[i]=true;
                nodes[dist+1]=i+1;
                print_n_walks(i,dist+1);
                visited[i]=false;
            }
         }
    }
}

int main(){
    int i,j,k,l;
    
    while(cin>> n >> m){
        repf(i,0,n)
            repf(j,0,n)
                sc(k),matrix[i][j]=k;
        visited.assign(n,false);
        visited[0]=1, nodes[0]=1;
        flag=false;
        print_n_walks(0,0);
        if(!flag)
            printf("no walk of length %d\n",m);
        if(sc(n)!=EOF)
            printf("\n");
    }
}
