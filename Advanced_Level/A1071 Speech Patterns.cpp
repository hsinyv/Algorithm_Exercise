#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef pair<string, int> psi;

void split(string s, vector<string> &words) {
	for (string::iterator it = s.begin(); it < s.end(); it++) {
		if (isalnum(*it)) {
			string s;
			while (isalnum(*it)) {
				s.push_back(*it);
				it++;
				
			}
			words.push_back(s);
		}
	}
}

bool mycom(psi A, psi B) {
	if (A.second == B.second) {
		return A.first < B.first;
	}
	else return A.second > B.second;
}

vector<psi> sort_map(map<string, int> m) {
	vector<psi> pair_vec;
	for (auto it : m)
		pair_vec.push_back(it);
	sort(pair_vec.begin(), pair_vec.end(), mycom);
	return pair_vec;
}

void find_pattern(vector<string> words) {
	map<string, int> word_freq;
	for (auto it : words) {
		if (word_freq.find(it) == word_freq.end()) {
			word_freq[it] = 1;
		}
		else {
			word_freq[it]++;
		}
	}
	vector<psi> pair_vec = sort_map(word_freq);
	cout << pair_vec[0].first << " " << pair_vec[0].second << endl;
}
int main(void) { 
	string ini_s;
	getline(cin, ini_s);
	for_each(ini_s.begin(), ini_s.end(), [](char& c) {if (isalpha(c)) c = tolower(c); });
	vector<string> words;
	split(ini_s, words);
	find_pattern(words);
	/*for (auto it : words) {
		cout << it << endl;
	}*/
	return 0;

}


