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

int main(){
	int t,i,j,m,n,k;
	si(t);
	while(t--){
		sii(n,m);
		bitset<1030> b;
		b.set();
		repf(i,0,m){
			si(k); b[k]=0;
		}
		int wo=0,res_index;
		n=(1<<n);
		//	cout << b <<endl;
		while(n){
			res_index=1;
			for(i=2;i<=n;i+=2){
				wo+=(b[i-1]^b[i]);
				b[res_index++]=(b[i-1]|b[i]);
			}
			n>>=1;
		}
		cout << wo <<endl;
	}
}