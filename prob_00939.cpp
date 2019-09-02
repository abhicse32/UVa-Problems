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

int main(){
	int i,j,k,n;
	string str1, str2;
	scanf("%d",&n);
	map<string, string> person_disease;
	map<string, vector<string> > person_person;

	while(n--){
		cin >> str1 >> str2;
		if(str2=="non-existent" || str2=="recessive" || str2=="dominant")
			person_disease[str1]= str2;
		else{
			if(person_person.find(str2)==person_person.end())
				person_person[str2]= vector<string>{str1};
			else person_person[str2].push_back(str1);
		}
	}

	while(person_person.size()){
		for(auto iter= person_person.begin(); iter!= person_person.end();){
			string parent1= iter->second[0];
			string parent2= iter->second[1];
			string name= iter->first;
			// cout << parent1 <<" " << parent2 <<endl;
			if(person_disease.find(parent1)!= person_disease.end() && 
				person_disease.find(parent2)!= person_disease.end()){
				// cout <<"came here\n";
				unsigned char p1_d= person_disease[parent1][0];
				unsigned char p2_d= person_disease[parent2][0];
				if((p1_d!='n' && p2_d!='n') || (p1_d=='d' || p2_d=='d')){
					if( (p1_d+ p2_d == ('d'<<1)) || (p1_d+p2_d== 'r'+'d'))
						person_disease[name]="dominant";
					else person_disease[name]="recessive";

				}else person_disease[name]="non-existent";
				iter= person_person.erase(iter);

			}else ++iter;
		}
	}

	for(auto& val: person_disease)
		cout << val.first <<" "<< val.second <<endl;
}