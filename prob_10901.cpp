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
	while(ch!='\n' && ch!=' ')
		command[i++]=ch,ch=gc();
	command[i]='\0';
}

int read_int(){
	int a=0;
	char ch;
	while((ch=gc())=='\n');
	while(ch!='\n' && ch!=' ')
		a=(a<<1)+(a<<3)+ch-48,
		ch=gc();
	return a;
}

int main(){
	int t,n,m,c;
	//n - number of cars ferry can carry at a time
	//t- time taken by the ferry to cross the river
	queue<pair<int,int> > right;
	queue<pair<int,int> > left;
	int arr[SIZE];
	int i,j,k;

	c= read_int();
	while(c--){
		memset(arr,0,sizeof(int)*SIZE);
		scanf("%d%d%d",&n,&t,&m);
		
		rep(i,0,m){
			j= read_int();
			read_string();
			if(command[0]=='l')
				left.push(make_pair(i,j));
			else right.push(make_pair(i,j));
		}

		int time=0;
		bool bank_flag= true; // true for left bank
		int front_;
		while(!right.empty() || !left.empty()){
			int next_car= (left.empty()?right.front().second:
						  right.empty()?left.front().second:
						  min(left.front().second,right.front().second));

			time= max(time,next_car);

		   	int counter=0;
			if(bank_flag){
				while(!left.empty() && left.front().second<= time && counter<n){
					arr[left.front().first]= time+t;
					left.pop();
					++counter;
				}
			}else{
				while(!right.empty() && right.front().second<= time && counter<n){
					arr[right.front().first]= time+t;
					right.pop();
					++counter;
				}
			}
			time+=t;
			bank_flag^=1;
		}

		rep(i,0,m)
			cout <<arr[i]<<endl;
		if(c)
			cout <<endl;	
	}
}