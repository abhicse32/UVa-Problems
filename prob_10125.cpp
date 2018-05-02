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

long long val2;
long long arr[1005];
int binary_search_k(int l, int r, long long val1){
    if(l>=r) return l;
    int mid= (l+r)>>1;
    if(arr[mid]+val1>val2)
        return binary_search_k(l,mid-1,val1);
    return binary_search_k(mid+1,r,val1);
}

int binary_search_l(int l, int r,long long val1){
    if(l>=r) return l;
    int mid= (l+r)>>1;
    if(arr[mid]+val1==val2) return mid;
    else if(arr[mid]+val1>val2)
        return binary_search_l(l,mid-1,val1);
    return binary_search_l(mid+1,r,val1);    
}

void find_d(long long arr[], int n){
    int i,j,k,l;
    long long b,val1;    
    for(i=n-1;i>=0;--i){
        val2= arr[i];
        for(j=i-1;j>=0;--j){
            k= binary_search_k(0,n-1,arr[j]);
            for(;k>=0;--k){
                if(k==i or k==j) continue;
                val1= arr[j]+arr[k];
                l= binary_search_l(0,n-1,val1);
                //printf("%lld:  %lld %lld %lld\n",val2,arr[j],arr[k],arr[l]);
                if(l!=k && l!=j && l!=i && val1+arr[l]==arr[i]){
                    printf("%lld\n",arr[i]);
                    return;
                }
            }
        }
    }
    printf("no solution\n");
}

int main(){
    int i,n;
    while(sc(n),n){
        repf(i,0,n) scanf("%lld",&arr[i]);
        sort(arr,arr+n);
        //repf(i,0,n) printf("%lld ",arr[i]);
        //printf("\n");
        find_d(arr,n);
    }  
}
