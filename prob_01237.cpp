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
#include <set>
#include <bitset>
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,n,b) for(i=n;i>=b;i--)
#define vectIter(vect,T) for(vector<T>::iterator iter= vect.begin(), \
								end= vect.end(); iter!= end; ++iter)
#define mapIter(map_,T1,T2)  for(map<T1,T2>::iterator iter_= map_.begin(),  \
						end_= map_.end(); iter_ != end_; ++iter_)
#define si(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define set_(a,i) memset(a,i,sizeof a)
#define gc getchar_unlocked
using namespace std;


int main(){
	int t,i,j,k,d,l,h,q;
	si(t);
	char str[30];
	map<char*,pair<int,int> > myMap;
	while(t--){
		si(d);
		repf(i,0,d){
			cin >> str >> l >> h ; 
			myMap[strdup(str)]=make_pair(l,h);
		}
		si(q);
		while(q--){
			si(j);
			int counter=0;
			char* name;
			for(map<char*,pair<int,int> >::iterator iter_= myMap.begin(), end= myMap.end();
							iter_!=end; ++iter_){
				if(j>= iter_->second.first && j<= iter_->second.second){
					if(!counter){
						name= iter_->first;
						++counter;
					}
					else{
						counter=0;
						break;
					}
				}
			}
			if(counter)
				cout << name <<endl;
			else cout <<"UNDETERMINED" <<endl;
		}
		if(t)
			cout <<endl;
		myMap.clear();
	}
}