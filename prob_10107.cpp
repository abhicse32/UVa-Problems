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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,n,b) for(i=n;i>=b;i--)
#define vectIter(vect,T) for(vector<T>::iterator iter= vect.begin(), \
								end= vect.end(); iter!= end; ++iter)
#define mapIter(map_,T1,T2)  for(map<T1,T2>::iterator iter_= map_.begin(),  \
						end_= map_.end(); iter_ != end_; ++iter_)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define gc getchar_unlocked
using namespace std;
#define size 10005
inline int fastRead(){
	int n=0;
	char ch;
	while((ch=gc())< '-')
		if(ch==EOF) 
			return EOF;
	int negFlag=(ch=='-'?-1:1);
	if (negFlag==1) n=(ch-'0');
	while((ch=gc())>='0')
		n=(n<<1)+(n<<3)+ch-'0';
	return negFlag*n;
}

bool comp(int i, int j){return i<j;}
int main(){
	int n=0,mid,i,first,second;
	int arr[size];
	while(si(arr[n])==1){
		n++;
		mid=(n>>1);
		if(n&1){
			nth_element(arr,arr+mid,arr+n);
			mid=arr[mid];
			// repf(i,0,n) cout << arr[i] <<" "; cout << endl;
		}else{
			nth_element(arr,arr+mid,arr+n);
			first=arr[mid];
			nth_element(arr,arr+mid-1,arr+n);
			second= arr[mid-1];
			mid=((first+second)>>1);
		}
		cout << mid <<endl;
	}
}