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

void extract_key_values(char* str,map<char*,char*,functor>& dict){
	char delimiter[]="{,}";
	char* token= strtok(str,delimiter);
	while(token){
		int i,len= strlen(token);
		for(i=0;i<len && token[i]!=':';++i);
		token[i]='\0';
		dict[strdup(token)]= strdup(token+i+1);
		token= strtok(NULL,delimiter);
	}
}

void print(char ch, set<char*,functor>& vect){
	auto iter= vect.begin();
	printf("%c%s",ch,*iter);
	for(++iter;iter!=vect.end();++iter)
		printf(",%s",*iter);
	printf("\n");
}

int main(){
	int t,i,j,k;
	si(t);
	map<char*,char*,functor> dict1,dict2;	
	char str1[105];
	map<char*,set<char*,functor>,functor> extras;

	while(t--){
		ss(str1);
		extract_key_values(str1,dict1);
		ss(str1);
		extract_key_values(str1,dict2);
		mapIter(dict2)
			if(dict1.find(val_.first)==dict1.end())
				extras["+"].insert(val_.first);
			else if(strcmp(dict1[val_.first],val_.second))
				extras["*"].insert(val_.first);
		
		mapIter(dict1)
			if(dict2.find(val_.first)==dict2.end())
				extras["-"].insert(val_.first);

		if(extras.find("+")!=extras.end())
			print('+',extras["+"]);
		if(extras.find("-")!=extras.end())
			print('-',extras["-"]);
		if(extras.find("*")!= extras.end())
			print('*',extras["*"]);
		if(extras.size()==0)
			printf("No changes\n");
		printf("\n");
		dict1.erase(dict1.begin(),dict1.end());
		dict2.erase(dict2.begin(),dict2.end());
		extras.erase(extras.begin(),extras.end());
	}
}