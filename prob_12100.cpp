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

int read_int(){
	int a=0;
	char ch;
	while((ch=gc())=='\n');
	while(ch!='\n' && ch!=' ' && ch!=EOF)
		a=(a<<1)+(a<<3)+ch-48,
		ch=gc();
	return a;
}

int main(){
	int t,n,m,i,j,k;
	scanf("%d",&t);
	queue<pair<int,int> > que;
	while(t--){
		scanf("%d%d",&n,&m);
		rep(i,0,n)
			que.push(make_pair(i,read_int()));
		
		int time=0;
		while(true){
			queue<pair<int,int> >temp;
			pair<int,int> p= que.front();
			que.pop();
			bool flag=false;
			while(!que.empty()){
				if(que.front().second>p.second)
					flag=true;
				temp.push(que.front());
				que.pop();
			}
			if(flag)
				temp.push(p);
			else{
				++time; 
				if(p.first==m)
					break;
			}
			que=temp;
		}
		cout << time <<endl;
		while(!que.empty()) que.pop();
	}
}