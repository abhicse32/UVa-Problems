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

int arr[6];
vector<char> used_ops(6),available_ops{'+','-','*'};
bool eval_exp(int l){
    int i,j,k;
    if(l==4){
        sort(arr,arr+5);
        do{ 
            j=arr[0];
            repf(i,0,l){
                switch(used_ops[i]){
                    case '+': j = j + arr[i+1]; break;
                    case '-': j = j - arr[i+1]; break;
                    case '*': j = j * arr[i+1]; break;
                    default: break;
                }
            }
            if(j==23) return true; 
        }while(next_permutation(arr,arr+5));
   }else{
      repf(i,0,3){
         used_ops[l]= available_ops[i];
         if(eval_exp(l+1)) return true;
      } 
   }
   return false; 
}

int main(){
    int i,j,k;
    while(cin >> arr[0] >> arr[1] >> arr[2]>> arr[3] >> arr[4] 
            && (arr[0]|arr[1]|arr[2]|arr[3]|arr[4])){
        sort(arr,arr+5);
        if(eval_exp(0))
            cout <<"Possible\n";
        else cout << "Impossible\n";
    }
}
