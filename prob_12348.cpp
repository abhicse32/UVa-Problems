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

bool check_for_condition(vvi& S,int n){
    int i,j,k,l;
    int arr[]={0,0};
    for(i=0;i<(1<<n);++i){
        repf(j,0,S.size()){
            arr[0]=arr[1]=0;
            for(auto& val: S[j])
                i&(1<<val)?++arr[1]:++arr[0];
            
            if(arr[0]!=1 && arr[1]!=1)
                break;
        }
        if(j>=S.size())
            return true;
    }
    return false;
}

int main(){
    int i,j,k,l,n,m;
    sc(k);
    char ch;
    vvi S; 
    while(k--){
        scc(n,m);
        S.erase(S.begin(),S.end());
        repf(i,0,m){
            vector<int> vect;
            l=0;
            while((ch=gc())=='\n');
            while(ch!='\n' && ch!=EOF){
                l=(l<<1)+(l<<3)+ch-'0',ch=gc();
                if(ch==' '){
                    vect.push_back(l-1);
                    l=0; ch= gc();
                }
            }
            vect.push_back(l-1);
            S.push_back(vect);
        }
        /*for(auto& val: S){
            for(auto& val1: val){
                 cout << val1 <<" ";
            }
            cout << endl;
        }*/
        check_for_condition(S,n)?printf("Y"):printf("N"); 
    }
}
