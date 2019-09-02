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
#define price 5000000
using namespace std;
bool compare(unsigned long long a, unsigned long long b){
	return a>b;
}

int main(){
	int i,j,k,t;
	unsigned long long arr[50],n;
	si(t);
	while(t--){
		i=0;
		while(scanf("%lld",&n),n)
			arr[i++]=n;
		sort(arr,arr+i,compare);
		unsigned long long total=0,temp;
		bool flag=true;
		repf(j,0,i){
			temp=(unsigned long long)pow(arr[j],j+1);
			total+=(temp<<1);
			if(total> price){
				flag=false;
				break;
			}
		}
		if(flag)
			cout << total <<endl;
		else cout <<"Too expensive\n";
	}
}