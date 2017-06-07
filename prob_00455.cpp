#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int b[1000];
char pattern[1000];
int m;

int kmpPreprocess(){
	int i=0,j=-1;
	b[0]=-1;
	while(i<m){
		while(j>=0 && pattern[i]!=pattern[j])
			j=b[j];
		++j; ++i;
		b[i]=j;
	}
	return j;
}

int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%s",pattern);
		m= strlen(pattern);
		int index= kmpPreprocess();
		if(m%(m-index))
			printf("%d\n",m);
		else printf("%d\n",(m-index));
		if(t)
			printf("\n");
	}
}