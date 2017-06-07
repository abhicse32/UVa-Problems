#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main(){
	int t,N,p,k;
	int parties[105];
	bool arr[4000];
	scanf("%d",&t);
	while(t--){
		memset(arr,0,sizeof arr);
		scanf("%d%d",&N,&p);
		for(int i=0;i<p;i++)
			scanf("%d",&parties[i]);
		for(int i=0;i<p;i++){
			k=parties[i];
			for(int j=k-1;j<N;j+=k)
				arr[j]=true;
		}
		// for(int i=0;i<N;i++)
		// 	printf("%d ",arr[i]);
		// printf("\n");
		int counter=0;
		for(int i=0;i<N;i++){
			k= i%7;
			if(arr[i] && k!=5 && k!=6)
				counter++;
		}
		printf("%d\n",counter);
	}
}