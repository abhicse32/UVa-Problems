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
#define size 26
using namespace std;

bool compare(int a, int b){
	return a>b;
}

int main(){
	int r,c,m,n,t,sum;
	int i,j,k;
	char ch;
	int arr[size];
	si(t);
	repf(i,1,t+1){
		sum=0;
		scanf("%d%d%d%d",&r,&c,&m,&n);
		set(arr,0);
		repf(j,0,r){
			k=0;
			while(k<c){
				if((ch=gc())>='A' && ch <= 'Z'){
					arr[ch-'A']++;
					k++;
				}
			}
		}
		sort(arr,arr+size,compare);
		sum=(arr[0]*m);
		repf(j,1,size)
			if(arr[j-1]==arr[j])
				sum+=(arr[j]*m);
			else break;
		while(j<size)
			sum+=(arr[j++]*n);
		printf("Case %d: %d\n",i,sum);
	}
}