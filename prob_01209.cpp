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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,b,n) for(i=n;i>=b;i--)
#define vectIter(vect,T) for(vector<T>::iterator iter= vect.begin(), \
								end= vect.end(); iter!= end; ++iter)
#define mapIter(map_,T1,T2)  for(map<T1,T2>::iterator iter_= map_.begin(),  \
						end_= map_.end(); iter_ != end_; ++iter_)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define gc getchar_unlocked
using namespace std;

int getMax(string str, int len){
	int i,dist=INT_MAX,j;
	repf(i,1,len)
		dist=min(dist, abs(str[i]-str[i-1]));
	return dist;
}

int main(){
	string str,str2;
	int i,j,k;
	while(getline(cin,str)){
		int len= str.length();
		repf(i,0,10)
			prev_permutation(str.begin(),str.end());
		k=0;
		repf(i,0,21){
			j = getMax(str,len); 
			if(k< j){
				k=j;
				str2= str;
			}
			next_permutation(str.begin(), str.end());
		}
		cout << str2 <<k <<endl;
	}
}