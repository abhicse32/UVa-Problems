#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <list>
#include <set>
#include <forward_list>
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define gc getchar_unlocked
#define si(n) scanf("%d",&n)
#define sii(m,n) scanf("%d%d",&m,&n)
#define ssi(str,a) scanf("%s%d",str,&a)
#define sis(a,str) scanf("%d%s",&a,str)
#define ss(str) scanf("%s",str)
using namespace std;
#define INF 999999999

struct functor{
	bool operator()(const char* str1, const char* str2)const{
		return strcmp(str1,str2)<0;
	}
};

int main(){
	int i,j,k;
	char str[205];
	set<char*,functor> dict;
	while(fgets(str,204,stdin)!=NULL){
		int len= strlen(str);
		str[len-1]='\0';
		rep(i,0,len)
			if(isalpha(str[i]))
				str[i]= tolower(str[i]);
			else str[i]= ' ';
		char* token=strtok(str," ");
		while(token){
			dict.insert(strdup(token));
			token= strtok(NULL," ");
		}
	}
	vectIter(dict) printf("%s\n",val); 
}