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
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked
#define SIZE 130
bool visited[SIZE];
int years, awake_areas;

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
            }
        }
        
        int find_set(int i){
            return (i==parent[i]?i:(parent[i]=find_set(parent[i])));
        }

        int num_disjoint_sets(){
           return num_sets; 
        }   
};

int count_active_areas(UFDS& ufds, vector<char>& nbrs, char active_area){
    int active_count=0;
    for(auto&val: nbrs)
        if(ufds.is_same_set(active_area,val))
            ++active_count;
    return active_count;
}

void bfs(vector<vector<char> >&ad_list,vector<char> vect,UFDS& ufds){
    if(vect.empty())
        return;
    vector<char> temp;
    for(auto& val: vect){
        vector<char> nbrs= ad_list[val];
        for(auto& nbr:nbrs){
            if(!visited[nbr] && count_active_areas(ufds,ad_list[nbr],val)>2){
               temp.push_back(nbr);
               visited[nbr]= true; 
            }
        } 
    }
    if(!temp.empty()){
        ++years;
        awake_areas+=temp.size();
        //printf("%d\n",awake_areas);
        for(auto&val:temp)
            ufds.union_set(val,vect[0]);
    }
    bfs(ad_list,temp,ufds);
}

int main(){
    int t,i,j,k,connections;
    int slept_areas;
    string str;
    while(sc(slept_areas)!=EOF){
        vector<vector<char> > ad_list(SIZE);
        sc(connections);
        getline(cin,str);
        UFDS ufds(SIZE);  
        vector<char> vect;
        memset(visited,false,sizeof(visited));
        repf(i,0,3)
            ufds.union_set(str[0],str[i]),
            vect.push_back(str[i]),
            visited[str[i]]=true; 

        repf(i,0,connections){
           getline(cin,str);
           ad_list[str[0]].push_back(str[1]);
           ad_list[str[1]].push_back(str[0]); 
        }
        years=0, awake_areas=3;
        bfs(ad_list,vect,ufds);
        if(awake_areas!=slept_areas){
            printf("THIS BRAIN NEVER WAKES UP\n");
        }else
            printf("WAKE UP IN, %d, YEARS\n",years);
    }
}
