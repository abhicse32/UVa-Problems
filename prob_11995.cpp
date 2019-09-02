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
	int i,j,k,l;
	int t;
	priority_queue<int, vector<int> > pq;
	stack<int> st;
	queue<int> que;

	bool pq_flag=true, st_flag=true, que_flag=true;
	while(si(t)!=EOF){
		pq_flag= st_flag= que_flag= true;
		while(!que.empty()) que.pop();
		while(!st.empty()) st.pop();
		while(!pq.empty()) pq.pop();
		rep(i,0,t){
			sii(j,k);
			if(j==1){
				if(pq_flag) pq.push(k);
				if(st_flag) st.push(k);
				if(que_flag) que.push(k);
			}else{
				if(pq_flag){
					if(pq.empty() || pq.top()!=k)
						pq_flag= false;
					else pq.pop();
				}
				if(st_flag){
					if(st.empty() || st.top()!=k)
						st_flag= false;
					else st.pop();
				} 
				if(que_flag){
					if(que.empty() || que.front()!=k)
						que_flag= false;
					else que.pop();
				}
			}
		}
		if((pq_flag+ que_flag+st_flag) >= 2)
				printf("not sure\n");
		else if(!(pq_flag || st_flag || que_flag))
			printf("impossible\n");
		else if(st_flag) printf("stack\n");
		else if(que_flag) printf("queue\n");
		else printf("priority queue\n");
	}
}