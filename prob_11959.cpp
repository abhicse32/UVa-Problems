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
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

bool check_config(string& str1, string& str2){
    int i,j;
    char ch,ch1;
    string str3=str1;
    swap(str3[1],str3[0]);
    swap(str3[2],str3[4]);

    for(i=0;i<4;++i){ 
        for(ch=str1[2],ch1=str3[2],j=2;j<5;str1[j]=str1[j+1],str3[j]= str3[j+1],++j);
        str1[j]=ch;
        str3[j]=ch1;
        if(str1==str2 || str3==str2)
          return true;
       //cout << str1 <<" "<< str3 <<endl; 
    }
    return false;    
}

void swap_(string&str,int a, int b, int c, int d){
    char ch= str[a];
    str[a]= str[c];
    str[c]= str[b];
    str[b]= str[d];
    str[d]= ch;
}

int main(){
    int i,j,k,l,t;
    string str1,str2;
    char ch;
    sc(t);
    while(t--){
        cin >> str1 >> str2;
        //cout << str1 <<" " << str2 <<endl;
        if(!check_config(str1,str2) && (swap_(str1,0,1,2,4), !check_config(str1,str2)) 
                        && (swap_(str1,0,1,3,5), !check_config(str1,str2)))
                    printf("Not Equal\n");
                
        else printf("Equal\n");    
        
    }
}
