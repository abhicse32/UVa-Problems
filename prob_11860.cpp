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
#define si(n) scanf("%d",&n);
#define sii(m,n) scanf("%d%d",&m,&n);
#define ss(str) scanf("%s",str)
using namespace std;
#define INF 999999999

struct functor{
	bool operator()(const char* str1, const char* str2)const{
		return strcmp(str1,str2)<0;
	}
};

vector<char*> vect;
map<char*,int,functor> database;
set<char*,functor> unique_;

void extract(char* str,int len){
	int i;
	rep(i,0,len)
		if(str[i]<'a' || str[i]>'z')
			str[i]=' ';
	char *token= strtok(str," ");
	while(token){
		char* temp= strdup(token);
		vect.push_back(temp);
		unique_.insert(temp);
		token= strtok(NULL," ");
	}
}

int main(){
	
	int t,i,j,k,l;
	si(t);
	char str[200];
	rep(i,1,t+1){
		printf("Document %d: ",i);
		vect.push_back("");
		while(fgets(str,199,stdin)!=NULL){
			int len= strlen(str);
			str[len-1]='\0';
			if(!strcmp(str,"END"))
				break;
			extract(str,len);
		}
		int len= unique_.size();
		k=1;
		int lower=1,upper=INF;
		if(vect.size()==1)
			upper=0;
		else if(vect.size()==2)
			upper=1;
		else{
			database[vect[1]]=1;
			int sz= vect.size();
			for(j=2;j<sz;++j){
				database[vect[j]]=j;
				for(l=k;l<=j && l<database[vect[l]];++l);
				k=l;
				if(database.size()==len){
					upper=j,lower=k;
					break;
				}
			}

			for(;j<sz;++j){
				database[vect[j]]= j;
				for(l=k;l<=j && l< database[vect[l]];++l);
				k=l;
				if(upper-lower > j-k)
					upper= j, lower=k;				
			}
		}
		printf("%d %d\n",lower,upper);	
		vect.erase(vect.begin(),vect.end());
		unique_.erase(unique_.begin(),unique_.end());
		database.erase(database.begin(),database.end());
	}
}