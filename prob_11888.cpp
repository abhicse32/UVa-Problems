#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

#define size 200005
int b[size];

void strcat(char* dest, char* src, int len){
	int i,j;
	for(i=0,j=len;i<len;++i,++j)
		dest[j]=src[i];
	dest[j]='\0';
}

int kmp_search(char* pattern, char* text, int len_p ,int len_t){
	int i=0,j=0;
	while(i<len_t){
		while(j>=0 && pattern[j]!= text[i])
			j=b[j];
		++i; ++j;
		if(j==len_p && (i-j))
			return (i-j);
	}
	return -1;
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
	char str[(size<<1)];
	char temp_str[size<<1];
	int t,i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		// printf("%s ",str);
		int len= strlen(str);
		strcpy(temp_str,str);
		strcat(str,str,len);
		reverse(temp_str,temp_str+len);
		kmpPreprocess(temp_str,len);
		int index=kmp_search(temp_str,str,len,(len<<1));
		if(index==len || index==0)
			printf("palindrome\n");
		else if(index==-1)
			printf("simple\n");
		else printf("alindrome\n");

	}
}