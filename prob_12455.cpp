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
#define sii(a,b) scanf("%d%d",&a,&b) 
#define set_(a,i) memset(a,i,sizeof a)
#define gc getchar_unlocked
using namespace std;

int main(){
	int i,j,k,t,n,l;
	int arr[30];
	si(t);
	while(t--){
		si(l);
		si(n);
		repf(i,0,n)si(arr[i]);
		j=(1<<n);
		bool flag=false;
		repf(i,0,j){
			k=i;
			int counter=0,sum=0;
			while(k){
				if(k&1)
					sum+=arr[counter];
				counter++;
				k>>=1;
			}
			if(sum==l){
				printf("YES\n");
				flag=true;
				break;
			}
		}
		if(!flag)
			printf("NO\n");
	}
}