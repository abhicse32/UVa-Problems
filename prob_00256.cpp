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
#include <set>
#include <bitset>
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,n,b) for(i=n;i>=b;i--)
#define vectIter(vect,T) for(vector<T>::iterator iter= vect.begin(), \
								end= vect.end(); iter!= end; ++iter)
#define mapIter(map_,T1,T2)  for(map<T1,T2>::iterator iter_= map_.begin(),  \
						end_= map_.end(); iter_ != end_; ++iter_)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define set_(a,i) memset(a,i,sizeof a)
#define gc getchar_unlocked
using namespace std;

vector<vector<int> > vect(5);
void precalc(){
	for(int i=2;i<=8;i+=2){
		int temp=(i>>1);
		int limit=pow(10,i);
		int divisor=pow(10,temp);
		for(int j=0;j<limit;j++){
			if(pow((j/divisor+j%divisor),2)==j)
				vect[temp].push_back(j);
		}
	}
}

int main(){
	int i,j,n;
	precalc();
	while(si(n)!=-1){
		vectIter(vect[(n>>1)],int)
			printf("%.*d\n",n,*iter);
	}
}