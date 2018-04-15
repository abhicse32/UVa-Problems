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

int get_hash(string& str){
    int hash=0;
    for(auto& c:str)
        hash=(hash<<5)+c-'a'+1;
    return hash;
}

int main(){
    string str;
    int i,j,k,l,n,C;
    int w_i[100],remember[100];
    bool arr[100];

    while(getline(cin,str)){  
        n=0;
        stringstream stream(str);
        for(string temp;stream >>temp;)
            w_i[n++]=get_hash(temp);
        sort(w_i,w_i+n);
        memset(arr,-1,sizeof(int)*n);
        i=0;
        for(C=w_i[i];i!=n;){
            memset(arr,0,sizeof(arr));
            memset(remember,0,sizeof(remember));
            for(i=0;i<n;++i){
                int mod_i=(C/w_i[i])%n;
                if(arr[mod_i]){
                    C=min((C/w_i[i]+1)*w_i[i],(C/remember[mod_i]+1)*remember[mod_i]);
                    break;
                }else{
                    arr[mod_i]=1;
                    remember[mod_i]= w_i[i];
                }
            }
        }
        cout << str <<endl;
        printf("%d\n\n",C);
    }
}
