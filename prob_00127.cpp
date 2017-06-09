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
vector<stack<string> > vect;

void func(vector<stack<string> >::iterator& iter, 
		vector<stack<string> >::iterator& iter1, 
		vector<stack<string> >::iterator& iter_1){
	
	iter_1->push(iter1->top());
	iter1->pop();
	if(iter1->empty()){
		iter1=vect.erase(iter1);
		--iter;
	}
	iter1=iter_1;
}

int main(){
	string str1,str2;
	int i;
	while(getline(cin,str1),str1!="#"){
		vect.erase(vect.begin(),vect.end());

		stringstream stream(str1);
		while(stream>>str2){
			stack<string> st; st.push(str2);
			vect.push_back(st);
		}
		getline(cin,str1);
		stream=stringstream(str1);
		while(stream>>str2){
			stack<string> st; st.push(str2);
			vect.push_back(st);
		}

		for(auto iter=vect.begin()+1;iter!=vect.end();++iter){
			
			for(auto iter1=vect.begin()+1;iter1<=iter;){
				string str= iter1->top();
				auto iter_1= iter1-1;
				auto iter_3= iter1-3;
				string str_1,str_3;
				if(iter_3>= vect.begin() && (iter_3->top()[0]==str[0] || 
					iter_3->top()[1]==str[1])){
					func(iter,iter1,iter_3);
				}else if(iter_1>=vect.begin() && (iter_1->top()[0]==str[0] || 
					iter_1->top()[1]==str[1])){
					func(iter,iter1,iter_1);
				}else ++iter1;
			}
		}

		int sz=vect.size();
		cout << sz <<" pile" <<(sz>1?"s":"") << " remaining:";
		for(auto& val: vect)
			cout <<" " <<val.size();
		cout <<endl;		
	}
}

// c++11 doesn't allow 'auto' type function parameters, whereas c++14 does