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

int main(){
	int i,j,k,l,largest;
	int t,n,counter=0;
	si(t);
	map<int,int> last_index;

	while(t--){
		si(n);
		k=1; largest=1;
		counter=0;
		++n;
		rep(i,1,n){
			si(j);
			l= last_index[j];
			if(l>=k){
				if(i-k>largest){
					largest= i-k;
					//cout << largest <<endl;
				}
				k=l+1;
			}
			last_index[j]=i;
		}
		if(last_index[j]-k+1>largest)
			largest= last_index[j]-k+1;
		if(n==1) largest=0;
		printf("%d\n",largest);
		last_index.erase(last_index.begin(),last_index.end());
	}
}