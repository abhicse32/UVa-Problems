#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,b,n) for(i=n;i>=b;i--)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define gc getchar_unlocked
using namespace std;
int main(){
	int n,i,j,k,pos;
	map<int,int> myMap;
	while(si(n) && n){
		bool flag=true;
		repf(i,1,n+1){
			sii(j,k);
			pos=i+k;
			if(myMap.find(pos)!=myMap.end() || pos>n || pos < 1)
				flag=false;
			else myMap[pos]=j;
		}
		i=1;
		if(!flag)
			printf("-1");
		else
			for(map<int,int>::iterator iter= myMap.begin(), end= myMap.end(); iter!= end; ++iter){
				printf("%d",iter->second);
				if(i<n)
					printf(" ");
				i++;
			}
		printf("\n");
		myMap.clear();
	}	
}