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
#define MAX 1000000
typedef struct Prices{
    int a,b,c,d;
    Prices(int i,int j, int k, int l):a(i),b(j),c(k),d(l){}
    bool operator<(const Prices& p) const{
        return tie(a,b,c,d) < tie(p.a,p.b,p.c,p.d);
    }
}prices;

int main(){
    int i,j,k,l,m,n;
    vector<prices> vect;
    for(i=1;i<=500;++i){
        for(j=i;j<=(2000-i)/3;++j){
            for(k=j;k<=(2000-j-i)/2;++k){
                long long product= ((long long)i)*j*k;
                long long sum= i+j+k;
                if(product!=MAX){
                    l= (sum*MAX)/(product-MAX);
                    sum+=l;

                if(l>=k && sum<=2000 && sum==(l*product)/MAX)
                    vect.push_back(prices(i,j,k,l));
                }
            }
        }
    } 
    sort(vect.begin(),vect.end());
    for(auto& price: vect)
        printf("%d.%02d %d.%02d %d.%02d %d.%02d\n",price.a/100,price.a%100,price.b/100,price.b%100,
                price.c/100,price.c%100,price.d/100,price.d%100);
}
