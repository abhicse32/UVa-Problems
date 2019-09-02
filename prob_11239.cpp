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

struct functor{
	bool operator()(const pair<string,int>& p1, 
		const pair<string,int>& p2)const{
		if(p1.second > p2.second)
		return true;
		else if(p1.second==p2.second && p1.first < p2.first)
			return true;
		return false;
	}
};

int main(){
	int i,j,k,l;
	string str;
	map<string,set<string> > projects;
	map<string,set<string> > students;
	getline(cin,str);
	while(str!="0"){
		if(str[0]!='1'){	
			string str2;
			projects[str]=set<string>{};
			while(getline(cin,str2),str2[0]>='a'){
				projects[str].insert(str2);
				students[str2].insert(str);
			}
			str=str2;
		}else{
			for(auto iter= projects.begin(), end= projects.end(); iter!=end;++iter){
				set<string>& temp_students= iter->second;
				for(auto iter2= temp_students.begin();iter2!=temp_students.end();){
					if(students[*iter2].size()>1)
						iter2= temp_students.erase(iter2);
					else ++iter2;
				}
			}

			set<pair<string,int>, functor> vect;
			for(auto&val: projects)
				vect.insert(make_pair(val.first,val.second.size()));
			for(auto& val: vect)
				cout<< val.first <<" "<< val.second <<endl;
			projects.erase(projects.begin(),projects.end());
			students.erase(students.begin(),students.end());
			getline(cin,str);
		}
	}
}