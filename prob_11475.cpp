#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

#define size 100005

void strcat(char* dest, char* src, int len){
	int i,j;
	for(i=0,j=len+1;i<len;++i,++j)
		dest[j]=src[i];
	dest[j]='\0';
}

int kmpPreprocess(char* pattern, int m){
	int i=0,j=-1;
	int* b= new int[m+1];
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
	char str[(size<<1)];
	char temp_str[size<<1];
	int t,i,j,k;
	while(scanf("%s",str)!=-1){
		int len= strlen(str);
		strcpy(temp_str,str);
		reverse(temp_str,temp_str+len);
		temp_str[len]='$';
		strcat(temp_str,str,len);
		int len2= kmpPreprocess(temp_str,(len<<1)+1);
		for(i=len-len2-1,j=len;i>=0;--i,++j)
			str[j]=str[i];
		str[j]='\0';
		printf("%s\n",str);
	}
}