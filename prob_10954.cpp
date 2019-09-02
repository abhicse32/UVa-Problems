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
	int i,j,k,l,t;
	priority_queue<int,vector<int>, greater<int> > pq;

	while(si(t),t){
		rep(i,0,t) si(k), pq.push(k);

		int sum=0;
		while(pq.size()>1){
			int num1=pq.top(); pq.pop();
			int num2=pq.top(); pq.pop();
			num1+=num2;
			sum+=num1;
			pq.push(num1);
		}
		pq.pop();
		printf("%d\n",sum);
	}
}