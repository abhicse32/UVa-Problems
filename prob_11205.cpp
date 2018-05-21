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

vi nums;
void get_input(int n,int m){
    string str;
    int k,i;
    while(n--){
        getline(cin>>ws,str);
        //str.erase(remove(str.begin(),str.end(),' '),str.end()); // alternative
        for(i=0,k=0;i<str.size();i+=2)
            k=(k<<1)|(str[i]-'0');
        nums.push_back(k);
    }
}
    
int get_min_bits(int m,int n){
    vi vect(n);
    int min_bits= m,i,j,k;
    for(i=0;i<(1<<m);++i){
        repf(j,0,n) vect[j]=nums[j]&i;
        sort(vect.begin(),vect.end());
        for(k=1;k<n;++k)
            if(vect[k]==vect[k-1]) break;
        int local_bits= __builtin_popcount (i);
        if(k>=n && min_bits>local_bits)
            min_bits= local_bits;
    }
    return min_bits;
}

int main(){
    int i,j,k,l,t,n,m;
    string str;
    sc(t);
    while(t--){
        sc(m); sc(n);
        nums.erase(nums.begin(),nums.end());
        get_input(n,m);
        cout << get_min_bits(m,n)<<endl;
    }
}
