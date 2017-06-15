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
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define gc getchar_unlocked
using namespace std;

vector<vector<char> > vect;

void func(string::iterator iter1, string::iterator end1,
		  string::iterator iter2, string::iterator end2,
		  stack<char> st, vector<char> vect_char){

	for(;iter1<end1;){
		if(st.top()==*iter2){
			stack<char> st2=st;
			st2.pop();	
			vector<char> vect_char2= vect_char;
			vect_char2.push_back('o');
			func(iter1,end1,iter2+1,end2,st2,vect_char2);
		}
		st.push(*iter1);
		vect_char.push_back('i');
		++iter1;
	}
	if(iter1==end1){
		while(iter2!=end2 && st.top()==*iter2)
			++iter2,st.pop(),
			vect_char.push_back('o');
		if(iter2==end2)
			vect.push_back(vect_char);
	}
	return;
}

int main(){
	string str1,str2;
	stack<char> st;
	while(cin >> str1 >> str2){
		cout <<"["<<endl;
		if(str1.size()==str2.size()){
			st.push('$');
			vector<char> vect_char;
			vect.erase(vect.begin(),vect.end());
			func(str1.begin(),str1.end(), str2.begin(),
				str2.end(),st,vect_char);
			sort(vect.begin(),vect.end());
			for(auto&val: vect){
				auto iter= val.begin(),end=val.end();
				cout <<*iter;
				for(++iter;iter!=end;++iter)
					cout <<" "<<*iter;
				cout <<endl;
			}
		}
		cout << "]" <<endl;
	}
}