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
	int a[3],b[3],c[3],i;
	map<char,int>myMap;
	myMap['B']=0; myMap['G']=1; myMap['C']=2;

	while(scanf("%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2],&c[0],&c[1],&c[2])!=-1){
		string str="BCG",temp_str="BCG";
		int sum=INT_MAX;
		do{
			int temp=0;
			for(i=0;i<3;i++){
				switch(i){
					case 0: 
						switch(str[i]){
							case 'B': temp+=(b[0]+c[0]); break;
							case 'G': temp+=(b[1]+c[1]); break;
							case 'C': temp+=(b[2]+c[2]); break;
						}
						break;
					case 1:
						switch(str[i]){
							case 'B': temp+=(a[0]+c[0]); break;
							case 'G': temp+=(a[1]+c[1]); break;
							case 'C': temp+=(a[2]+c[2]); break;
						}
						break;
					case 2:
						switch(str[i]){
							case 'B': temp+=(b[0]+a[0]); break;
							case 'G': temp+=(b[1]+a[1]); break;
							case 'C': temp+=(b[2]+a[2]); break;
						}
						break;
					default: break;
				}
			}
			if(sum>temp){
				sum= temp;
				temp_str= str;
			}
		}while(next_permutation(str.begin(),str.end()));
		cout << temp_str<<" " << sum <<endl;
	}
}