#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,b,n) for(i=n;i>=b;i--)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 

#define gc getchar_unlocked
using namespace std;
#define size 1500
int main(){
	int i,j,k,n;
	int arr[size];
	while(1){
		si(n);
		if(!n) break;
		repf(i,0,n)
			si(arr[i]);
		sort(arr,arr+n);
		bool flag=true;
		repf(i,1,n)
			if(arr[i]-arr[i-1]>200){
				flag=false;
				break;
			}
		if(((1422 - arr[n-1])<<1) >200)
			flag=false;
		if(!flag)
			printf("IMPOSSIBLE\n");
		else printf("POSSIBLE\n");
	}
}