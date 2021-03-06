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
	int i,j,used,temp,count=0;
	int N;
	while(si(N)){
		if(!N)
			break;
		if(count>0)
			printf("\n");
		count++;
		int limit= 98765/N;
		bool flag=false;
		repf(i,1234,limit+1){
			j=i*N;
			used=(i<10000);
			temp= i; 
			while(temp){
				used|=(1<<(temp%10));
				temp/=10;
			} temp=j;
			while(temp){
				used |=(1<<(temp%10));
				temp/=10;
			}
			if((1<<10)-1 == used){
				printf("%.5d / %.5d = %d\n",j,i,N);
				flag=true;
			}
		}
		if(!flag)
			printf("There are no solutions for %d.\n",N);
	}
}