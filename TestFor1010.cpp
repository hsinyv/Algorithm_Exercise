#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;



vector<string> digit({ "0","1","2","3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" \
	, "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m"\
	, "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" });
map<char, int> digit_value;
void DigitValueInitialize() {
	for (int i = 0; i < 36; i++)
	{
		if (i < 10) {
			digit_value['0' + i] = i;
		}
		else {
			digit_value['a' + i - 10] = i;
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
		decimal += digit_value[number_reverse[i]] * weight;
		weight *= radix;
	}
	return to_string(decimal);
}

string Decimal2AnyRadix(int ini_number, int radix) {
	int number = ini_number;
	string trans_result;
	int remain = 0;
	while (number > radix) {
		int remain = number % radix;
		number /= radix;
		trans_result = digit[remain] + trans_result;
	}
	trans_result = digit[number] + trans_result;
	return trans_result;
}

int GuessRadix(int num_decimal, string num_guess) {
	for (int i = 2; i < 36; i++)
	{
		if (Decimal2AnyRadix(num_decimal, i) == num_guess) {
			return i;
		}
	}
	return -1;
}

int main(void) {
	DigitValueInitialize();
	ofstream out; out.open("A1010.txt");
	int radix_1 = 24;
	int radix_2 = 17;
	for (int i = 0; i < 9999; i++)
	{
		string num1 = Decimal2AnyRadix(i, radix_1);
		string num2 = Decimal2AnyRadix(i, radix_2);
		out << num1 << " " << GuessRadix(i, num1) << " " << \
			num2 << " " << GuessRadix(i, num2) << endl;
	}
	out.close();
	cout << "finish\n";
	return 0;
}

