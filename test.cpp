#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define vi vector<int>

using namespace std;
int main(){
    set<set<int> >comb;
    comb.insert(set<int>{1,2,3});
    comb.insert(set<int>{3,2,1});
    comb.insert(set<int>{2,3,1});
    cout << comb.size() <<endl;
}
