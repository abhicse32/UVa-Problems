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
#define size 500005
using namespace std;
bool compare(int a, int b){
	return abs(a) > abs(b);
}

int main(){
	int t,n,i,j,k;
	int arr[size];
	si(t);
	while(t--){
		si(n);
		repf(i,0,n)
			si(arr[i]);
		sort(arr,arr+n,compare);
		k=1;
		j= arr[0]>0?true:false;
		repf(i,1,n){
			if((j && arr[i]<0) || (!j && arr[i]>=0)){
				j^=true;
				k++;
			}
		}
		cout << k <<endl;
	}
}