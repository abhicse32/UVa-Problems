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

long long exponentiate(long long num, int power){
	long long res=1;
	while(power){
		if(power&1)
			res*=num;
		num*=num;
		power>>=1;
	}
	return res;
}

int main(){
	int C,i,j,n;
	int k,t,d;
	long long coeffs[25],an[25];
	si(C);
	while(C--){
		si(n);
		repf(i,0,n+1)
			sll(coeffs[i]);
		sii(d,k);
		memset(an,0,sizeof an);
		repf(i,1,22){
			repf(j,0,n+1)
				an[i]+= coeffs[j]*exponentiate(i,j);
		}
		// repf(i,1,21)
		// 	printf("%lld ",an[i]);
		// printf("\n");
		k<<=1;
		repf(i,1,22)
			if(d*(i*(i+1)) >= k)
				break;
		printf("%lld\n",an[i]);
	}
}