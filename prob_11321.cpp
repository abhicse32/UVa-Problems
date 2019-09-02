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
#define size 10005
using namespace std;
int mod;
bool compare(int a, int b){
	int mod_a= a%mod;
	int mod_b= b%mod;
	if(mod_a < mod_b)
		return true;
	else if(mod_a== mod_b){
		if(a&1){
			if(b&1)
				return a > b;
			return true;
		}else{
			if(b&1)
				return false;
			else return a<b;
		}
	}
	return false;
}

int main(){
	int n,m,i,j,k;
	int arr[size];
	while(sii(n,m), (n && m)){
		printf("%d %d\n",n,m);
		mod=m;
		repf(i,0,n)
			si(arr[i]);
		sort(arr,arr+n,compare);
		repf(i,0,n)
			printf("%d\n",arr[i]);
	}
	printf("%d %d\n",n,m);
}