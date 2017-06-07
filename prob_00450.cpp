#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

class Record{
public:
	string title;
	string first_name;
	string last_name;
	string street_address;
	string home_phone;
	string work_phone;
	string campus_mailbox;
	string department;

	Record(string dept, string f_name, string l_name, 
			string title, string s_address, string h_phone,
			string w_phone, string c_mailbox):department(dept),
			title(title),first_name(f_name),last_name(l_name),
			street_address(s_address),home_phone(h_phone), work_phone
			(w_phone),campus_mailbox(c_mailbox){}

	Record(){}

	friend ostream& operator<<(ostream& os, Record& record){
		os << record.title <<" " <<record.first_name <<" "
		   << record.last_name<<endl;
		os << record.street_address <<endl;
		os << "Department: " << record.department <<endl;
		os << "Home Phone: " << record.home_phone <<endl;
		os << "Work Phone: " << record.work_phone <<endl;
		os << "Campus Box: " << record.campus_mailbox <<endl;
		return os;
	}

	bool operator<(Record& record){
		return last_name < record.last_name;
	}
};

int main(){
	int depts,i,j,k;
	string str;
	vector<Record> records;

	scanf("%d\n",&depts);
	while(getline(cin,str)){
		string department= str;
		while(getline(cin,str)){
			if(str.size()==0)
				break;
			Record record1;
			record1.department= department;
			size_t pos;
			string delimeter= ",";
			for(i=0;(pos=str.find(delimeter))!=string::npos;++i){
				string sub= str.substr(0,pos);
				str= str.substr(pos+1,string::npos);
				switch(i){
					case 0: record1.title= sub; break;
					case 1: record1.first_name= sub; break;
					case 2: record1.last_name= sub; break;
					case 3: record1.street_address= sub; break;
					case 4: record1.home_phone= sub; break;
					case 5: record1.work_phone= sub; break;
					default: break;
				}
			}
			record1.campus_mailbox= str;
			records.push_back(record1);
		}
	}
	sort(records.begin(), records.end());
	for(auto& val: records){
		cout <<"----------------------------------------\n";
		cout << val;
	}
}	

