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
#define sll(a) scanf("%lld",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define set_(a,i) memset(a,i,sizeof a)
#define gc getchar_unlocked
using namespace std;

int main(){
	int i,j,k,x,y;
	vector<string> vect;
	while(si(k)>0){
		int times= (k<<1)+1;
		repf(i,k+1,times){
			int prod= i*k;
			if(prod%(i-k)==0)
				vect.push_back("1/"+to_string(k)+" = 1/"+to_string(prod/(i-k))+" + 1/"+to_string(i));		
		}
		cout << vect.size() <<endl;
		vectIter(vect,string)
			cout << *iter <<endl;
		vect.clear();
	}
}