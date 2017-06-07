#include <iostream>
#include <stdio.h>
#define repP(i,b,n) for(i=b;i<n;i++)
#define repN(i,b,n) for(i=n;i>=b;i--)
#define size 1000005
using namespace std;
int main(){
	int t,n;
	int arr[size];
	scanf("%d",&t);
	for(int j=1;j<=t;j++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int total=0,index=0,temp;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			total+=(arr[i]-temp);
			if(total<0)
				index=i+1;
		}
		printf("Case %d:",j);
		if(total < 0)
			printf(" Not possible\n");
		else printf(" Possible from station %d\n",(index+1));
	}
}