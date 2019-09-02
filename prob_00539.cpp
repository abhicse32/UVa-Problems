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

bool graph[30][30];
int n,m;
int get_longest_path(int src, int curr_len){
    int down_len=0;
    for(int i=0;i<n;++i){
        if(graph[src][i]){
            graph[src][i]=graph[i][src]=false;
            int x=get_longest_path(i,curr_len+1);
            if(down_len<x) down_len= x;
            graph[src][i]=graph[i][src]=true;
        }
    }
    return max(curr_len,down_len);
}

int main(){
    int i,j,k,l;
    while(scc(n,m),n){
        memset(graph,false,sizeof graph);
        repf(i,0,m)
            scc(j,k),graph[j][k]=graph[k][j]=true;
        int max_len=0;
        repf(i,0,n){
            if(max_len<(k=get_longest_path(i,0))){
               max_len=k; 
            }
        }
        cout << max_len <<endl;
    }    
}
