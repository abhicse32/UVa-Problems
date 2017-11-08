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
#include <queue>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d\n",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked
#define SIZE 10005
vi given_owed;

class UFDS{	
    vi parent,rank;
    int num_sets; // to answer queries that ask for the numbr of different sets
    public:
    	UFDS(int n){
	    parent.assign(n+1,0);
            rank.assign(n+1,0);
	    for(int i=0;i<=n;++i)
		parent[i]=i;
	    num_sets= n;
        }
        void reset(){
           fill(parent.begin(),parent.end(),0); 
           fill(rank.begin(),rank.end(),0);
            for(int i=0;i<parent.size();++i){
                parent[i]=i;
            }
            num_sets=parent.size()-1;
        }

        bool is_same_set(int i, int j){
            return find_set(i) == find_set(j);
        }
        
        void union_set(int i, int  j){
            int x= find_set(i), y= find_set(j);
            if(x!=y){
               --num_sets;
               if(rank[x]==rank[y]){
                    parent[x]= y;
                   ++rank[y];
                }else{
                   if(rank[x]>rank[y])
                       parent[y]= x;
                   else parent[x]= y;
                }
                given_owed[find_set(x)]=given_owed[x]+given_owed[y];
            }
        }
        
        int find_set(int i){
            return (i==parent[i]?i:(parent[i]=find_set(parent[i])));
        }

        int num_disjoint_sets(){
           return num_sets; 
        }   
};
int main(){
    int t,i,j,k,m,n;
    sc(t);
    UFDS ufds(SIZE);
    given_owed.assign(SIZE,0);
    while(t--){
        scc(n,m);
        repf(i,0,n)
            sc(given_owed[i]);

        repf(i,0,m){
            scc(j,k);
            ufds.union_set(j,k);
        }
        bool flag=true;
        repf(i,0,n){
            if(given_owed[ufds.find_set(i)]!=0){
                flag=false;
                break;
            }
        }
        if(flag)
            printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
        ufds.reset();
        fill(given_owed.begin(),given_owed.end(),0);
    }
}
