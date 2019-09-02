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
#include <forward_list>
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define gc getchar_unlocked
using namespace std;
#define SIZE 100000
#define INF 999999999

struct functor{
	bool operator()(const char* str1, const char* str2){
		return strcmp(str1,str2)<0;
	}
};

map<const char*, int, functor> word_map;
int lambda;

void extract_words(char* str){
	char* delimiters=".,:;!?\"() \t\n";
	// convert string to lowercase
	for(int i=0;str[i]!='\0';++i) str[i]= tolower(str[i]);
	char* token= strtok(str,delimiters);
	while(token!=NULL){
		char* temp= strdup(token);
		if(word_map.find(temp)==word_map.end())
			word_map[temp]=1;
		else ++word_map[token]; 
		token= strtok(NULL,delimiters);
		++lambda;
	}
}

double get_entropy(){
	double entropy=0;
	double log_lambda= log10(lambda);
	for(auto& val: word_map)
		entropy+=(val.second*(log_lambda- log10(val.second)));
	entropy/= lambda;
	double rel_entropy= (entropy/log_lambda)*100;
	printf("%.1lf %.0lf\n",entropy,rel_entropy);
	return entropy;
}

int main(){
	char *eot= "****END_OF_TEXT****";
	char *eoi= "****END_OF_INPUT****";
	int i,j,k,len;
	char str[SIZE];
	while(true){
		fgets(str,SIZE-1,stdin);
		if(str[strlen(str)-1]=='\n')
			str[strlen(str)-1]='\0';
		if(strcmp(str,eoi)==0)
			break;
		
		lambda=0;
		word_map.erase(word_map.begin(),word_map.end());
		while(strcmp(str,eot)!=0){
			extract_words(str);
			fgets(str,SIZE-1,stdin);
			str[strlen(str)-1]='\0';
		}
		cout << lambda <<" ";
		get_entropy();
	}
}