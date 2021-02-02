#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cctype>
using namespace std;

string del_string(string pattern, string ini_string){
	string space = " ";
	int match_pos = ini_string.find(space);
	while(match_pos != -1){
		auto begin = ini_string.begin() + match_pos;
		ini_string.erase(begin);
		match_pos = ini_string.find(space);
	}
	
	string lower_copy(ini_string);
	transform(lower_copy.begin(), lower_copy.end(), lower_copy.begin(), ::tolower);
	transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
	
	match_pos = lower_copy.find(pattern);
	while(match_pos != -1){
		auto begin = lower_copy.begin() + match_pos;
		auto i_begin = ini_string.begin() + match_pos;
		auto end = begin + pattern.size();
		auto i_end = i_begin + pattern.size();
		lower_copy.erase(begin,end);
		ini_string.erase(i_begin,i_end);
		match_pos = lower_copy.find(pattern);
	}
	return ini_string;
	
}

int main(void){
	string pattern; string t;
	cin >> pattern; getchar();
	while(getline(cin, t)){
		cout << del_string(pattern,t) << endl;
		t.clear();
	}
	return 0;
} 
