#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define max_size 1000005
int b[max_size];
char pattern[max_size];
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
	while(scanf("%s",pattern),strcmp(pattern,".")){
		m= strlen(pattern);
		int index= kmpPreprocess();
		if(m%(m-index))
			printf("%d\n",1);
		else printf("%d\n",m/(m-index));
	}
}