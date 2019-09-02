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
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define ll long long 
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)

vector<string> dictionary(105);
vector<string> replacement(105);
string rule;
int n,m;
vector<string> numbers(10);

void generate_comb(int index){
    if(index>=rule.size()){
        for(int i=0;i<rule.size();++i)
            cout << replacement[i];
        printf("\n");
    }else if(rule[index]=='#')
        for(int j=0;j<n;++j)
            replacement[index]=dictionary[j],
            generate_comb(index+1);
    else if(rule[index]=='0')
        for(int j=0;j<10;++j)
            replacement[index]=numbers[j],
            generate_comb(index+1); 
}

int main(){
    int i,j,k,l;
    string str;
    //ios_base::sync_with_stdio(false);
    i=0;
    //for_each(numbers.begin(),numbers.end(),[&](auto& iter){iter=to_string(i);++i;});
    for(auto&val:numbers) val=to_string(i++);
    while(cin >> n){
        repf(i,0,n) cin >> dictionary[i];
        sc(m);
        printf("--\n");
        while(m--){
            cin >> rule;
            generate_comb(0);
        }
    }
}
