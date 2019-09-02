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
#define SIZE 30007

int main(){
	int i,j,k,p;
	int t,n,m;
	int A[SIZE];
	multiset<int> storage;
	si(t);
	while(t--){
		sii(m,n);
		rep(i,1,m+1)
			si(A[i]);

		p=1;
		si(k);
		while(p<=k) storage.insert(A[p]),++p;
		auto iter= storage.begin();
		printf("%d\n",*iter);

		rep(j,1,n){
			si(k);
			while(p<=k){
				storage.insert(A[p]);
				if(A[p]< *iter)
					--iter;
				++p;
			}
			printf("%d\n",*(++iter));
		}
		if(t)
			printf("\n");
		storage.erase(storage.begin(),storage.end());
	}
}