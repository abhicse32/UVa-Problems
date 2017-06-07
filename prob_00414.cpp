#include <iostream>
#include <stdio.h>
#include <string.h>
#define gc getchar_unlocked
int input(){
	int i=0;
	char ch;
	while((ch=gc())!='X');
	while(ch=='X'){
		i++; ch= gc();
	}
	return i;
}

using namespace std;
int main(){
	int n,max_sum,sum_;
	int arr[2][15];
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		max_sum=0;
		memset(arr,0,sizeof arr);
		for(int i=0;i<n;i++){
			arr[0][i]=input();
			if(arr[0][i]<25)
				arr[1][i]=input();
			sum_=arr[0][i]+arr[1][i];
			if(max_sum < sum_)
				max_sum= sum_;
		}
		sum_=0;
		for(int i=0;i<n;i++)
			sum_+=(max_sum-(arr[0][i]+arr[1][i]));
		printf("%d\n",sum_);
	}
}