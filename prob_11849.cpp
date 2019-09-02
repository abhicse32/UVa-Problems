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

int main(){
	int i,j,k,l,m,n;
	map<int,bool> cds;
	while(sii(m,n),(m && n)){
		l=0;
		rep(i,0,m)
			si(k), cds[k]=true;
		rep(i,0,n){
			si(k);
			if(cds.find(k)!=cds.end())
				++l;
		}
		cds.erase(cds.begin(),cds.end());
		printf("%d\n",l);
	}
}