#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define repf(i,a,b) for(i=a;i<b;++i)
#define repb(i,a,b) for(i=a;i>b;--i)
#define gc getchar_unlocked

class UFDS{
    vi rank, parent;
    public:
    	UFDS(int n){
	    parent.assign(n+1,0);
            rank.assign(n+1,0);
	    for(int i=0;i<=n;++i)
		parent[i]=i;
        }
     
        bool is_same_set(int i, int j){
            return find_set(i) == find_set(j);
        }
        
        void union_set(int i, int  j){
            int x= find_set(i), y= find_set(j);
            if(x!=y){
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
};

int main(){
    int t,i,j,k;
    int n;
    sc(t);
    while(t--){
        sc(n);
        UFDS ufds(n);
        int success=0,unsuccess=0;
        string str;
        char ch;
        int computer1, computer2;
        while(getline(cin,str),str!=""){ 
            stringstream stream(str);
            stream >> ch >> computer1 >> computer2;
            if(ch=='c')
                ufds.union_set(computer1, computer2);
            else{
                if(ufds.is_same_set(computer1,computer2))
                    ++success;
                else ++unsuccess;
            }
        }
        if(t)
            printf("%d,%d\n\n",success,unsuccess);
        else printf("%d,%d\n",success,unsuccess);
    }
}
