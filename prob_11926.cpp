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
#define size 1000005
#define limit 1000000
using namespace std;

int main(){
	int n,m,i,j,k;
	int start,end,interval;
	bitset<size> b;
	while(sii(n,m)!=EOF){
		if(n==0 && m==0)
			break;
		b.reset();
		bool conflict=false;
		repf(i,0,n){
			sii(start,end);
			if(!conflict){
				repf(j,start+1,end+1){
					if(b[j]==1){
						conflict=true;
						break;
					} else b[j]=1;
				}
			}
		}
		repf(i,0,m){
			scanf("%d%d%d",&start,&end,&interval);
			if(!conflict){
				while(start<= limit){
					for(j=start+1;j<=min(end,limit);j++){
						if(b[j]==1){
							conflict=true; break;
						}else b[j]=1;
					}
					start+=interval;
					end+=interval;
				}
			}
		}
		if ( conflict ) printf ("CONFLICT\n");
        else printf ("NO CONFLICT\n");
	}
}