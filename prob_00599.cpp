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
#define vii vector<vi>
#define sc(n) scanf("%d\n",&n)
#define repf(i,a,b) for(i=a,i<b;++i)
#define repb(i,a,b) for(i=a;i>b;--i)

int dfs(map<char, vector<char> >&ad_list, map<char,bool>& visited, char src_node){
    int n=1;
    for(auto& nbr: ad_list[src_node]){
        if(!visited[nbr]){
            visited[nbr]= true;
            n+=dfs(ad_list,visited,nbr);
        }
    }
    return n;
}

void print_adlist(map<char, vector<char> >& ad_list){
    for(auto& node: ad_list){
        cout << node.first <<":";
        for(auto& nbr: node.second)
            cout << nbr <<" ";
        cout << endl;
    }
}
int main(){
    int i,j,k;
    int n;
    char ch1,v1,v2,ch2;
    sc(n);
    map<char,vector<char> > ad_list;
    map<char,bool> visited;
    string str;
    while(n--){
        while(getline(cin,str), str[0]!='*'){
            v1=str[1]; v2= str[3];
            if(ad_list.find(v1)==ad_list.end())
                ad_list[v1]= vector<char>{};
            ad_list[v1].push_back(v2);
            if(ad_list.find(v2)==ad_list.end())
                ad_list[v2]= vector<char>{};
            ad_list[v2].push_back(v1);
        }
        getline(cin,str);
        for(int i=0;i<str.size();i+=2){
            if(ad_list.find(str[i])==ad_list.end())
                ad_list[str[i]]= vector<char>{};
            visited[str[i]]= false;
        }
        
        //print_adlist(ad_list); 
        int tree_count=0, acorn_count=0;
        for(auto& iter: visited){
           if(!iter.second){
               int node_count=dfs(ad_list,visited,iter.first);
              if(node_count==1)
                 acorn_count++;
              else tree_count++; 
           } 
        }
        printf("There are %d tree(s) and %d acorn(s).\n",tree_count, acorn_count); 
        ad_list.erase(ad_list.begin(),ad_list.end());
        visited.erase(visited.begin(), visited.end());
    }
}
