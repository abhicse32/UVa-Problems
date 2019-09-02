#include <iostream>
#include <stdio.h>
using namespace std;
#define size 10005
int main(){
	int t,n,i,j;
	int arr[size];
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		arr[n]=arr[0];
		arr[n+1]=arr[1];
		n+=2;
		int total=0;
		i=1;
		while(i<n){
			j=i;
			while(i<n && arr[i]>arr[i-1]) i++;
			if(i<n && j!=i) total++;
			j=i;
			while(i<n && arr[i]<arr[i-1]) i++;
			if(i<n && j!=i) total++;
		}
		printf("%d\n",total);
	}
	
}