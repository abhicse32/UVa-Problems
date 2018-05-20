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
#define vs vector<string>
#define ll long long 
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int main(){
    int t,i,j,k,l,m,n;
    sc(t);
    vs vect;
    string str;
    repf(m,1,t+1){
        sc(n);
        vect.erase(vect.begin(),vect.end());
        repf(j,0,n)
            cin >> str,
            vect.push_back(str);
        sort(vect.begin(),vect.end());
        //for(auto& val: vect)
        //    cout << val << endl;
        printf("Case %d:",m);
        int min_cost=INT_MAX;
        do{
            str= vect[0];
            for(i=1;i<vect.size();++i){
                string str2= vect[i];
                for(l=0;l<str.size();++l){
                    for(j=l,k=0;j<str.size() && k<str2.size() && str[j]==str2[k];++j,++k);
                    if(j>=str.size()) break;
                }
                str+=str2.substr(k);
            }
            //cout << str <<" " <<str.size() <<endl;
            if(str.size()<min_cost)
                min_cost= str.size();
        }while(next_permutation(vect.begin(),vect.end()));
        printf(" %d\n",min_cost);
    }
}
