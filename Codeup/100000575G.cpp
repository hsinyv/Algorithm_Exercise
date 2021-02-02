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
	string a, b;
	int da, db;
	while(cin >> a >> da >> b >> db){
		int cnt1 = 0, cnt2 = 0;
		int pa = 0, pb = 0;
		for(int i = 0; i < a.size(); ++i){
			if(a[i] - '0' == da) cnt1++;
		}
		for(int i = 0; i < b.size(); ++i){
			if(b[i] - '0' == db) cnt2++;
		}
		for(int i = 0, e = 1; i < cnt1; ++i, e = e*10){
			pa += da * e;
		}
		for(int i = 0, e = 1; i < cnt2; ++i, e = e*10){
			pb += db * e;
		}
		cout << pa+pb << endl;	
	} 
	return 0;
}

