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
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

int main(){
    int i,j,k,l,m,n;
    vector<string> vect_str;
    map<pair<int,int>, int> count_map;

    while(sc(n)!=EOF){
        string str;
        repf(i,0,n){
            cin >> str;
            vect_str.push_back(str);
        }
        repf(i,0,n){
            repf(j,0,n){
                if(vect_str[i][j]=='1'){
                    pair<int,int> p(i,j);
                    for(k=0;k<n;++k){
                        for(l=0;l<n;++l){
                            if(vect_str[k][l]=='3'){
                                int man_dist= abs(k-i) +abs(l-j);
                                if(count_map.find(p)==count_map.end())
                                    count_map[p]=man_dist;
                                else if(count_map[p]>man_dist)
                                    count_map[p]= man_dist;
                            } 
                        }
                    }
                }
            }
        }
        int max= INT_MIN;
        for(auto iter: count_map)
           if(max<iter.second)
              max= iter.second;
        cout << max <<endl; 
        count_map.erase(count_map.begin(),count_map.end()); 
        vect_str.erase(vect_str.begin(),vect_str.end());
    }














    
}
