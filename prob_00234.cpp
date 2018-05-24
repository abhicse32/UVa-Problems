#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <vector>
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

typedef struct AlignmentPts{
    int point,imp;
    bool operator<(const AlignmentPts& pts)const{
       if(point<pts.point) return true;
       return false; 
    }
}alignment;

int duration[10],final_ordering[10];
alignment align_pts[8];
map<int,int> importance;
int min_err;

inline bool imp_comp(map<int,int>& imp_arr){
    auto iter1= importance.begin(), iter2= imp_arr.begin();
    for(;iter1!=importance.end() && iter1->second==iter2->second;++iter1,++iter2);
    return iter1==importance.end()?false:iter1->second > iter2->second;
}

void get_ordering(int p,int a){
    int temp_arr[10],i,j,k,ordering_error;
    min_err= INT_MAX;
    temp_arr[p]= INT_MAX;
    map<int,int> imp_arr;
    do{ 
        ordering_error=0;
        temp_arr[0]= duration[0];
        for(auto&val:importance)imp_arr[val.first]=0;
        repf(i,1,p)
            temp_arr[i]=duration[i]+temp_arr[i-1];
        repf(i,0,a){
            for(j=0;j<p && align_pts[i].point>temp_arr[j];++j);
            k=min(abs(align_pts[i].point - temp_arr[j]),
                  abs(align_pts[i].point - temp_arr[j-1]));
            ordering_error+=k;
            imp_arr[align_pts[i].imp]+=k;
        }
        if(imp_comp(imp_arr)){
            min_err= ordering_error;
            importance= imp_arr;
            repf(i,0,p) final_ordering[i]= duration[i];
        }
    }while(next_permutation(duration,duration+p));
}

int main(){
    int i,j,k,l,p,n,a;
    k=1;
    while(sc(p),p){
       repf(i,0,p)
           sc(duration[i]);
       sort(duration,duration+p);
       sc(a);
       memset(align_pts,0,sizeof align_pts);
       importance.erase(importance.begin(),importance.end());
       repf(i,0,a)
          scc(align_pts[i].imp,align_pts[i].point);
       sort(align_pts,align_pts+a); 
       repf(i,0,a) importance[align_pts[i].imp]=INT_MAX;

       get_ordering(p,a);

       printf("Data set %d\n  Order:",k++);
       repf(i,0,p) printf(" %d",final_ordering[i]);
       printf("\n  Error: %d\n",min_err);
       //for(auto&val:importance)
       //    cout << val.first <<" " << val.second <<endl;
    }
}
