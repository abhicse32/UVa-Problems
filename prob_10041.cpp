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
    int i,smallest,j,largest,l,n,t,temp_sum;
    int sum;
    int arr[505];
    sc(t);
    while(t--){
        sc(n);
        repf(i,0,n)
            sc(arr[i]);
        sort(arr,arr+n);
        for(sum=0,i=1,smallest=arr[0];i<n;++i)
            sum+=(arr[i]-smallest);
        for(j=1;(temp_sum=sum+(arr[j]-arr[j-1])*((j<<1)-n))<=sum && temp_sum>=0;++j){
            if(sum>temp_sum) sum=temp_sum;
        }
        
        cout << sum <<endl;
    }
}
