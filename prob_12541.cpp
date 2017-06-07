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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,n,b) for(i=n;i>=b;i--)
#define vectIter(vect,T) for(vector<T>::iterator iter= vect.begin(), \
								end= vect.end(); iter!= end; ++iter)
#define mapIter(map_,T1,T2)  for(map<T1,T2>::iterator iter_= map_.begin(),  \
						end_= map_.end(); iter_ != end_; ++iter_)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define set(a,i) memset(a,i,sizeof a)
#define gc getchar_unlocked
#define price 5000000
using namespace std;
class Person{
	public:
		string name;
		int day, month, year;
		Person(string n, int d, int m, int y){
			name= n; day= d;
			month= m; year= y;
		}
};

bool compare(Person p1, Person p2){
	if(p1.year < p2.year)
		return true;
	else if(p1.year == p2.year){
		if(p1.month < p2.month)
			return true;
		else if(p1.month==p2.month){
			if(p1.day < p2.day)
				return true;
		}
	}
	return false;
}

int main(){
	int t,dd,mm,yyyy,i;
	string name;
	si(t);
	vector<Person> vect;
	repf(i,0,t){
		cin >> name >> dd >> mm >> yyyy;
		vect.push_back(Person(name,dd,mm,yyyy));
	}
	sort(vect.begin(), vect.end(),compare);
	cout << vect[t-1].name <<endl;
	cout << vect[0].name <<endl;
}	