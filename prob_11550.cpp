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

int main(){
    int t,n,m,i,j,k;
    vii edge_list;
    sc(t);
    while(t--){
        scanf("%d%d",&n,&m);
        edge_list.assign(m+1,pair<int,int>{0,0});
        bool three_incident_flag=false;
        repf(i,1,n+1){
            repf(j,1,m+1){
               sc(k);
               if(k){
                   if(!edge_list[j].first)
                       edge_list[j].first=i;
                   else if(!edge_list[j].second)
                       edge_list[j].second= i;
                   else
                       three_incident_flag=true;
               }
            }
        }
        map<pair<int,int>,bool> edge_map;
        if(!three_incident_flag){
            repf(i,1,m+1){
                if(edge_list[i].first*edge_list[i].second==0){
                    three_incident_flag=true;
                    break;
                }else if(edge_map.find(edge_list[i])==edge_map.end())
                    edge_map[edge_list[i]]=true;
                else{
                    three_incident_flag=true;
                    break;
                }
            }
            if(three_incident_flag)
                printf("No\n");
            else printf("Yes\n");
        }else printf("No\n");
    }
}
