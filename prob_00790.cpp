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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,b,n) for(i=n;i>=b;i--)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define gc getchar_unlocked
using namespace std;

typedef struct Problem{
	string prob;
	long long time_=0;
	int N=0;
	int Y=0;
}problem;

long long getTime(string str){
	size_t pos=str.find(":");
	string hrs_= str.substr(0,pos);
	string mins_= str.substr(pos+1);
	long long t=stoll(hrs_)*60 + stoll(mins_);
	return t;
}
int find(vector<problem> vect, string prob_){
	int len= vect.size();
	for(int i=0;i<len;i++)
		if(vect[i].prob == prob_)
			return i;
	return -1;
}

bool compare(pair<int,pair<int,string> > p1, pair<int,pair<int, string> >p2){
	if((p1.first > p2.first)||(p1.first==p2.first && p1.second.first > p2.second.first))
		return true;
	return false;
}

int main(){
	string str,buff;
	string user, prob, t,Y_N;
	vector<string> vect;
	map<string,vector<problem> > myMap;
	while(getline(cin,str))
		vect.push_back(str);
	for(vector<string>::iterator iter= vect.begin(), end= vect.end();
					iter!= end; ++iter){
		str= *iter;
		stringstream ss(str);
		ss >> user; ss >> prob; ss >> t ; ss >> Y_N;
		problem prob_;
		prob_.prob= prob;
		if(Y_N=="N")
			prob_.N=1;
		else{
			prob_.Y= 1;
			prob_.time_= getTime(t);
		}
		if(myMap.find(user)!=myMap.end()){
			int index= find(myMap[user],prob);
			if(index!=-1){
				prob_.N+=myMap[user][index].N;
				myMap[user][index]= prob_;
			}else myMap[user].push_back(prob_);
		}else
			myMap[user]= vector<problem>{prob_};
	}
	vector<pair<int, pair<int,string> > > teams;
	for(map<string,vector<problem> >::iterator iter= myMap.begin(), end= myMap.end();
							iter!= end; ++iter){
		//cout << iter->first <<" ";
		int solved=0, t=0;
		vector<problem> vect= iter->second ;
		for(vector<problem>::iterator iter_= vect.begin(), end_= vect.end();
					iter_!= end_; ++iter_){
			if(iter_->Y){
				t += (iter_->time_) + (iter_->N)*20;
				solved++;
			}
		}
		teams.push_back(make_pair(solved,make_pair(t,iter->first)));
	}
	cout << "RANK TEAM PRO/SOLVED TIME\n";
	sort(teams.begin(), teams.end(),compare);
	for(int j=1;j<=teams.size();++j){
		int i=j-1;
		cout << setw(4) <<right << j <<" ";
		cout << setw(4) <<right << teams[i].second.second <<" ";
		if(teams[i].first)
			cout << setw(4) <<right << teams[i].first
		     << setw(11) << right << teams[i].second.first;
		 cout <<endl;
		//cout << teams[i].first <<" "  << teams[i].second.first <<" " << teams[i].second.second <<endl;
	}
}