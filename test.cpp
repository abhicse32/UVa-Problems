#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main ()
{
    string str1="ABCD",str2="ACERT";
    int count=0;
    auto iter= str1.begin();
    for_each(str2.begin(),str2.end(),[&iter,&count](auto &iter2){if(*iter==iter2) ++count;++iter;});
    cout << count <<endl;
    return 0;
}
