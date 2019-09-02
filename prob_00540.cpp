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

void read_command(){
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

class Node{
	public:
		int data;
		Node* next;
		Node(int ele){
			data= ele;
			next= NULL;
		}
};

class List{
public:
	Node* head;
	List(){
		head= NULL;
	}

	Node* insert_after(Node** iter,int data){
		Node* node= new Node(data);
		if(head==NULL)
			head= node;
		else{
			Node* next_= (*iter)->next;
			(*iter)->next= node;;
			node->next= next_;
		}
		return node;
	}

	void pop_front(){
		if(head==NULL)
			return;
		Node* temp= head;
		head= head->next;
		delete temp;
	}
};

int main(){
	int n,i,j,k,l=1;
	int team_members[SIZE];
	List que;
	map<int,Node*> last_member;
	
	while((n=read_int())!=0){
		memset(team_members,0,sizeof(int)*SIZE);
		rep(i,1,n+1){
			j=read_int();
			rep(k,0,j)
				team_members[read_int()]=i;
		}
		que.head= NULL;
		cout <<"Scenario " <<"#"<<l <<endl;
		Node* last=que.head;
		while(read_command(), command[0]!='S'){
			if(command[0]=='E'){
				j= read_int();
				int team=team_members[j];
				if(last_member.find(team)==last_member.end())
					last_member[team]= last= que.insert_after(&last,j);
				else{
					Node* temp= last_member[team];
					last_member[team]= que.insert_after(&last_member[team],j);
					if(last==temp)
						last= last_member[team];
				}
			}else{
				int top= que.head->data;
				cout << que.head->data<<endl;
				if(last_member[team_members[top]]==que.head)
					last_member.erase(team_members[top]);
				que.pop_front();
				if(que.head==NULL)
					last=NULL;
			}
		}
		cout <<endl;
		last_member.erase(last_member.begin(),last_member.end());
		while(que.head)
			que.pop_front();
		++l;
	}
}