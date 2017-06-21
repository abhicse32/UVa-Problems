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
#include <set>
#include <forward_list>
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define gc getchar_unlocked
using namespace std;
#define INF 999999999

class Problem{
public:
	string name;
	set<string> words;
	int diff;
	Problem(string name,set<string>& words, int diff){
		this->name= name;
		this->words= words;
		this->diff= diff;
	}
};

int main(){
	int i,j,k,l;
	int n,w,c,x;
	scanf("%d",&n);
	vector<Problem> database;
	string str,str2;
	set<string> text_map;
	while(n--){
		scanf("%d",&c);
		rep(j,0,c){
			cin >> str >> w >> x;
			set<string>vect;
			rep(i,0,w){
				cin >> str2;
				vect.insert(str2);
			}
			Problem p(str,vect,x);
			database.push_back(p);
		}
		cin.ignore(100,'\n');
		while(getline(cin,str),str!=""){
			int len= str.length();
			for(i=0;i<len;++i)
				if(!isalpha(str[i]))
					str[i]=' ';
			//cout << str <<endl;
			stringstream stream(str);
			while(stream>> str2)
				text_map.insert(str2);
		}
		// cout << c <<endl;
		bool flag= false;
		for(int i=0;i<c;++i){
			set<string>& vect= database[i].words;
			int count=0;
			for(auto& val1: vect)
				if(text_map.find(val1)!=text_map.end())
					++count;
	
			if(count>= database[i].diff){
				if(flag)
					cout << ","<<database[i].name;
				else cout << database[i].name;
				flag= true;
			}
		}
		if(!flag)
			cout << "SQF Problem.";
		cout <<endl;
		database.erase(database.begin(),database.end());
		text_map.erase(text_map.begin(),text_map.end());
	}
}