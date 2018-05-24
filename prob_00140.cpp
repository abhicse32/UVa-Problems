#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <climits>
#include <bitset>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

bool nodes[100];
int indices[100];
map<char,vector<char> >ad_matrix;

string get_ordering(){
    string str="";
    for(int i=65;i<92;++i)
        if(nodes[i]) str+=char(i);
    return str;
}

void print_graph(){
    for(auto&keys: ad_matrix){
        cout << keys.first<<":";
        for(auto&nbr:keys.second)
            cout << nbr;
        cout <<endl;
    }
}

void extract_graph(string str){
    stringstream stream(str);
    ad_matrix.erase(ad_matrix.begin(),ad_matrix.end());
    memset(nodes,false,sizeof nodes);

    while(stream.good()){
        string str2,nbrs;
        getline(stream,str2,';');
        char ch=str2[0];
        if(ad_matrix.find(ch)==ad_matrix.end())
            ad_matrix[ch]= vector<char>{};
        nodes[ch]=true;
        for(int j=2;j<str2.size();++j)
            ad_matrix[ch].push_back(str2[j]),
            nodes[str2[j]]=true;
    }
}
string min_ordering;

int get_min_bandwidth(){
    int global_min= INT_MAX,i,j,l;
    string ordering= get_ordering();
    do{
        repf(i,0,ordering.size())    
            indices[ordering[i]]=i;

        int ordering_max=INT_MIN;
        for(auto&key:ad_matrix){
            int local_max=INT_MIN;
            for(auto&nbr:key.second)
                if((l=abs(indices[nbr]-indices[key.first]))>local_max)
                    local_max=l;
            if(local_max>ordering_max)
                ordering_max= local_max;
        }
        if(global_min>ordering_max){
            global_min= ordering_max;
            min_ordering= ordering;
        }
        memset(indices,0,sizeof indices);   
    }while(next_permutation(ordering.begin(),ordering.end()));
    return global_min;
}

int main(){
    int i,j,k,l;
    string str;
    while(getline(cin,str),str!="#"){
        str.erase(remove(str.begin(),str.end(),' '),str.end());
        extract_graph(str);
        int global_min= get_min_bandwidth();
        for(auto&c:min_ordering)
            printf("%c ",c);
        printf("-> %d\n",global_min);
    } 
}
