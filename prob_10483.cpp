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

struct Triples{
    int a, b, c;
    int product_sum;
    Triples(int a_, int b_, int c_,int p):a(a_),b(b_),c(c_),product_sum(p){};
    bool operator<(const Triples& tr) const{
        if(product_sum<tr.product_sum) return true;
        else if(product_sum==tr.product_sum){
           if (a<tr.a) return true;
           else if(a==tr.a && b<tr.b) return true;
        }
        return false;
    }   
};

int main(){
    int i1,i2,fr1,fr2;
    int i,j,k,l,m;
    scanf("%d.%d %d.%d",&i1,&fr1,&i2,&fr2);
    i1=i1*100+fr1;
    i2=i2*100+fr2;
    vector<struct Triples> vect;
    for(i=1;i<=i2/3;++i){
        for(j=i;j<=(i2-i)/2;++j){
            int product=j*i;
            int sum= i+j;
            if(product>10000){
                k= (sum*10000)/(product-10000);
                sum+=k;
                if(k>=j && sum>=i1 && sum<=i2 && i+j+k==((long long)product*k)/10000)
                    vect.push_back(Triples(i,j,k,sum));
            }
        }
    }
    sort(vect.begin(),vect.end());
    for(auto& val: vect){
        printf("%d.%02d = ",val.product_sum/100,val.product_sum%100);
        i=val.a/100,j=val.a%100,k=val.b/100,l=val.b%100,
        i1= val.c/100,i2=val.c%100;
        printf("%d.%02d + %d.%02d + %d.%02d = %d.%02d * %d.%02d * %d.%02d\n",i,j,k,l,i1,i2,i,j,k,l,i1,i2); 
    }
}
