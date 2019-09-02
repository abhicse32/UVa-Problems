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
#define si(n) scanf("%d",&n);
#define ss(str) scanf("%s",str)
using namespace std;
#define INF 999999999
#define SIZE 10005

int main(){
	int t,i,j,k,l;
	int m,n;
	vector<set<int> > map_;
	int arr[SIZE];
	char ch='%';
	si(t);
	rep(i,1,t+1){
		si(n);
		map_= vector<set<int> >(n);
		memset(arr,0,sizeof arr);
		rep(j,0,n){
			si(m);
			rep(k,0,m){
				si(l);
				map_[j].insert(l);
			}
		}
		vectIter(map_){
			set<int>& vect= val;
			for(auto&iter: vect)
				++arr[iter];
		}
		int count=0;
		vectIter(map_){
			set<int>& vect= val;
			for(auto iter= vect.begin(); iter!= vect.end();)
				if(arr[*iter]>1)
					iter= vect.erase(iter);
				else ++iter;
			count+=vect.size();
		}
		printf("Case %d:",i);
		vectIter(map_)
			printf(" %.6lf%c",(double(val.size())/count)*100,ch);
		map_.erase(map_.begin(),map_.end());
		printf("\n");
	}
}