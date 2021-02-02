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
typedef vector<string> vs;
vs line_split(string s){
	vs v; 
	s += " ";//DO NOT ignore the last word
	int begin = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' '){
			string sub = s.substr(begin,i-begin);
			v.insert(v.begin(),sub);
			begin = i + 1;
		} 
	}
	return v;
}
int main() {
	string s;
	getline(cin, s);
	vs v = line_split(s);
	for(auto a = v.begin(); a < v.end(); a++){
		cout << *a;
		if(a + 1 != v.end()) cout << " ";
	}
	//the method for test system
//	string s;
//	vs v;
//	while(cin >> s){
//		v.insert(v.begin(),s);
//	}	
//	for(auto a = v.begin(); a < v.end(); a++){
//		cout << *a;
//		if(a + 1 != v.end()) cout << " ";
//	}	
//	
	return 0;
}
