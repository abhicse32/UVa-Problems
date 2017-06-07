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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,n,b) for(i=n;i>=b;i--)
#define vectIter(vect,T) for(vector<T>::iterator iter= vect.begin(), \
								end= vect.end(); iter!= end; ++iter)
#define mapIter(map_,T1,T2)  for(map<T1,T2>::iterator iter_= map_.begin(),  \
						end_= map_.end(); iter_ != end_; ++iter_)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define gc getchar_unlocked
using namespace std;
#define size  65537
int findIdx(int num, int* arr){
	int counter=0,i;
	repf(i,0,size){
		counter+=arr[i];
		if(counter>= num)
			return i;
	}
}

int main(){
	int i,j,count=0,n,small,diff,small2;
	int *low,*high;
	int arr[size];
	while(si(n)==1){
		memset(arr,0,sizeof arr);
		repf(i,0,n){
			si(j);
			arr[j]++;
		}
		j=(n>>1);
		int counter=0; count=0;
		diff=1;
		if(n&1){
			small=findIdx(j+1,arr);
			count= arr[small];
		}else{
			small= findIdx(j,arr);
			count=arr[small];
			small2= findIdx(j+1,arr);
			if(small!=small2){
				count+=arr[small2];
				diff+=(small2-small);
			}
		}
		cout << small <<" " << count <<" " << diff <<endl;
	}
}