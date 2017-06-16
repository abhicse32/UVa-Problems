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
#define gc getchar_unlocked
using namespace std;
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

struct Generator {
    Generator() : m_value( 1 ) { }
    int operator()() { return m_value++; }
    int m_value;
};

int main(){
	int i,j,k;
	int n;
	queue<int> discarded;
	while((n=read_int())){
		deque<int> deq(n);
		generate(deq.begin(), deq.end(),Generator());
		
		while(deq.size()>1){
			discarded.push(deq.front());
			deq.pop_front();
			deq.push_back(deq.front());
			deq.pop_front();
		}
		cout << "Discarded cards:";
		if(!discarded.empty())
			cout <<" " << discarded.front(), discarded.pop();
		while(!discarded.empty())
			cout <<", " << discarded.front(), discarded.pop();
		cout << endl;
		cout <<"Remaining card: " << deq.front();
		deq.pop_front();
		cout <<endl;
	}
}