#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(){
	set<vector<string>> s;
	vector<string> res;
	res.push_back("harshal");
	res.push_back("shebin");
	s.insert(res);
	return 0;
}
