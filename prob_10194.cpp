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
#define repf(i,b,n) for(i=b;i<n;i++)
#define repb(i,n,b) for(i=n;i>=b;i--)
#define vectIter(vect,T) for(vector<T>::iterator iter= vect.begin(), \
								end= vect.end(); iter!= end; ++iter)
#define mapIter(map_,T1,T2)  for(map<T1,T2>::iterator iter_= map_.begin(),  \
						end_= map_.end(); iter_ != end_; ++iter_)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b) 
#define gc getchar_unlocked
using namespace std;
#define size 10005

typedef struct team_info{
	string name;
	int pts_earned=0;
	int wins=0;
	int ties=0;
	int goals_scored=0;
	int goals_against=0;
	int games_played=0;
}team;

inline int fastRead(){
	int n=0;
	char ch;
	while((ch=gc())< '-')
		if(ch==EOF) 
			return EOF;
	int negFlag=(ch=='-'?-1:1);
	if (negFlag==1) n=(ch-'0');
	while((ch=gc())>='0')
		n=(n<<1)+(n<<3)+ch-'0';
	return negFlag*n;
}

bool compare(team t1, team t2){
	int diff1= t1.goals_scored - t1.goals_against;
	int diff2= t2.goals_scored - t2.goals_against;
	if(t1.pts_earned > t2.pts_earned)
		return true;
	else if(t1.pts_earned == t2.pts_earned){
		if(t1.wins > t2.wins)
			return true;
		else if(t1.wins == t2.wins){
			if(diff1 > diff2){
				return true;
			}else if(diff1 == diff2){
				if(t1.goals_scored > t2.goals_scored)
					return true;
				else if(t1.goals_scored == t2.goals_scored){
					if(t1.games_played < t2.games_played)
						return true;
					else if(t1.games_played == t2.games_played){
						string team1= t1.name, team2= t2.name;
						transform(team1.begin(), team1.end(), team1.begin(),::tolower);
						transform(team2.begin(),team2.begin(),team2.begin(),::tolower);
						return (team1 < team2);
					}
				}
			}
		}
	}
	return false;
}

void add(team &team1, int scored, int against){
	if(scored > against){
		team1.pts_earned+=3;
		team1.wins++;
	}else if(scored==against){
		team1.pts_earned+=1;
		team1.ties++;
	}
	team1.goals_scored+=scored;
	team1.goals_against+=against;
	team1.games_played++;
}

int main(){
	char team_name[35], match[500];
	string tournament;
	int n;
	int n_teams, i,j,k,l,matches;
	char *delimiters="#@";
	map<string,int> team_map;
	cin >> n;
	cin.get();
	while(n--){
		getline(cin,tournament);
		cout << tournament <<endl;
		cin >> n_teams;
		cin.get();
		team teams[n_teams];
		repf(i,0,n_teams){
			getline(cin,teams[i].name);
			team_map[teams[i].name] = i;
		}
		// cout << team_map["Scotland"] <<endl;
		cin >> matches;
		cin.get();
		repf(i,0,matches){
			cin.getline(match,500);
			char* temp1= strtok(match,delimiters);	
			int goal_s= atoi(strtok(NULL,delimiters));
			int goal_a= atoi(strtok(NULL,delimiters));
			char* temp2= strtok(NULL,delimiters);
			int idx1= team_map[temp1], idx2= team_map[temp2];
			add(teams[idx1],goal_s,goal_a);
			add(teams[idx2],goal_a,goal_s);
		}
		sort(teams,teams+n_teams,compare);
		repf(i,0,n_teams){
			cout << i+1 <<") " << teams[i].name <<" " << teams[i].pts_earned<<"p, "
			     << teams[i].games_played<<"g (" << teams[i].wins <<"-" 
			     << teams[i].ties <<"-" << teams[i].games_played - (teams[i].ties + teams[i].wins)<<"), "
			     << teams[i].goals_scored - teams[i].goals_against <<"gd (" <<teams[i].goals_scored 
			     <<"-" << teams[i].goals_against <<")\n";  
		}
		team_map.clear();
		if(n)
			cout << endl;
	}
}
