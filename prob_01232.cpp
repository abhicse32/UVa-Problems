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
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d\n",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

#define MAX_SIZE 100000
class Seg_Tree{
    public:
        vi st;
        Seg_Tree(){
           st.assign(MAX_SIZE<<2,0); 
        }
        void reset();
        int over_lapped(int, int, int, int , int ,int);
};

void Seg_Tree::reset(){
   fill(st.begin(),st.end(),0); 
}

int Seg_Tree::over_lapped(int st_ind, int left, int right, int l, int r, int h){ 
    int diff= right- left;
    //printf("%d %d\n",left,right);
    if(diff>1 && st[st_ind]<= h){
        if(left>= l && right<= r && st[st_ind]!=0){
            st[st_ind]= h;
            //printf("%d %d %d\n",left,right,st[st_ind]);
            return right-left;
        }else{
            int mid= (left+right)>>1;
            int right_count=0, left_count=0;
            int st_l= st_ind<<1,st_r= st_l|1;
            if(r<=mid)
                left_count= over_lapped(st_l,left,mid,l,r,h);
            else if(l>=mid)
                right_count= over_lapped(st_r,mid,right,l,r,h);
            else{
                left_count= over_lapped(st_l,left,mid,l,r,h);
                right_count= over_lapped(st_r,mid,right,l,r,h);
            }
            st[st_ind]= (st[st_l]==st[st_r] && (st[st_ind]<=st[st_l]))?st[st_l]:0;
            return left_count+ right_count;
        }
        //printf("%d %d %d\n",left,right,st[st_ind]);

    }else if(diff==1 && left>= l && right<= r && st[st_ind]<=h){
        st[st_ind]= h;
        //printf("%d %d %d\n",left,right,st[st_ind]);
        return 1;     
    }
    return 0;
}

int main(){
    int i,j,k,c,n,l,r,h;
    sc(c);
    Seg_Tree *seg_tree=new Seg_Tree();
    while(c--){
        sc(n);
        k=0;
        while(n--){
            scanf("%d%d%d",&l,&r,&h);
            int x=seg_tree->over_lapped(1,1,MAX_SIZE,l,r,h);
           // printf("\n%d\n\n",x);
            k+=x;
        }
        printf("%d\n",k);
        seg_tree->reset();
    }  
    sc(i);  
}
