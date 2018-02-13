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
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

typedef struct Description desc;
struct Description{
    double L;
    int G,Y,R;
    
    Description(double l, int g, int y, int r):L(l),G(g),Y(y),R(r){}
};

void print_speeds(vi& speeds){
    int i,j,k,len= speeds.size();
    for(i=0;i<len;){
        for(j=i+1;j<len && speeds[j-1]+1==speeds[j];++j);
        if(!i)
            printf("%d",speeds[i]);
        else printf(", %d",speeds[i]);
        if(j-i>1) printf("-%d",speeds[j-1]);
        i=j;
    }
    printf("\n");
}
int main(){
    int n,i,j,k=1,g,y,r;
    double dist;
    vector<desc> vect;
    vi speeds;
    while(sc(n),n!=-1){
        repf(i,0,n){
           scanf("%lf%d%d%d",&dist,&g,&y,&r);
           vect.push_back(Description(dist,g,y,r));  
        }
        for(i=30;i<=60;++i){
           for(j=0;j<n;++j){
                double seconds_exact= (vect[j].L*3600)/i;
                int seconds_floor= floor(seconds_exact);
                int acceptable_range= (vect[j].G+vect[j].Y);
                double arrived= (seconds_floor%(acceptable_range+vect[j].R))+(seconds_exact- seconds_floor);   
                if(arrived >acceptable_range)
                    break;
           } 
           if(j>=n)
               speeds.push_back(i);
        }
        printf("Case %d: ",k++);
        if(speeds.size()==0)
            printf("No acceptable speeds.\n");
        else print_speeds(speeds);
        vect.erase(vect.begin(),vect.end());
        speeds.erase(speeds.begin(),speeds.end());
    }
}
