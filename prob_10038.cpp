#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#define gc getchar_unlocked
using namespace std;
#define size 3005
int main(){
	bool arr[size];
	int n,num1,num2;
	while(1){
		num1=scanf("%d",&n);
		if(num1!=1)
			break;
		memset(arr,0,sizeof arr);
		scanf("%d",&num1);
		for(int i=1;i<n;i++){
			scanf("%d",&num2);
			arr[abs(num2-num1)]=true;
			num1= num2;		
		}
		num1=1;
		for(int i=1;i<n;i++)
			if(!arr[i]){
				num1=0;
				break;
			}
		if(num1)
			printf("Jolly\n");
		else printf("Not jolly\n");
	}
}