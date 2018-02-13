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
#define pr(n) printf("%d ",n)
#define prr(n,m) printf("%d %d ",n,m);
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked
#define SIZE 100005

typedef struct Node node;
struct Node{
    int left_val, left_count;
    int right_val, right_count;
    int frequent_val, frequent_count;
};

class Seg_Tree{
    private:
        vi arr;
        vector<node> st;
        int n;
    public:
        Seg_Tree(){
            st.assign(SIZE<<2,0);
        }
 
        void reset(vi &a, int size){
            fill(st.begin(),st.end(),0);
            arr=a;
            n=size;
            build_tree(1,0,n-1);
        }

        void build_tree(int st_ind, int l, int r){
            if(l>=r){
                st[st_ind]=arr[l];
            }else{
               int left= st_ind<<1, right= left+1;
               int mid= (l+r)>>1;
               build_tree(left,l,mid);
               build_tree(right,mid+1,r);
               st[st_ind]= st[left]>st[right]?st[left]:st[right];
            }
        }

        int max_query(int p, int l, int r, int q_l, int q_r){
            if(q_l>r || q_r < l)
               return -1;
            else if(l>=q_l && r<=q_r)
               return st[p];
            else{
                int mid= (l+r)>>1;
                int left=p<<1, right=left|1;
                int first= max_query(left,l,mid,q_l,q_r);
                int second= max_query(right,mid+1,r,q_l,q_r);
                return first>second?first:second;  
            } 
        }

        void print_st(int p){
            if(st[p]!=0){
                printf("%d ",st[p]);
                print_st(p<<1);
                print_st((p<<1)|1);
            }
        }
};

int main(){
    int n,q,i,j,k;
    vi arr(SIZE);
    Seg_Tree seg_tree= Seg_Tree();
    while(scc(n,q),n){
        repf(i,0,n)sc(arr[i]);
        int count=1, last_entry=arr[0];
        arr[0]=count;
        repf(i,1,n){
            if(last_entry==arr[i])
                arr[i]=++count;
            else{
                last_entry=arr[i];
                arr[i]=count=1;
            }
        }
        seg_tree.reset(arr,n);
       // seg_tree.print_st(1);
        printf("\n");
        repf(i,0,q){
            scc(j,k);
            printf("%d %d",j,k);
            int max_count= seg_tree.max_query(1,0,n-1,j,k); 
            printf("%d\n",max_count);
        }
    }
}
