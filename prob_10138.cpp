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
#include <forward_list>
#define rep(i,a,b) for(i=a;i<b;++i)
#define vectIter(vect) for(auto &val: vect)
#define mapIter(map_) for(auto &val_: map_)
#define gc getchar_unlocked
using namespace std;
#define INF 999999999

class Date{
public:
	int dd, hh, mm, dist;
	bool enter_exit;
	Date(){
		dd= hh= mm= dist=INF;
	}

	Date(int dd_, int hh_, int mm_, int dist_,bool flag=true){
		dd= dd_;
		hh= hh_;
		mm= mm_;
		dist= dist_;
		enter_exit= flag;
	}

	bool operator<(const Date& d2)const{
		if(dd < d2.dd)
			return true;
		else if(dd==d2.dd){
			if(hh< d2.hh)
				return true;
			else if(hh==d2.hh && mm<d2.mm)
				return true;
		}
		return false;
	}
};


struct functor{
	bool operator()(const Date& d1,const Date& d2)const{
		return d1<d2;
	}
};

int main(){
	int n,mm,dd,hh,mmm,distance;
	int i,j,k;
	scanf("%d\n",&n);
	string str;
	string num_plate, enter_exit;
	char ch;

	int fare_map[25];
	map<string, set<Date,functor> > enter_records;

	while(n--){
		rep(i,0,24) scanf("%d",&fare_map[i]);

		getchar();
		while(getline(cin,str),str!=""){
			stringstream stream(str);
			stream >> num_plate >> mm >>ch >>dd >>ch
				   >> hh >>ch >> mmm >> enter_exit >> distance;
		
			Date date(dd,hh,mmm,distance);
			if(enter_exit=="exit")
				date.enter_exit=false;
			if(enter_records.find(num_plate)!=enter_records.end())
				enter_records[num_plate].insert(date);
			else enter_records[num_plate]=set<Date,functor>{date};
		}

		for(auto&val: enter_records){
			int cents=0;
			set<Date,functor> &temp= val.second;
			for(auto iter1=temp.begin(),iter2= iter1; iter1!=temp.end();++iter1){
				iter2=iter1;
				++iter2;
				if(iter2!=temp.end() && (iter1->enter_exit && !(iter2->enter_exit))){
					cents+=abs(iter2->dist - iter1->dist)*(fare_map[iter1->hh])+100;
					++iter1;
				}
			}

			if(cents)
				cout << val.first <<" $"<<fixed <<setprecision(2) <<(cents/100.0)+2 <<endl;
		}

		if(n)
			cout << endl;
		enter_records.erase(enter_records.begin(),enter_records.end());
	}
}