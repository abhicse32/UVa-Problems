#include <bits/stdc++.h>
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define gc getchar_unlocked
#define si(n) scanf("%d",&n)
#define sii(m,n) scanf("%d%d",&m,&n)
#define ssi(str,a) scanf("%s%d",str,&a)
#define sis(a,str) scanf("%d%s",&a,str)
#define ss(str) scanf("%s",str)
using namespace std;
#define INF 999999999
#define SIZE 10005
int main(){
	int m,n,t;
	int i,j,k,l;
	int arr1[SIZE], arr2[SIZE];
	si(t);
	while(t--){
		sii(m,n);
		rep(i,0,m) si(arr1[i]);
		rep(i,0,n) si(arr2[i]);
		sort(arr1,arr1+m);
		sort(arr2,arr2+n);
		i=j=k=0;
		while(i<m && j<n){
			if(arr1[i]==arr2[j])
				++i,++j;
			else{
				if(arr1[i]< arr2[j])++i;
				else ++j;
				++k;
			}
		}
		k+=(m-i);
		k+=(n-j);
		printf("%d\n",k);
	}
}