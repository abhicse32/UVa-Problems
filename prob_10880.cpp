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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,n,b) for(i=n;i>=b;i--)
#define vectIter(vect,T) for(vector<T>::iterator iter= vect.begin(), \
								end= vect.end(); iter!= end; ++iter)
#define mapIter(map_,T1,T2)  for(map<T1,T2>::iterator iter_= map_.begin(),  \
						end_= map_.end(); iter_ != end_; ++iter_)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define set(a,i) memset(a,i,sizeof a)
#define gc getchar_unlocked
using namespace std;
#define size 10005

int main(){
	long long R,C,i,j,n,ate,k,p;
	set<long long> vect;
	scanf("%lld",&n);
	repf(p,1,n+1){
		cin >> C >> R;
		ate= C-R;
		if(!ate){
			printf("Case #%lld: 0\n",p);
			continue;
		}
		j=ceil(sqrt(ate));
		repf(i,1,j+1){
			if(!(ate%i)){
				if(i>R)
					vect.insert(i);
				k= ate/i;
				if(k > R)
					vect.insert(k);
			}
		}
		printf("Case #%lld:",p);
		for(set<long long>::iterator iter= vect.begin(), end= vect.end(); iter!= end; ++iter)
			printf(" %lld",*iter);
		printf("\n");
		vect.clear();
	}
}