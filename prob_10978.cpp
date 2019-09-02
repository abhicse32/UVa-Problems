#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
#define rep(i,b,n) for(i=b;i<n;i++)
using namespace std;
int main(){
	int n,i,j,k;
	char str1[5],str2[21];
	map<int,char*> myMap;
	bool arr[60];
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		int total=0;
		memset(arr,0,sizeof arr);
		rep(i,0,n){
			scanf("%s%s",str1,str2);
			int len= strlen(str2)+total;
			for(j=total+1,k=total+1;j<=len;k++)
				if(!arr[k%n])
					j++;
			total=(k-1)%n;
			arr[total]=true;
			myMap[total]=strdup(str1);
		}
		for(map<int,char*>::iterator iter= ++(myMap.begin()), end= myMap.end(); iter!= end; ++iter)
			printf("%s ",iter->second);
		printf("%s\n",(myMap.begin())->second);
		myMap.clear();
	}
}