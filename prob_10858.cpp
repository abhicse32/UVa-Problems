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
#include <list>
#include <set>
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define vi vector<int>
#define vii vector<vi>
#define gc getchar_unlocked
using namespace std;
#define SIZE 2000005

vi primes;
set<map<int,int> > unique_factorizations;

void sieve(){
	int sqrt_=sqrt(SIZE)+10;
	bool* arr= new bool[sqrt_];
	int i,j,k;
	rep(i,2,sqrt_){
		if(!arr[i]){
			primes.push_back(i);
			for(j=(i<<1);j<sqrt_;j+=i)
				arr[j]= true;
		}
	}
}

void get_factors(map<int,int> & factors, int n){
	int sz= primes.size();
	for(int i=0;n!=1 && i<sz;){
		if(n%primes[i]==0){
			if(factors.find(primes[i])!=factors.end())
				++factors[primes[i]];
			else factors[primes[i]]=1;
			n/=primes[i];
		}
			
		else ++i;
	}
	if(n!=1)
		factors[n]=1;
}

void generate_factorizations(map<int,int> factors){
	if(factors.size()==0 ||(factors.size()==1 
		&& factors.begin()->second<=1))
		return;

	unique_factorizations.insert(factors);
	for(auto iter1=factors.begin(),end= factors.end(); iter1!=end;++iter1){
		map<int,int> temp_map= factors;
		int top= iter1->first;
		--temp_map[top];
		auto iter2=iter1;		
		if(!temp_map[top]){
			++iter2;
			temp_map.erase(top);
		}
		
		for(;iter2!= factors.end();++iter2){
			map<int,int> map_=temp_map;
			int top2= iter2->first;
			--map_[top2];
			if(map_[top2]==0)
				map_.erase(top2);
			int num= top * top2;
			if(map_.find(num)==map_.end())
				map_[num]=1;
			else ++map_[num];
			if(unique_factorizations.find(map_)==unique_factorizations.end())
				generate_factorizations(map_);
		}
	}
}

int main(){
	sieve();
	int n,i,j,k;
	map<int,int> factors;
	while(scanf("%d",&n),n){
		get_factors(factors,n);
		generate_factorizations(factors);
		set<vector<int> > set_;
		for(auto&val:unique_factorizations){
			vector<int> vect;
			for(auto&val1:val)
				rep(i,0,val1.second)
					vect.push_back(val1.first);
			set_.insert(vect);
		}
		cout << set_.size() <<endl;
		for(auto&val:set_){
			auto iter=val.begin(),end= val.end();
			cout << *iter;
			for(++iter;iter!=end;++iter)
				cout <<" "<< *iter;
			cout <<endl;
		}
		factors.erase(factors.begin(),factors.end());
		unique_factorizations.erase(unique_factorizations.begin(),
			unique_factorizations.end());
	}
}