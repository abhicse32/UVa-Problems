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
#define SIZE 1000005
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

bool check_if_unloaded(queue<int> stations[105], int N){
	int i;
	rep(i,1,N+1){
		if(!stations[i].empty())
			return false;
	}
	return true;
}

int main(){
	int set,N,S,Q;
	int i,j,k;
	set= read_int();
	queue<int> stations[105];
	stack<int> carrier;
	while(set--){
		int time=0;
		bool flag=true;

		scanf("%d%d%d",&N,&S,&Q);
		rep(i,1,N+1){
			k= read_int();
			rep(j,0,k)
				stations[i].push(read_int());
		}

		while(flag){
			rep(i,1,N+1){
				while(!carrier.empty()){
					if(carrier.top()!=i){
						if(stations[i].size()<Q)
							stations[i].push(carrier.top());
						else break;
					}
					carrier.pop();
					++time;
				}
				
				while(carrier.size()<S && !stations[i].empty()){
					carrier.push(stations[i].front());
					stations[i].pop();
					++time;
				}

				if(!check_if_unloaded(stations,N) || !carrier.empty())
					time+=2;
				else{
					flag= false;
					break;
				}
			}
		}
		cout << time <<endl;
	}
}
