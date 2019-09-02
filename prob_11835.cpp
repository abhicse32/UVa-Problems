#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define SIZE 105

class Driver{
public:
	int positions[SIZE];
	int score;
	int id;
	Driver(){
		score=0;
	}

	void reset(int i){
		score=0;
		memset(positions,0,sizeof(int)*SIZE);
		id= i;
	}	
};

set<int> get_winners(vector<Driver>& drivers, int P){
	int highest= 0,i;
	set<int> ids;
	rep(i,1,P+1)
		if(drivers[i].score> drivers[highest].score)
			highest= i;
	ids.insert(drivers[highest].id);
	int h_score= drivers[highest].score;
	rep(i,1,P+1)
		if(drivers[i].score== h_score)
			ids.insert(drivers[i].id);
	return ids;
}

int main(){
	int G,P;
	int i,j,k;
	int S,K;
	int points[SIZE];
	vector<Driver> drivers(SIZE);
	while(cin>> G >> P, G || P){
		rep(i,0,SIZE)
			drivers[i].reset(i);
		rep(i,1,G+1){
			rep(j,1,P+1){
				scanf("%d",&k);
				drivers[j].positions[i]= k;
			}
		}
		scanf("%d",&S);
		while(S--){
			scanf("%d",&K);
			memset(points,0,sizeof(int)*SIZE);
			rep(i,1,K+1)
				scanf("%d",&k),
				points[i]=k;

			rep(i,1,P+1){
				drivers[i].score=0;
				rep(j,1,G+1)
					drivers[i].score+=points[drivers[i].positions[j]];
				
			}
			set<int> winners= get_winners(drivers,P);
			bool flag=false;
			for(auto &iter: winners){
				if(!flag){
					cout<< iter;
					flag= true;
				}else
					cout <<" " << iter;
			}
			cout <<endl; 
		}
	}
}