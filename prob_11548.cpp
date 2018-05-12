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
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int dp[80][80];
int get_max_candies(string& str1, string& str2){
    int max_=0,i,j,k;
    int len1= str1.size(), len2= str2.size();
    for(i=0;i<=len1;++i) dp[0][i]=0;
    for(i=0;i<=len2;++i) dp[i][0]= 0;
    for(i=1;i<=len2;++i){
        for(j=1;j<=len1;++j){
           dp[i][j]= dp[i-1][j-1];
           if(str2[i-1]==str1[j-1]){
              ++dp[i][j];
              if(dp[i][j]> max_)
                  max_= dp[i][j];
           }
        }
    }
    return max_;
}

int main(){
    int i,j,k,l,t,n,max_;
    string str;
    sc(t);
    vector<string> vect;
    while(t--){
        sc(n);
        repf(i,0,n)
            getline(cin,str),
            vect.push_back(str);
        max_=0;
        for(i=0;i<vect.size();++i){
            for(j=i+1;j<vect.size();++j){
                l= get_max_candies(vect[i],vect[j]);
                if(max_< l) max_ = l;
            }
        }
       printf("%d\n",max_); 
       vect.erase(vect.begin(),vect.end());
    }
}
