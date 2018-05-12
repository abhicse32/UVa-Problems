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
typedef struct Player{
    string name;
    int attacking,defending;
    Player(string& str, int a, int b):name(str),attacking(a),defending(b){}
    bool operator<(const Player& p) const{
        return tie(name,attacking,defending)< tie(p.name,p.attacking,p.defending);
    }
    Player(){
        name="";
        attacking= defending=0;
    }
}player;

void print_attackers_defenders(vector<player>& vect, int indices){
    bool flag= false;
    printf("(");
    for(int i=0;i<10;++i){
        if(indices&(1<<i)){
            if(!flag){
                cout << vect[i].name;
                flag= true;
            }else
               cout <<", "<< vect[i].name; 
        }
    }
    printf(")\n");   
}

int main(){
    int i,j,k,l,m,t,n,max_attack,cases=0;
    vector<player> vect;
    player p;
    for(sc(t);t--;){
        vect.erase(vect.begin(),vect.end());
        repf(i,0,10){
           cin >> p.name >> p.attacking >> p.defending;
           vect.push_back(p);
       } 
       sort(vect.begin(),vect.end());
       int max_attack=0,indices=0,attack_sum=0;

       for(i=0;i<6;++i){
           for(j=i+1;j<7;++j){
               int sum1= vect[i].attacking+ vect[j].attacking;
               for(k=j+1;k<8;++k){
                   int sum2= sum1+vect[k].attacking;
                   for(l=k+1;l<9;++l){
                       int sum3= sum2+ vect[l].attacking;
                       for(m=l+1;m<10;++m){
                           int sum4= sum3 + vect[m].attacking;
                           if(sum4 > max_attack){
                               max_attack= sum4;
                               indices=(1<<i)|(1<<j)|(1<<k)|(1<<l)|(1<<m);
                           }else if(sum4==max_attack){
                               int current_defend=0, prev_defend=0;
                               int current_indices=(1<<i)|(1<<j)|(1<<k)|(1<<l)|(1<<m);
                               for(int counter=0;counter<10;++counter){
                                   if(!(indices&(1<<counter)))
                                       prev_defend+=vect[counter].defending;
                                    if(!(current_indices&(1<<counter)))
                                       current_defend+=vect[counter].defending;
                               }
                                if(current_defend>prev_defend){
                              //      printf("%d %d\n",current_defend,prev_defend);
                                    indices=(1<<i)|(1<<j)|(1<<k)|(1<<l)|(1<<m);
                                }
                           }
                       }
                   }
               }
           }
       }
        printf("Case %d:\n",++cases);
        print_attackers_defenders(vect,indices);
        print_attackers_defenders(vect,~indices);
    }
}
