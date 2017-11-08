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
#define SIZE 200005
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
        void reset(){
           fill(parent.begin(),parent.end(),0); 
           fill(rank.begin(),rank.end(),0);
           fill(set_size.begin(),set_size.end(),1);
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
struct comparator{
    bool operator()(char const* str1, char const* str2)const{
        return strcmp(str1,str2)<0;
    }
};
int main(){
    int i,j,k,l;
    int t,n,m;
    map<char*,int,comparator> name_map;
    char str1[25], str2[25];
    sc(t);
    UFDS ufds(SIZE);
    while(t--){
       sc(l);
       k=0;
       while(l--){
           scanf("%s %s",str1,str2);
           if(name_map.find(str1)==name_map.end())
                name_map[strdup(str1)]=++k;
           if(name_map.find(str2)==name_map.end())
                name_map[strdup(str2)]=++k;
           ufds.union_set(name_map[str1],name_map[str2]);
           printf("%d\n",ufds.find_set_size(name_map[str1]));
        } 
       ufds.reset();
       name_map.erase(name_map.begin(),name_map.end());
    }
}
