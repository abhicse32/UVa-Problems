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
    int i,j,k,f,r,t;
    int f_arr[105],r_arr[105];
    double arr[105];
    while(sc(f),f){
        sc(r);
        repf(i,0,f) sc(f_arr[i]);
        repf(i,0,r) sc(r_arr[i]); 
        
        repf(i,0,r){
            double d= double(r_arr[i]);
            repf(j,0,f)
                arr[i*f+j]= d/f_arr[j];
        }
        sort(arr,arr+f*r);
        double d= arr[1]/arr[0],d1;
        repf(i,1,f*r){
            if((d1=arr[i]/arr[i-1])>d)
                d= d1;
        }
        printf("%.2lf\n",d);
    }
}
