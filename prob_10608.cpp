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
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked
#define gc getchar_unlocked

class UFDS{	
    vi parent,rank;
    int num_sets; // to answer queries that ask for the numbr of different sets
    vi set_size;  // used to store the size of the set element i belongs to
    public:
    	UFDS(int n){
	    parent.assign(n+1,0);
            rank.assign(n+1,0);
            set_size.assign(n+1,1);
	    for(int i=0;i<=n;++i)
		parent[i]=i;
	    num_sets= n;
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
                set_size[x] = set_size[y] =(set_size[x]+set_size[y]);
            }
        }
        
        int find_set(int i){
            return (i==parent[i]?i:(parent[i]=find_set(parent[i])));
        }

        int find_set_size(int i){
            return set_size[find_set(i)];
        }

        int num_disjoint_sets(){
           return num_sets; 
        }   

};
int main(){
    int i,j,k,m,n;
    int t;
    sc(t);
    while(t--){
        scc(n,m);
        UFDS ufds(n);
        repf(i,0,m){
            scc(j,k);
            ufds.union_set(j,k);
        }
        int max_size=0;
        repf(i,0,n+1){
           if((j=ufds.find_set_size(i))>max_size)
              max_size= j;
        }
        printf("%d\n",max_size);
    }
}
