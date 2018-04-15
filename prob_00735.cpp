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
#define sc(n) scanf("%d",&n)
#define scc(n,m) scanf("%d%d",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked


int main(){
    int i,j,k,a,b,c,n;
    set<set<int> > combinations;
    set<vector<int> >permutations;

    while(sc(n),n>0){
        combinations.erase(combinations.begin(),combinations.end());
        permutations.erase(permutations.begin(),permutations.end());
        if(n>180){
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);  
        }else{
            repf(i,0,21){
                repf(j,0,21){
                    repf(k,0,21){
                        repf(a,1,4){
                            repf(b,1,4){
                                repf(c,1,4){
                                    if((a*i+b*j+c*k)==n){ 
                                        permutations.insert(vi{a*i,b*j,c*k});
                                        combinations.insert(set<int>{a*i,b*j,c*k});
                                    }
                                }
                            }
                        } 
                    }
                }
            }
            repf(i,0,21){
                repf(j,0,21){
                    repf(a,1,4){
                        repf(b,1,4){
                            if((50+a*i+b*j)==n){
                                permutations.insert(vi{50,a*i,b*j});
                                permutations.insert(vi{a*i,50,b*j});
                                permutations.insert(vi{a*i,b*j,50});
                                combinations.insert(set<int>{50,a*i,b*j});
                            } 
                        }
                    } 
                }
            }

            repf(i,0,21){
                repf(a,1,4){
                    if((50+50+a*i)==n){
                        permutations.insert(vi{50,50,a*i});
                        permutations.insert(vi{50,a*i,50});
                        permutations.insert(vi{a*i,50,50});
                        combinations.insert(set<int>{50,50,a*i});
                    }
                }
            }
            if(n==150){
                permutations.insert(vi{50,50,50});
                combinations.insert(set<int>{50,50,50});
            }
            if(permutations.size()){
                printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %lu.\n",n,combinations.size());
                printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %lu.\n",n,permutations.size());
            }else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
        }
        printf("**********************************************************************\n"); 
    }
    printf("END OF OUTPUT\n");
}
