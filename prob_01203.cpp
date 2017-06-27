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

typedef struct Query{
	int q_num;
	int period;
	int next_occur;

	Query(int q_num_, int period_, int next_occur_=INF):
					q_num(q_num_), period(period_),
					next_occur(next_occur_){};

	void set_next_occur(int num){
		next_occur= num;
	}

	bool operator<(const struct Query& q1)const{
		if(next_occur > q1.next_occur) return true;
		else if(next_occur == q1.next_occur && q_num > q1.q_num)
			return true;
		return false;
	}

}query;

struct functor{
	bool operator()(const query& q1, const query& q2)const{
		if(q1.next_occur> q2.next_occur)
			return true;
		else if(q1.next_occur== q2.next_occur && q1.q_num > q2.q_num)
			return true;
		return false;
	}
};

int main(){
	int q_num, period,k;
	char str[10];
	// priority_queue<query, vector<query>, functor > pq; // could also have been used
	priority_queue<query,vector<query> > pq;
 	while(ss(str),str[0]!='#'){
 		sii(q_num,period);
 		pq.push(query(q_num,period,period));
 	}
 	si(k);
 	while(k--){
 		query q= pq.top();
 		pq.pop();
 		printf("%d\n",q.q_num);
 		q.set_next_occur(q.period+q.next_occur);
 		pq.push(q);
 	}
}