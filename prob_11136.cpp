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
#define si(n) scanf("%d",&n)
#define sii(m,n) scanf("%d%d",&m,&n)
#define ssi(str,a) scanf("%s%d",str,&a)
#define sis(a,str) scanf("%d%s",&a,str)
#define ss(str) scanf("%s",str)
using namespace std;
#define INF 999999999

int main(){
	int n,i,j,k,d;
	multiset<int> database;
	while(si(n),n){
		long long sum=0;
		rep(i,0,n){
			si(d);
			while(d--) si(k), database.insert(k);

			sum+=(long long)(*(database.rbegin()) - *(database.begin()));
			database.erase(database.begin());
			database.erase(--(database.end()));
		}
		database.erase(database.begin(),database.end());
		printf("%lld\n",sum);
	}
}