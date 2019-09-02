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

struct functor{
	bool operator()(const int& val1, const int& val2)const{
		return val1>=val2;
	}
};

int main(){
	multiset<int,functor> green, blue;
	int i,j,k,n,b,sb,sg;
	si(n);
	while(n--){
		si(b);
		sii(sg,sb);
		// printf("%d %d\n",sg,sb);
		rep(i,0,sg)
			si(k), green.insert(k);
		rep(i,0,sb)
			si(k), blue.insert(k);
		vector<int> vect_green, vect_blue;
		
		while(!blue.empty() && !green.empty()){
			auto iter2= blue.begin(), end1= green.end(),
				 iter1= green.begin(), end2= blue.end();

			for(i=0;i<b && iter1!=end1 && iter2!=end2;++i,++iter1,++iter2){
				if(*iter1> *iter2)
					vect_green.push_back(*iter1 - *iter2);
				else if(*iter2 > *iter1)
					vect_blue.push_back(*iter2 - *iter1);
			}
			green.erase(green.begin(),iter1);
			blue.erase(blue.begin(), iter2);
			vectIter(vect_green)
				green.insert(val);
			vectIter(vect_blue)
				blue.insert(val);
			vect_green.erase(vect_green.begin(), vect_green.end());
			vect_blue.erase(vect_blue.begin(), vect_blue.end());
		}
		if(green.empty() && blue.empty())
			printf("green and blue died\n");
		else if(green.empty() && !blue.empty()){
			printf("blue wins\n");
			vectIter(blue) printf("%d\n",val);
		}
		else {
			printf("green wins\n");
			vectIter(green) printf("%d\n",val);
		}
		if(n)
			printf("\n");

		green.erase(green.begin(),green.end());
		blue.erase(blue.begin(), blue.end());
	}
}