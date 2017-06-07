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
	int n,x,y,z;
	int A,B,C;
	int temp1,temp2,temp3;
	si(n);
	while(n--){
		sii(A,B); si(C);
		bool sol=false;
		for(x=-22; x<=22 && !sol; x++){
			if((temp1=(x*x))<=C){
				for(y=-100; y<=100 && !sol; y++){
					if(y!=x && (temp3=(temp1+y*y))<=C){
						for(z=-100;z<=100 && !sol;z++){
							if(z!=x && z!=y && x+y+z==A && x*y*z==B &&
								temp3+(z*z)==C){
								printf("%d %d %d",x,y,z);
								sol=true;
							}
						}
					}
				}
			}
		}
		if(!sol)
			printf("No solution.");
		
			printf("\n");
	}
}