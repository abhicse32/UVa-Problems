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

int get_least_degree(vi &vect){
    int smallest_ind=1,i;
    repf(i,2,vect.size()){
        if(vect[i]<vect[smallest_ind])
            smallest_ind= i;
    }
    return smallest_ind;    
}

int main(){
    vi nbrs_count;
    int n,i,j,k,l;
    int nodes;
    sc(n);
    string str;
    while(n--){
        sc(nodes);
        nbrs_count.assign(nodes+1,0);
        repf(i,1,nodes+1){
            int space_count=1;
            char ch;
            while((ch=gc())!='\n')
                if(ch==' ')
                    ++space_count;
            nbrs_count[i]= space_count;      
        }
        int smallest_ind= get_least_degree(nbrs_count);
        printf("%d",smallest_ind);
        repf(i,smallest_ind+1,nbrs_count.size()){
            if(nbrs_count[i]==nbrs_count[smallest_ind])
                printf(" %d",i);
        }
        printf("\n");
        nbrs_count.erase(nbrs_count.begin(), nbrs_count.end());
    }
}
