#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

#define size 1000005
int b[size];
char str[size],temp_str[size];


int kmp_search(char* text, char* pattern, int n, int m){
	int i=0,j=0;
	int max_len=0;
	while(i<n){
		while(j>=0 && pattern[j]!= text[i])
			j=b[j];
		++i; ++j;
		if(max_len<j)
			max_len=j;
		if(j==m){
			j=b[j];
		}
	}
	return max_len;
}

int kmpPreprocess(char* pattern, int m){
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
	int t,i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);	
		int len= strlen(str);
		strcpy(temp_str,str);
		reverse(temp_str,temp_str+len);
		kmpPreprocess(str,len);
		int max_len= kmp_search(temp_str,str,len,len);
		for(i=max_len-1;i>=0;--i)
			putchar(str[i]);
		printf("\n");
	}
}