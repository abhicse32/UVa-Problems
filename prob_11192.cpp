#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int main(){
	int n;
	char str[102];
	while(scanf("%d",&n)==1 && n){
		scanf("%s",str);
		int len= strlen(str);
		int grp_len =len/n;
		for(int i=0;i<len;i+=grp_len)
			for(int j=i+grp_len-1;j>=i;j--)
				putchar(str[j]);
		printf("\n");
	}
}