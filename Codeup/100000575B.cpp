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
int main() {
	string s,t;
	while(cin >> s){
		cin >> t;
//		cout <<"s: " << s << endl;
//		cout <<"t: " << t << endl;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == ',') {
				s.erase(s.begin()+i);
				i--;
			}
			
		}
		for(int i = 0; i < t.size(); i++){
			if(t[i] == ',') {
				t.erase(t.begin()+i);
				i--;
			}
		}
//		cout <<"new s: " << s << endl;
//		cout <<"new t: " << t << endl;
		int a = stoi(s);
		int b = stoi(t);
		cout << a+b << endl;
	}
	return 0;
}
