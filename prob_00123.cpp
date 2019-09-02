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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,b,n) for(i=n;i>=b;i--)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define gc getchar_unlocked
using namespace std;

bool compare(pair<string,pair<int,string> > p1, pair<string,pair<int,string> > p2){
	if((p1.first < p2.first) ||(p1.first == p2.first && p1.second.first < p2.second.first))
		return true;
	return false;
}

int main(){
	map<string,bool> myMap;
	vector<pair<string,pair<int,string > > > vect;
	string str,buff,str2;
	int i,j,k;
	while(getline(cin,str), str!="::")
		myMap[str]=true;
	int index=1;
	while(getline(cin,str)){
		transform(str.begin(),str.end(),str.begin(),::tolower);
		int len= str.length();
		i=0;
		while(i<len){
			buff="";
			while(i<len && str[i]==' ')i++;
			j=i;
			while(i<len && str[i]!=' ')buff+=str[i++];
			if(myMap.find(buff)==myMap.end()){
				str2=str;
				transform(str2.begin()+j,str2.begin()+i,str2.begin()+j,::toupper);
				vect.push_back(make_pair(buff,make_pair(index,str2)));
			}
		}
		index++;
	}
	sort(vect.begin(),vect.end(),compare);
	for(vector<pair<string,pair<int,string> > >::iterator iter= vect.begin(), end= vect.end(); iter!= end;
		++iter)
		cout << iter->second.second <<endl;
}