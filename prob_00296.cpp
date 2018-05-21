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
#define ll long long 
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

typedef struct Guess{
    string guess;
    int right,wrong;
}guess;

int get_right_count(string& str1, string &str2){
    int count=0;
    for(int i=0;i<4;++i)
        if(str1[i]==str2[i]) 
            ++count,str2[i]=str1[i]='a'+i;
    return count;
}

int get_wrong_count(string &str1, string str2){
    int count=0;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            if(i!=j && str1[i]==str2[j]){
                str2[j]='a';++count; break;
            }
    return count;
}

vector<string> get_codes(vector<guess>& v_guess){
    int i,j,k,l;
    vector<string> res_vect;
    repf(i,1,10000){
        string num_str= to_string(i);
        num_str=string(4-num_str.size(),'0')+num_str;
        repf(j,0,v_guess.size()){
            string str2= v_guess[j].guess,str1=num_str;
            int right_c= get_right_count(str1,str2);
            int wrong_c= get_wrong_count(str1,str2);
            if(right_c!=v_guess[j].right || wrong_c!= v_guess[j].wrong)     
                break;
        }
        if(j>=v_guess.size())
            res_vect.push_back(num_str);      
    }    
    return res_vect;
}

int main(){
    int i,j,k,l,m,n,t;
    char ch;
    sc(t);
    vector<guess> vect;
    while(t--){
        sc(n);
        vect.erase(vect.begin(),vect.end());
        repf(i,0,n){
            guess g;
            cin >> g.guess >> g.right >>ch >> g.wrong;
            vect.push_back(g);
        }
        vector<string> res_vect= get_codes(vect);    
        if(res_vect.size()==0)
            printf("impossible\n");
        else if(res_vect.size()==1)
            cout << res_vect[0] <<endl;
        else printf("indeterminate\n");
    }
}
