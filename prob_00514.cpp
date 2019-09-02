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
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define gc getchar_unlocked
using namespace std;

bool flag=false;
int j,n;

bool move_to_station(stack<int>& st, int k){
	for(;j<n && j<k;++j)
		st.push(j);
	++j;
}

int main(){
	int i,k;
	stack<int> st;
	while(scanf("%d",&n),n){
		while(true){
			flag=true;
			scanf("%d",&k);
			if(!k) break;
			j=1;
			if(k<j)
				flag=false;
			else move_to_station(st,k); 
			rep(i,0,n-1){
				scanf("%d",&k);
				//cout << st.size() <<endl;
				if(flag){
					if(!st.empty() && st.top()==k)
						st.pop();
					else if(k>=j)
						move_to_station(st,k);
					else flag=false;
				}
			}
			if(flag && st.empty())
				cout <<"Yes" <<endl;
			else cout <<"No" <<endl;
			while(!st.empty()) st.pop();
		}
		cout <<endl;
	}
}