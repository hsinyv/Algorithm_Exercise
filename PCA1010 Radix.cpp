/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1010 Radix
*  Date: 2021/0
***********************************************/
/***********************************************
* Core Mission: 
* Point:  
***********************************************/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> value2digit({ "0","1","2","3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" \
	, "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m"\
	, "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" });
map<char, int> digit2value;
void DigitValueInitialize() {
	for (int i = 0; i < 36; i++)
	{
		if (i < 10) {
			digit2value['0' + i] = i;
		}
		else {
			digit2value['a' + i - 10] = i;
		}

	}
	return;
}
string AnyRadix2Decimal(string ini_number, int radix) {
	string number_reverse = ini_number;
	reverse(number_reverse.begin(), number_reverse.end());
	int weight = 1;
	int decimal = 0;
	for (int i = 0; i < number_reverse.size(); i++)
	{
		decimal = decimal + (digit2value[number_reverse[i]] * weight);
		weight *= radix;
	}
	return to_string(decimal);
}

string Decimal2AnyRadix(string ini_number, int radix) {
	int number = stoi(ini_number);
	string trans_result;
	int remain = 0;
	while (number > radix) {
		int remain = number % radix;
		number = number / radix;
		trans_result = value2digit[remain] + trans_result;
	}
	trans_result = value2digit[number] + trans_result;
	return trans_result;
}

int main(void) {
	DigitValueInitialize();
	string a_number, b_number;
	int tag, radix;
	cin >> a_number >> b_number >> tag >> radix;
	//while (cin >> a_number >> b_number >> tag >> radix) {
	if (tag == 2) {
		swap(a_number, b_number);
	}
	if (radix != 10) {
		a_number = AnyRadix2Decimal(a_number, radix);
	}

	bool possible = false;
	for (int radix_probing = 2; radix_probing < 37; radix_probing++)
	{
		string probing_number = Decimal2AnyRadix(a_number, radix_probing);
		if (probing_number == b_number) {
			possible = true;
			cout << radix_probing << endl;
			break;
		}
	}
	if (!possible) {
		cout << "Impossible\n";
	}
	//}
	
	
	return 0;
}
 
