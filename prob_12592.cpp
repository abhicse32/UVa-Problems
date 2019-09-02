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
	int t;
	map<char*,char*, functor> slogans;
	si(t);
	cin.ignore(100,'\n');
	char str1[105],str2[105];
	while(t--){
		fgets(str1,104,stdin);
		fgets(str2,104,stdin);
		str1[strlen(str1)-1]='\0';
		str2[strlen(str2)-1]='\0';
		slogans[strdup(str1)]= strdup(str2);
	}
	si(t);
	cin.ignore(100,'\n');
	while(t--){
		fgets(str1,104,stdin);
		str1[strlen(str1)-1]='\0';
		printf("%s\n",slogans[str1]);
	}
}