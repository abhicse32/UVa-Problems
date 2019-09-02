#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int i,j=1,n;
	int arr1[13],arr2[13];
	while(1){
		scanf("%d",&n);
		if(n<0) break;
		for(int i=0;i<12;i++)
			scanf("%d",&arr1[i]);
		for(int i=0;i<12;i++)
			scanf("%d",&arr2[i]);
		printf("Case %d:\n",j);
		for(int i=0;i<12;i++){
			if(n<arr2[i])
				printf("No problem. :(\n");
			else{ 
				printf("No problem! :D\n");
				n-=arr2[i];
			}
			n+=arr1[i];
		}
		++j;
	}
}