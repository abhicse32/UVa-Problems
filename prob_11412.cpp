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
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked
vector<string> vect;
string str1,str2;
int gn1,gn2,gn3,gn4;

void get_distinct_length_4_strings(char colors[]){
    for(int i=0;i<6;++i)
        for(int j=i+1;j<6;++j)
            for(int k=j+1;k<6;++k)
                for(int l=k+1;l<6;++l)
                    vect.push_back(string{colors[i],colors[j],colors[k],colors[l]});                 
}
int get_same_pos_count(string& str1, string& str2){
    int count=0;
    for(auto iter1= str1.begin(),iter2= str2.begin();iter1!=str1.end();++iter1,++iter2)
        if(*iter1==*iter2) ++count;
    return count;
}

int get_diff_pos_count(string& str1,string& str2){
    int count=0;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j)
            if(i!=j && str1[i]==str2[j]){
                ++count;
                break;
            }
    }
    return count;
}

bool check_possibility(){
    for(auto& val: vect){
        string hole_colors= val;
        do{
            int n1= get_same_pos_count(hole_colors,str1);
            int n2= get_diff_pos_count(hole_colors,str1);
            int n3= get_same_pos_count(hole_colors,str2);
            int n4= get_diff_pos_count(hole_colors,str2);
            if(n1==gn1 && n2==gn2 && n3==gn3 && n4==gn4)    
                return true;
        }while(next_permutation(hole_colors.begin(),hole_colors.end()));
    }
    return false;
}
int main(){
    int i,j,k,l,m,t;
    char colors[]={'R','G','B','Y','O','V'};
    sort(colors,colors+6);
    get_distinct_length_4_strings(colors);
    sc(t);
    while(t--){
        cin >> ws >> str1 >> gn1 >>gn2;
        cin >> ws >> str2 >> gn3 >>gn4;
        if(check_possibility())
            printf("Possible\n");
        else printf("Cheat\n");
    }
}
