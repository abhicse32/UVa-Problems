#include <iostream>
#include <stdio.h>
#include <string.h>
#define gc getchar_unlocked
using namespace std;
#define size 10005
int main(){
	int t,n,i,j,k;
	char ch;
	double arr[257],m;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(arr,0,sizeof arr);
		while(n--){
			while((ch=gc())=='\n');
			scanf("%lf",&m);
			arr[ch]=m;
		}
		scanf("%d",&n);
		while((ch=gc())=='\n');
		long double total=arr[ch];
		while(n--){
			while((ch=gc())!='\n')
				total+=arr[ch];
		}
		printf("%.2llf$\n",total/100);
	}
}