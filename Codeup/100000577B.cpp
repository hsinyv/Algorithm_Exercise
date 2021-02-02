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
string s_reverse(string s){
	string t = s;
	for(int i = 0, j = s.size()-1; i < s.size(), j >= 0; i++, j--){
		t[i] = s[j];
	}
	return t;
}

int main() {
	string s;
	while(cin >> s){
		int len1 = ((s.size()+2)/3)-1;
		int len2 = s.size() - 2*len1;
		string s1 = s.substr(0,len1);
		string s2 = s.substr(len1, len2);
		string s3 = s.substr(len1+len2, len1);
		//cout << s1 << s2 << s3 <<endl;
		s3 = s_reverse(s3);
		//cout << s3;
		int len_space = len2 - 2;
		string space;
		for(int i = 0; i < len_space; i++){
			space += " ";
		}
		for(int i = 0 ; i < len1; i++){
			cout << s1[i] << space << s3[i] << endl;
		}
		cout << s2 << endl;
	}
	
	return 0;
}
