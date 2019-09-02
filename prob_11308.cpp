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

struct functor{
	bool operator()(const pair<string,int>& p1, 
		const pair<string,int>& p2)const{

		if(p1.second < p2.second)
			return true;
		else if(p1.second== p2.second && p1.first< p2.first)
			return true;
		return false; 
	}
};
int main(){
	int t,i,j,k,n,m,b;
	scanf("%d\n",&t);
	string str,str2;
	map<string,int> ingredients;
	while(t--){
		getline(cin, str);
		scanf("%d%d%d\n",&m,&n,&b);
		rep(i,0,m){
			cin >> str2 >> k;
			ingredients[str2]= k;
		}
		transform(str.begin(),str.end(),str.begin(),::toupper);
		cout << str <<endl;
		set<pair<string,int>, functor> required;
		cin.ignore(100,'\n');
		bool flag=false;
		rep(i,0,n){
			getline(cin,str);	
			scanf("%d\n",&k);
			int units, cost=0;
			rep(j,0,k){
				cin >> str2 >> units;
				cost+=(ingredients[str2]*units);
			}
			if(cost<=b) required.insert(make_pair(str,cost));
			cin.ignore(100,'\n');
		}
		ingredients.erase(ingredients.begin(),ingredients.end());
		// cin.ignore(100,'\n');
		if(required.size()>0){	
			vectIter(required)
				cout << val.first <<endl;
		}else cout <<"Too expensive!\n";
		// if(t)
			cout << endl;
	}
}