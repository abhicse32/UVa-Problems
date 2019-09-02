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
	bool operator()(const char* str1, const char* str2){
		return strcmp(str1,str2)<0;
	}
};

int main(){
	int m,n;
	int i,j,k;
	scanf("%d%d",&m,&n);
	map<string,int> salary;
	string str;
	while(m--){
		cin >> str >> k;
		salary[str]=k;
	}
	while(n--){
		int sal=0;
		while(getline(cin,str),str!="."){
			stringstream stream(str);
			while(stream>> str){
				sal+=salary[str];
			}
		}
		cout << sal <<endl;
	}
}