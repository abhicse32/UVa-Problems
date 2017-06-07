#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#define gc getchar_unlocked
using namespace std;
int main(){
	int n,i,j,count=0;
	int arr[60];
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		int sum_=0;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			sum_+=arr[i];
		}
		int k=(sum_/n);
		sum_=0;
		for(int i=0;i<n;i++)
			sum_+=abs(arr[i]-k);
		printf("Set #%d\n",++count);
		printf("The minimum number of moves is %d.\n\n",(sum_>>1));
	}
	return 0;
}