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
typedef long long ll;
map<char,ll> digit_in = {{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},{'B',11},\
						 {'C',12},{'D',13},{'E',14},{'F',15}};
string digit[17] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
ll any_radix_to_dec(string s, ll radix){
	ll index_base = 1;
	ll dec = 0;
	for(int i = s.size()-1; i >= 0; i--){
		if(islower(s[i])) s[i] = toupper(s[i]);
		dec += index_base * digit_in[s[i]];
		index_base *= radix;
	}
	return dec;
}
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
	ll a,b;
	string n;
	while(cin >> a >> n >> b){
		cout << dec_to_any_radix(any_radix_to_dec(n,a), b) << endl;
	}
	
	return 0;
}
