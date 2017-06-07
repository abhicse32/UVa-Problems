#include <iostream>
#include <stdio.h>
#include <string.h>
#define gc getchar_unlocked
int main(){
	int t,n,k;
	char ch;
	int arr[103];
	bool arr_[103];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		memset(arr_,0,sizeof arr_);
		for(int i=0;i<k;i++){
			int num;
			//printf("came here\n");
			scanf("%d",&num);
			num<<=1;
			for(int j=0;j<num;j++)
				scanf("%d",&arr[j]);
			while((ch=gc())=='\n');
			if(ch=='=')
				for(int j=0;j<num;j++)
					arr_[arr[j]]=1;
		}
		int count_zero=0,index=0;
		for(int i=1;i<=n;i++)
			if(!arr_[i]){
				count_zero++;
				index=i;
			}
		if(count_zero>1)
			index=0;
		printf("%d\n",index);
		if(t)
			printf("\n");
	}
}