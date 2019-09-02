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

int main(int argc, char* argv[]){
	string str;
	list<char> lst;
	int i,j,k;
	while(getline(cin,str)){
		lst.clear();
		auto iter=lst.begin();
		for(auto& val: str){
			if(val=='[')
				iter=lst.begin();
			else if(val==']')
				iter=lst.end();
			else lst.insert(iter,val);
		}
		string str1(lst.begin(),lst.end());
		cout << str1 <<endl;
	}
}