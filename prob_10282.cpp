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
using namespace std;
#define INF 999999999

struct functor{
	bool operator()(const char* str1, const char* str2){
		return strcmp(str1,str2)<0;
	}
};

int main(){
	int i,j,k,n;
	map<char*,char*,functor> database;
	char str[30];
	while(fgets(str,29,stdin)!=NULL){
		int len= strlen(str);
		str[len-1]='\0';
		if(len-1==0) break;
		char* token1= strdup(strtok(str," "));
		database[strdup(strtok(NULL," "))]=token1;
	}
	while(fgets(str,29,stdin)!=NULL){
		int len= strlen(str);
		str[len-1]='\0';
		if(len-1==0) break;
		if(database.find(str)!=database.end())
			printf("%s\n",database[str]);
		else printf("%s\n","eh"); 
	}
}