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
#include <queue>
#include <iomanip>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d\n",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int main(){
    int i,j,k,N;
    j=0;
    while(sc(N),N){
       bool flag=false;
       if(j)
           printf("\n");
       ++j;
       for(int fghij=1234;fghij<=98761/N;++fghij){
           int abcde= fghij*N;
           int tmp=fghij, used= (fghij<10000);
           while(tmp){used|=(1<<(tmp%10));tmp/=10;}
           tmp=abcde;
           while(tmp){used|=(1<<(tmp%10));tmp/=10;}
           if(used==((1<<10)-1)){
                flag=true;
                cout << setfill('0') << setw(5) << abcde <<" / " << setfill('0') << setw(5) << fghij <<" = " << N <<endl;
           }
       }
      if(!flag)
          cout <<"There are no solutions for " << N <<"." <<endl; 
    }
}
