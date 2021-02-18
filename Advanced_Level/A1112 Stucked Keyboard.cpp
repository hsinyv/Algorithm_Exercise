#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define suspected_stucked_key ssk

class Sus {
public:
	char c;
	int num;
	Sus(char a, int b) {
		c = a;
		num = b;
	}
};

bool confirm(int k, char c, string s){
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == c) {
			for (int j = i; j < i + k; j++) {
				if (s[j] != s[i] || j >= s.size()) {
					return false;
				}
			}
			i = i + k - 1;
		}
	}
	return true;
}

void find_stucked_key(int k, string s, vector<char>& stucked_key) {
	string key;
	int i = 0; 
	for (i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) {
			bool stuck_flag = true;
			for (int j = i; j < i + k; j++) {
				if (s[j] != s[i]) {
					stuck_flag = false;
					break;
				}
			}
			if (stuck_flag) {
				if((find(stucked_key.begin(), stucked_key.end(), s[i]) == stucked_key.end())&& confirm(k,s[i],s)) 
					stucked_key.push_back(s[i]);
				i = i + k - 1;
			}
		}
	}
	return;
}

string modify_sentence(int k, string& s, vector<char> stucked_key) {
	string modify_s;
	for (auto it = s.begin(); it < s.end(); it++) {
		if (find(stucked_key.begin(), stucked_key.end(), *it) != stucked_key.end()) {
			modify_s.push_back(*it);
			it = it + k - 1;
		}
		else modify_s.push_back(*it);
	}
	return modify_s;
}

int main(void) {
	int k; string s; 
	cin >> k >> s;
	vector<char> stucked_key;
	find_stucked_key(k, s, stucked_key);
	string modify_s;
	modify_s = modify_sentence(k, s, stucked_key);
	for (auto it : stucked_key)
		cout << it;
	cout << endl << modify_s << endl;

	return 0;	
}

