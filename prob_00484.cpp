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
#define SIZE 10005
#define INF 999999999

int main(){
	int i,j,k,l;
	map<int,int> my_map;
	vector<int> vect;
	while(scanf("%d",&i)!=-1){
		if(my_map.find(i)==my_map.end()){
			vect.push_back(i);
			my_map[i]=1;
		}else ++my_map[i];
	}
	for(auto& val: vect){
		cout << val<<" "<< my_map[val] <<endl;
	}
}