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

bool compare(string str1, string str2){
	return (str1+str2) > (str2+str1);
}

int main(){
	int n,i,j,k;
	string arr[60];
	while(si(n),n){
		repf(i,0,n)
			cin >> arr[i];
		sort(arr,arr+n,compare);
		repf(i,0,n)
			cout << arr[i];
		puts("");
	}
}