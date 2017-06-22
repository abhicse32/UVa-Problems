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

int get_op(char* guess, int& j){
	int comp_op;
	switch(guess[j]){
		case '<':
			comp_op=0;
			if(*(guess+j+1)=='=')
				++j,++comp_op;
			break;
		case '>':
			comp_op=2;
			if(*(guess+j+1)=='=')
				++j,++comp_op;
			break;
		case '=': 
			comp_op=4; 
			break;
		default: break;
	}
	return comp_op;
}

int main(){
	int i,j,k;
	int m,n;
	int before,after;
	char dec;
	sii(m,n);
	map<char*,int,functor> records;
	char party[25];	
	char guess[2005];
	rep(i,0,m){
		scanf("%s%d%c%d",party,&before,&dec,&after);
		records[strdup(party)]= before*10+after;
	}
	cin.ignore(100,'\n');
	int comp_op; // 0 for <,1 for <=, 2 for >, 3 for >= and 4 for =

	rep(i,1,n+1){
		fgets(guess,2004,stdin);
		int len= strlen(guess);
		guess[len-1]= '\0';
		
		rep(j,0,len){
			if(*(guess+j)=='>' || *(guess+j)=='<' || 
				*(guess+j)=='=')
				break;
		}
		k=j-1;
		comp_op= get_op(guess,j);
		int vote= atoi(guess+(++j)+1);
		guess[k]='\0';
		char* token= strtok(guess," +");
		int total=0;
		while(token){
			total+=records[token];
			token=strtok(NULL," +");
		}
		vote*=10;

		printf("Guess #%d was ",i);
		if((total<vote && comp_op==0) ||(total<=vote && comp_op==1) ||
			(total>vote && comp_op==2) || (total>= vote && comp_op==3) ||
			(total==vote && comp_op==4))
			printf("correct.\n");
		else printf("incorrect.\n"); 
	}
}