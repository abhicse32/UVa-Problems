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

typedef struct Locations{
    int a,b,c,d,e;
    Locations(int i,int j, int k, int l, int m):a(i),b(j),c(k),d(l),e(m){}
    Locations(){
        a=b=c=d=e=0;
    }
}office_location;

int main(){
    int i,j,k,l,m,n,t,a,b,c;
    long long distances[5][5][25];
    int city[5][5];
    sc(t);
    while(t--){
        memset(distances,0,sizeof distances);
        memset(city,0,sizeof city);
        sc(n);
        repf(i,0,n){
            scanf("%d%d%d",&j,&k,&l);
            city[j][k]= l;
        }
        
        repf(i,0,5){
            repf(j,0,5){
                if(city[i][j]){
                    repf(k,0,5)
                        repf(l,0,5)
                           distances[i][j][k*5+l] = (((long long)city[i][j])*(abs(i-k)+abs(j-l)));
                }
            }
        }

        long long min_dist=LONG_MAX;
        office_location location;
        repf(i,0,25)
            repf(j,i+1,25)
                repf(k,j+1,25)
                    repf(l,k+1,25)
                        repf(m,l+1,25){
                            long long dist_sum=0;
                            repf(a,0,5)
                                repf(b,0,5){
                                    long long* ptr= distances[a][b];
                                    dist_sum+=min(ptr[i],min(ptr[j],min(ptr[k],min(ptr[l],ptr[m]))));
                                }
                            if(dist_sum<min_dist){
                                min_dist= dist_sum;
                                location= office_location(i,j,k,l,m);
                            }
                        }
        printf("%d %d %d %d %d\n",location.a,location.b,location.c,location.d,location.e);
    }
}
