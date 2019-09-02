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
#define si(n) scanf("%d",&n)
#define sii(m,n) scanf("%d%d",&m,&n)
#define ssi(str,a) scanf("%s%d",str,&a)
#define sis(a,str) scanf("%d%s",&a,str)
#define ss(str) scanf("%s",str)
using namespace std;
#define INF 999999999

char convert(char ch){
	if(ch=='-') return '-';
	else if(isalpha(ch)) return tolower(ch);
	else return ' ';
}

int main(){
	int i,j,k;
	string str;
	set<string> dict;
	while(getline(cin,str)){
		string str2="";
		while(str[str.size()-1]=='-'){
			str.erase(str.size()-1);
			transform(str.begin(),str.end(),str.begin(),convert);
			str2+=str;
			getline(cin,str);
		}
		transform(str.begin(),str.end(),str.begin(),convert);
		str2+=str;
		stringstream stream(str2);
		while(stream >> str)
			dict.insert(str);
	}
	vectIter(dict) cout << val <<endl;
}