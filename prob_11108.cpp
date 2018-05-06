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
#include <bitset>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int arr_map[130];

bool evaluate(string& str, int j){
    int times= (1<<(j+1)),i,k;
    bool b1,b2;
    reverse(str.begin(),str.end());
    repf(i,0,times){
        stack<bool> st;
        for(auto& c: str){
           if(c>'a')
              st.push((i>>arr_map[c])&1);
           else{
               b1= st.top(),st.pop();
               if(c=='N')
                  st.push(!b1); 
               else{
                   b2= st.top(),st.pop();
                   if(c=='K')
                       st.push(b1&b2);
                   else if(c=='A')
                       st.push(b1|b2);
                   else if(c=='C')
                       st.push((!b1)|b2);
                   else 
                       st.push(b1==b2);
                }
           } 
        }
        b1= st.top(),st.pop();
        if(!st.empty() || !b1) return false;
    }
    return true;
}

int main(){
    int i,j,k,l,m;
    string str;
    
    while(getline(cin,str),str!="0"){
        memset(arr_map,0,sizeof arr_map);
        j=0;
        for(auto& c:str)    
            if(c>'a') 
                arr_map[c]=1;

        for(i='p',j=0;i<='t';++i) 
            if(arr_map[i])
                arr_map[i]=j++;
        if(evaluate(str,j))
            printf("tautology\n");
        else printf("not\n");
    }
}
