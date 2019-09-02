#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define ll long long 
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
char buffer[20];
void print_bit_strings(int n,int h){
    int i,j,k;
    repf(i,0,(1<<n)){
        if(__builtin_popcount(i)==h){
            for(j=i,k=n-1;k>=0;j>>=1,--k) 
                buffer[k]='0'+(j&1);
            buffer[n]='\0';
            printf("%s\n",buffer);
        } 
    }
}
int main(){
    int i,j,k,t,n,h;
    sc(t);
    while(t--){
        scc(n,h);
        print_bit_strings(n,h);
        if(t)printf("\n");
    }
}
