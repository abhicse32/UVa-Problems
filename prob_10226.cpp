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
	map<char*,int,functor> database;
	char str[35];
	scanf("%d\n",&n);
	while(n--){
		while(fgets(str,34,stdin)!=NULL){
			str[strlen(str)-1]='\0';
			if(strlen(str)==0)
				break;
			++database[strdup(str)];
		}
		int count=0;
		mapIter(database)
			count+=val_.second;
		
		mapIter(database)
			printf("%s %.4f\n",val_.first,(double(val_.second)/count*100));	

		if(n)
			cout << endl;
		database.erase(database.begin(),database.end());
	}
}