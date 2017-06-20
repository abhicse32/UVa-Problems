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
#define SIZE 10005
#define INF 999999999
char command[10];

void read_string(){
	int i=0;
	char ch;
	while((ch=gc())=='\n');
	while(ch!='\n' && ch!=' ' && ch!=EOF)
		command[i++]=ch,ch=gc();
	command[i]='\0';
	if(ch==EOF)
		exit(0);
}

int read_int(){
	int a=0;
	char ch;
	while((ch=gc())=='\n');
	while(ch!='\n' && ch!=' '||ch!=EOF)
		a=(a<<1)+(a<<3)+ch-48,
		ch=gc();
	return a;
}

void generate_1_len__words(map<string,int> & word_map,int& counter){
	string str="a";
	for(char i='a';i<='z';++i){
		str[0]=i;
		word_map[str]= ++counter;
	}
}

void generate_2_len__words(map<string,int> & word_map, int& counter){
	string str="aa";
	for(char i='a';i<='z';++i){
		str[0]=i;
		for(char j=i+1;j<='z';++j){
			str[1]=j;
			word_map[str]= ++counter;
		}
	}
}

void generate_3_len__words(map<string,int> & word_map, int& counter){
	string str("aaa");
	for(char i='a';i<='z';++i){
		str[0]=i;
		for(char j=i+1;j<='z';++j){
			str[1]=j;
			for(char k=j+1;k<='z';++k){
				str[2]=k;
				word_map[str]= ++counter;	
			}
		}
	}
}

void generate_4_len__words(map<string,int> & word_map, int& counter){
	string str("aaaa");
	for(char i='a';i<='z';++i){
		str[0]=i;
		for(char j=i+1;j<='z';++j){
			str[1]=j;
			for(char k=j+1;k<='z';++k){
				str[2]=k; 
				for(char l=k+1;l<='z';++l){
					str[3]=l;
					word_map[str]= ++counter;	
				}
			}
		}
	}
}

void generate_5_len__words(map<string,int> & word_map, int& counter){
	string str("aaaaa");
	for(char i='a';i<='z';++i){
		str[0]=i;
		for(char j=i+1;j<='z';++j){
			str[1]=j;
			for(char k=j+1;k<='z';++k){
				str[2]=k; 
				for(char l=k+1;l<='z';++l){
					str[3]=l; 
					for(char m=l+1;m<='z';++m){
						str[4]=m;
						word_map[str]= ++counter;
					}	
				}
			}
		}
	}
}

int main(){
	int i,j,k;
	map<string, int> word_map;
	int counter=0;
	generate_1_len__words(word_map,counter);
	generate_2_len__words(word_map,counter);
	generate_3_len__words(word_map,counter);
	generate_4_len__words(word_map,counter);
	generate_5_len__words(word_map,counter);

	while(scanf("%s",command)!=-1){
		cout << word_map[command] <<endl;
	}
}