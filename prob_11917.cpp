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
	int i,j,k,D;
	int t,n;
	char subject[25];
	map<char*,int,functor> database;
	si(t);
	rep(i,1,t+1){
		si(n);
		rep(j,0,n){
			ssi(subject,k);
			database[strdup(subject)]= k;
		}
		sis(D,subject);
		printf("Case %d: ",i);
		if(database.find(subject)!=database.end()){
			if(database[subject]<=D)
				printf("Yesss\n");
			else if(database[subject]<=D+5)
				printf("Late\n");
			else printf("Do your own homework!\n");	
		}else printf("Do your own homework!\n");
		database.erase(database.begin(),database.end());
	}
}