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
	int i,j,k,l=0;
	int r,c,n;
	bitset<10005> rows, cols;
	while(scanf("%d%d%d",&r,&c,&n)){
		if(!r && !c && !n)
			break;
		rows.reset(); cols.reset();
		// cout << rows <<endl;
		repf(k,0,n){
			sii(i,j);
			rows[i]= cols[j]=1;
		}
	//	cout << rows <<endl;
		sii(i,j);
		bool flag=false;
		if(rows[i]==0 && cols[j]==0) flag=true;
		else if(i+1<r && rows[i+1]==0 && cols[j]==0) flag=true;
		else if(i>=1 && rows[i-1]==0 && cols[j]==0) flag=true;
		else if(j+1 < c && rows[i]==0 && cols[j+1]==0) flag= true;
		else if(j>=1 && rows[i]==0 && cols[j-1]==0) flag=true;
		if ( flag )
            printf ("Case %d: Escaped again! More 2D grid problems!\n", ++l);
        else
            printf ("Case %d: Party time! Let's find a restaurant!\n", ++l);

	}
}