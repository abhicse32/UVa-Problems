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
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int main(){
    int i,j,k,l,m,n,t,a,b;
    int ticket[6][6],
        prizes[5];
    int total_win=0;
    sc(t);
    int ball_map[100];
    repf(i,1,t+1){
        scc(n,l);
        fill(ball_map,ball_map+100,255);
        repf(j,1,n+1) sc(k),ball_map[k]=j;
        repf(j,0,4) sc(prizes[j]);
        printf("Case %d:\n",i);
        repf(m,0,l){
            bool flag=true;
            total_win=0;
            repf(j,0,5){
                repf(k,0,5){
                    sc(ticket[j][k]);
                    if(ball_map[ticket[j][k]]==255)
                        flag= false;     
                }
            }
            if(flag) total_win+=prizes[3]; 
            if(ball_map[ticket[0][0]]<=35 && ball_map[ticket[4][4]]<=35 &&
                ball_map[ticket[4][0]]<=35 && ball_map[ticket[0][4]]<=35)
                total_win+=prizes[0];
            repf(a,0,5) if(ball_map[ticket[2][a]]>40) break;
            if(a>=5) total_win+=prizes[1];
            repf(a,0,5) if(ball_map[ticket[a][a]]>45) break;
            if(a>=5){
                repf(a,0,5) if(ball_map[ticket[4-a][a]]>45) break;
                if(a>=5) total_win+=prizes[2];
            } 
            printf("%d\n",total_win);     
        }
        if(i<t) printf("\n");
    }
}
