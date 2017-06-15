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
#define SIZE 1005

int main(){
	int i,j,k,l;
	char str[SIZE];
	vector<char> vect;
	for(l=1;scanf("%s",str),str[0]!='e';++l){
		int len= strlen(str);
		vect.erase(vect.begin(),vect.end());
		vect.push_back(str[0]);
		rep(i,1,len){
			k=vect.size();
			int min=0;
			char ch= 'Z'+1;
			rep(j,0,k){
				if(vect[j]>=str[i] && vect[j]<ch)
					min= j,ch=vect[j];
			}
			if(vect[min]>= str[i])
				vect[min]= str[i];
			else vect.push_back(str[i]);
		}
		cout <<"Case "<<l<<": ";
		cout << vect.size() <<endl;
	}
}