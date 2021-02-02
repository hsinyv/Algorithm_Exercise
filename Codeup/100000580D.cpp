#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>
#include <iomanip>
using namespace std;

string word_swab(string ini_s, string targ_s, string swab_s) {
	vector<string> split_s;
	string temp;
	ini_s += " ";
	for (int i = 0; i < ini_s.size(); i++) {
		if (ini_s[i] == ' ') {
			split_s.push_back(temp);
			temp.clear(); 
		}
		else {
			temp += ini_s[i];
		}
	}
	for (int i = 0; i < split_s.size(); i++) {
		if (split_s[i] == targ_s) {
			split_s[i] = swab_s;
		}
	}
	temp.clear();
	for (int i = 0; i < split_s.size(); i++) {
		temp += split_s[i];
		if (i < split_s.size() - 1) temp += " ";
	}
	return temp;
}

int main() {
	char c;
	while ((c = getchar()) != EOF) {
		string ini_s, targ_s, swab_s;
		while (c != '\n') {
			ini_s.push_back(c);
			c = getchar();
		}
		//cout << "ini: " << ini_s << endl;
		cin >> targ_s >> swab_s;
		//cout << "targ: " << targ_s << endl;
		//cout << "swab: " << swab_s << endl;
		cout << word_swab(ini_s, targ_s, swab_s) << endl;
		getchar();
	}
}
