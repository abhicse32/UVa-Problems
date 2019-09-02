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
	int i,j,k,l,n;
	map<string,int> freq;
	string str;
	vector<string> vect;
	scanf("%d\n",&n);
	while(n--){
		int Bits=0;
		while(getline(cin,str),str!=""){
			Bits+=str.size();
			vect.push_back(str);
		}

		int len= Bits/(vect.size()>>1);
		for(auto iter= vect.begin(),end= vect.end();iter!=end;++iter){
			for(auto iter1= iter; iter1!=end;++iter1){
				str= (*iter)+(*iter1);
				if(str.size()==len){
					if(freq.find(str)==freq.end())
						freq[str]= 1;
					else ++freq[str];
					str= (*iter1)+(*iter);
					
					if(freq.find(str)==freq.end())
						freq[str]= 1;
					else ++freq[str];
				}
			}
		}

		// cout << freq.size() <<endl;
		str= freq.begin()->first;
		for(auto& val:freq)
			if(val.second> freq[str])
				str= val.first;

		freq.erase(freq.begin(),freq.end());
		vect.erase(vect.begin(),vect.end());
		cout << str <<endl;
		if(n)
			cout <<endl;
	}
}