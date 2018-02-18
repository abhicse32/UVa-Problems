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
#include <cstring>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

void parse(char str[40], char cities[105][27],int index){
    char* temp= strtok(str,",");
    while(temp){
        cities[index][temp[0]-'a']=temp[2];
        temp= strtok(NULL,","); 
    }
}
int main(){
    int i=0,j,k,l;
    char cities[105][27],temp_str[40];
    while(scanf("%s",temp_str),temp_str[0]!='#'){
        parse(temp_str,cities,i++);
        while(scanf("%s",temp_str),temp_str[0]!='e')
            parse(temp_str,cities,i++);
        l=-1;
        int smallest=INT_MAX;
        string str="roygb";
        repf(j,0,i){
            int changes=0;
            repf(k,0,i){
                for(auto c: str){
                   if(cities[j][c-'a']!=cities[k][c-'a'])
                      ++changes; 
                } 
            }
            if(changes< smallest)
                smallest=changes,l=j+1;
        }
        printf("%d\n",l);
        i=0;
    }
}
