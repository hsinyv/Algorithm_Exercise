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
	int n; char c;	int height;
	cin >> n >> c;
//	double div = n / 2.0; 
//	if(div - n/2 >= 0.5) height = n/2-1;
//	else height = n/2-2;
	if(n % 2 == 0) height = n/2;
	else height = n/2 + 1;
	int width = n;
	int space_num = n-2;
	string s1(n,c);
	string s2; s2.push_back(c);
	for(int i = 0; i < space_num; i++){
		s2.push_back(' ');
	}
	s2.push_back(c);
	cout << s1 << endl;
	for(int i = 0; i < height; i++){
		cout << s2 << endl;
	}
	cout << s1 << endl;
	return 0;
}
