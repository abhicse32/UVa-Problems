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
#include <set>
#include <cstring>
#include <cmath>
#include <queue>
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

vector<unsigned long long> expecting(10);
int main(){
    int m,i,j,k,l,n,t,case_=1;
    int packet_num,start,end;
    int max_buffer_size,current_size;
    vector<unsigned long long> current_state(10);
    while(scc(n,m),n){
        repf(i,1,n+1){
            sc(k);
            if(k<64) expecting[i]=(1<<k)-1;
            else expecting[i]=-1;
        } 
        current_state.assign(n+1,0);
        max_buffer_size=current_size=0;
        repf(i,0,m){
            scanf("%d%d%d",&packet_num,&start,&end);
            l=end-start+1;
            current_state[packet_num]|=(((1<<l)-1)<<(start-1));
            if(current_state[packet_num]!=expecting[packet_num]){
                current_size+=l;
                if(max_buffer_size<current_size)
                    max_buffer_size=current_size;
            }else{
                current_size-= __builtin_popcount(expecting[packet_num]);
                expecting[packet_num]=-1;
            }
        }
        printf("Case %d: %d\n\n",case_++,max_buffer_size);
    }
}
