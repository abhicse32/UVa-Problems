#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define size 10005

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int t,n;
	int arr[size];
	int ind[3];
	int probs[3][size];
	scanf("%d",&t);
	for(int case_=1;case_<=t;case_++){
		memset(arr,0,sizeof arr);
		for(int i=0;i<3;i++){
			scanf("%d",&ind[i]);
			for(int j=0;j<ind[i];j++){
				scanf("%d",&probs[i][j]);
				arr[probs[i][j]]++;
			}
			sort(probs[i],probs[i]+ind[i]);
		}
		int solved[3],max=0;
		for(int i=0;i<3;i++){
			solved[i]=0;
			for(int j=0;j<ind[i];j++)
				if(arr[probs[i][j]]==1)
					solved[i]++;
			if(max< solved[i])
				max= solved[i];
		}
		printf("Case #%d:\n",case_);
		for(int i=0;i<3;i++){
			if(solved[i]==max){
				printf("%d %d",i+1,solved[i]);
				for(int j=0;j<ind[i];j++)
					if(arr[probs[i][j]]==1)
						printf(" %d",probs[i][j]);
				printf("\n");
			}
		}
	}
}	