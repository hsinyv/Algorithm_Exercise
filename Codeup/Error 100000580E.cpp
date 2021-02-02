#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string del_char(string ini_s, char targ_c) {
	for (auto it = ini_s.begin(); it < ini_s.end();) {
		if (*it == targ_c) {
			ini_s.erase(it);
		}
		else it++;
	}
	return ini_s;
}
string del_char(string ini_s, char targ_c, int z) {
	string temp;
	for (auto it = ini_s.begin(); it < ini_s.end(); it++) {
		if (*it != targ_c) {
			temp += *it;
		}
	}
	return temp;
}
int main(void) {
	string s;
	char c; char a;
//	while (cin >> s) {
//		cin >> c;
//		cout << del_char(s,c,0) << endl;
//	}
	while(getline(cin, s)){
		cin >> c;
		cout << del_char(s,c,0) << endl;
	}
	return 0;
}
