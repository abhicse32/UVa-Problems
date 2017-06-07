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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,n,b) for(i=n;i>=b;i--)
#define vectIter(vect,T) for(vector<T>::iterator iter= vect.begin(), \
								end= vect.end(); iter!= end; ++iter)
#define mapIter(map_,T1,T2)  for(map<T1,T2>::iterator iter_= map_.begin(),  \
						end_= map_.end(); iter_ != end_; ++iter_)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define set(a,i) memset(a,i,sizeof a)
#define gc getchar_unlocked
#define size 26
using namespace std;
bool compare(int a, int b){
	return a > b;
}

int main(){
	int t,i;
	int t1,t2,final,attendance, ct[3];
	double total;
	si(t);
	repf(i,1,t+1){
		scanf("%d%d%d%d%d%d%d",&t1,&t2,&final,&attendance,&ct[0],&ct[1],&ct[2]);
		sort(ct,ct+3,compare);
		double ct_avg=(ct[0]+ct[1])/2.0;
		total=t1+t2+final+attendance+ct_avg;
		char grade='F';
		if(total>= 90)
			grade='A';
		else if(total>= 80)
			grade= 'B';
		else if(total>= 70)
			grade='C';
		else if(total >= 60)
			grade='D';
		printf("Case %d: %c\n",i,grade);
	}
}