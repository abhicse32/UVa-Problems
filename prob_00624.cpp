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
#include <numeric>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define ll long long 
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)

int tracks[25];
int n,m,indices,min_space;
vi solution;

void backtrack_solution(int start, int current_ind,int current_sum){
    if(start>m) return;
    //cout << current_ind <<" ";
    if(current_sum<=n && (n-current_sum)<min_space)
        min_space= n-current_sum, indices= current_ind;
    backtrack_solution(start+1,current_ind|(1<<start),current_sum+tracks[start]);
    backtrack_solution(start+1,current_ind,current_sum);
}

void get_solution(){
    int i,j,k,end=(1<<m),l=0;
    int min_space=INT_MAX;
    repf(i,0,end){
        int sum=0;
        for(j=i,k=0;j;++k,j>>=1)
            if(j&1) sum+=tracks[k];
        if(sum<=n && (n-sum)<min_space)
            min_space= n-sum,l=i;
    }
    for(j=l,k=0;j;++k,j>>=1)
        if(j&1) solution.push_back(tracks[k]);
}

int main(){
    int i,j,k,l;
    while(sc(n)!=EOF){
        sc(m);
        repf(i,0,m) sc(tracks[i]);
        solution.erase(solution.begin(),solution.end());
        min_space=INT_MAX;
        backtrack_solution(0,0,0);
        for(j=indices,k=0,l=0;j;++k,j>>=1)
            if(j&1){
                l+=tracks[k];
                printf("%d ",tracks[k]);
            }
        //for(auto&val:solution)printf("%d ",val);
        printf("sum:%d\n",l);
    }
}
