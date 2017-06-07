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
	int N,i,counter=0;
	int a,b,c,d,e,f;
	int arr[20];
	while(si(N),N){
		repf(i,0,N)si(arr[i]);
		if(counter)
			printf("\n");
		counter++;
		repf(a,0,N-5){
			repf(b,a+1,N-4){
				repf(c,b+1,N-3){
					repf(d,c+1,N-2){
						repf(e,d+1,N-1){
							repf(f,e+1,N)
								printf("%d %d %d %d %d %d\n",arr[a],arr[b],arr[c],arr[d],arr[e],arr[f]);
						}
					}
				}
			}
		}
	}
}