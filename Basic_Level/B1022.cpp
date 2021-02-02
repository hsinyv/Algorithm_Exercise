#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
//map<char,ll> digit_in = {{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},{'B',11},\
//						 {'C',12},{'D',13},{'E',14},{'F',15}};
string digit[17] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
string trans_num_sys(ll n, int base){
	//transfer n in decimal to base number system
	ll quo = n; ll remain = 0; string result;
	while(quo >= base){
		remain = quo % base;
		quo /= base;
		result = digit[remain] + result;
	}
	result = digit[quo] + result;
	return result;
}

//string dec_to_any_radix(ll n, ll radix) {
//	ll remain = 0;
//	ll quo = n;
//	string s = "";
//	while (quo >= radix) {
//		remain = quo % radix;
//		quo = quo / radix;
//		s = digit[remain] + s;
//	}
//	s = digit[quo] + s;
//	return s;
//}
int main(void){
	ll a,b,d;
	cin >> a >> b >> d;
	cout << trans_num_sys(a+b,d) << endl;
	//cout << dec_to_any_radix(a+b,d) << endl;
	
}
