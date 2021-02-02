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
typedef long long ll;
using namespace std;
string digit[17] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
string dec_to_any_radix(ll n, ll radix) {
	ll remain = 0;
	ll quo = n;
	string s = "";
	while (quo >= radix) {
		remain = quo % radix;
		quo = quo / radix;
		s = digit[remain] + s;
	}
	s = digit[quo] + s;
	return s;
}
int main() {
	ll m, a, b;
	cin >> m;
	while(m){
		cin >> a >> b;
		cout << dec_to_any_radix(a+b, m) << endl;
		cin >> m;
	}
	return 0;
}
