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

typedef struct Forwarding{
    int start,end,destination;
    Forwarding(int s,int d, int des):start(s),end(d),destination(des){}    
}forwarding;
map<int,vector<forwarding> > database;

int get_ext(int time,int src,int ext){
    if(ext==src) return 9999; 
    for(auto&val:database[src])
        if(time>= val.start && time<= val.end)
            return get_ext(time,val.destination,ext);
    return src;
}

int aux(int time, int source){
    for(auto&val: database[source]){
        if(time>=val.start && time<= val.end)
            return get_ext(time,val.destination,source);
    }
    return source;    
}

int main(){
    int i,j,k,l,ext,source,x,duration,destination,t;
    sc(t);
    printf("CALL FORWARDING OUTPUT\n");
    repf(l,1,t+1){
        database.erase(database.begin(),database.end());        
        while(sc(source),source){
            scanf("%d%d%d",&x,&duration,&destination);
            if(database.find(source)==database.end())
                database[source]= vector<forwarding>{};
            database[source].push_back(forwarding(x,(x+duration)%8784,destination));
        }
        printf("SYSTEM %d\n",l);
        while(sc(x),x!=9000){
            sc(ext);
            int dest= aux(x,ext);
            printf("AT %04d CALL TO %04d RINGS %04d\n",x,ext,dest); 
        }
    }
    printf("END OF OUTPUT\n");
}
