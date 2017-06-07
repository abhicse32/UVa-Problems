#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define max_size 10005

string database[max_size];
int b[max_size];
char pattern[max_size];
int m;

bool str_compare(string str1, string str2){
	for(string::iterator iter1= str1.begin(), iter2= str2.begin(),
			end1= str1.end(), end2= str2.end(); iter1 != end1 && iter2!= end2; ++iter1, ++iter2)
		if(*iter1 != *iter2)
			return false;
	return true;
}

int main(){
	int t,i,j,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;++i)
			cin >> database[i];
		sort(database,database+n);
		bool flag= false;
		for(i=0;i<n;++i){
			j=i+1;
			while(j<n && database[j][0]==database[i][0]){
				flag= str_compare(database[i],database[j++]);
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag)
			printf("NO\n");
		else printf("YES\n");
	}
}