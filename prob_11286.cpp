#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <list>
#include <set>
#include <forward_list>
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define gc getchar_unlocked
using namespace std;
#define INF 999999999

int main(){
	int i,j,n;
	int a,b,c,d,e;
	map<set<int>,int> database;
	while(scanf("%d",&n),n){
		rep(i,0,n){
			scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
			set<int> set_{a,b,c,d,e};
			++database[set_];
		}
		int highest=0;
		for(auto&val:database)
			if(val.second>highest)
				highest= val.second;

		int counter=0;
		for(auto&val:database){
			if(val.second==highest)
				counter+=highest;
		}
		cout << counter <<endl;
		database.erase(database.begin(),database.end());
	}
}