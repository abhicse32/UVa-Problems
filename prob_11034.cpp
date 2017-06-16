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
	while(ch!='\n' && ch!=' '||ch!=EOF)
		command[i++]=ch,ch=gc();
	command[i]='\0';
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

int main(){
	int t,l,m,c;
	//n - number of cars ferry can carry at a time
	//t- time taken by the ferry to cross the river
	queue<int> right;
	queue<int> left;
	int i,j,k;

	scanf("%d",&c);
	while(c--){
		scanf("%d%d",&l,&m);
		rep(i,0,m){
			scanf("%d%s",&j,command);
			if(command[0]=='l')
				left.push(j);
			else right.push(j);
		}
		l=l*100; // converted the length in centimeters
		int times=0;
		while(!left.empty() || !right.empty()){
			int loaded_len=0;
			while(!left.empty() && (loaded_len+ left.front())<= l)
				loaded_len+=left.front(),left.pop();
			if(loaded_len || !right.empty())
				++times;
			loaded_len=0;
			while(!right.empty() && (loaded_len+ right.front())<= l)
				loaded_len+=right.front(),right.pop();
			if(loaded_len || !left.empty())
				++times;
		}
		cout << times <<endl;
	}
}