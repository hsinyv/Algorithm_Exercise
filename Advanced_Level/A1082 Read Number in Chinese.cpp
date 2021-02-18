#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* 
* test case
* 1 12 123 12345 123456 1234567 12345678 123456789
* 102 1002 10002 100002 1000002 10000002 100010002 
* Yi Wan Qian Bai Shi
* 1 10 103 12005 120456 1230567 12345678 123456789
*/
string read_number(int i) {
	switch (i) {
	case 1: {
		return "yi";
	}
	case 2: {
		return "er";
	}
	case 3: {
		return "san";
	}
	case 4: {
		return "si";
	}
	case 5: {
		return "wu";
	}
	case 6: {
		return "liu";
	}
	case 7: {
		return "qi";
	}
	case 8: {
		return "ba";
	}
	case 9: {
		return "jiu";
	}
	default:  return "##";
	}
}

string read_segment(string s) {
	//digit has 4 char
	vector<int> digit;
	for (auto it : s)
		digit.push_back(it - '0');
	//if (digit[3] == 0 && digit[2] == 0 && digit[1] == 0 && digit[0] == 0) return "ling";
	string read;
	for (int i = 0; i < digit.size(); i++) {
		if (digit[i] != 0) {
			read += read_number(digit[i]);
			read += " ";
			if (i == 0 && digit.size() > 1) read += "Qian ";
			if (i == 1) read += "Bai ";
			if (i == 2) read += "Shi ";
		}
		else {
			/*if (i = 0 && digit.size() < 4)
			if (i = 1 && digit.size() < 3)
			if (i = 2 && digit.size() < 2)*/
			if (i == 1 && digit[0] != 0 && (digit[2] != 0 || digit[3] != 0)) read += "ling ";
			if (i == 2 && digit[1] != 0 && digit[3] != 0) read += "ling ";
		}
	}
	return read;
}
string read_in_chinese(string s) {
	//split it into segments, 
	vector<string> segment;
	segment.push_back(s.substr(0, 1));
	segment.push_back(s.substr(1, 4));
	segment.push_back(s.substr(5, 4));
	//read every segment and deal with '0' between segments
	string read;
	read += read_segment(segment[0]); if (stoi(segment[0]) != 0) read += "Yi ";
	if (stoi(segment[0]) != 0 && stoi(segment[1]) < 1000) read += "ling ";
	read += read_segment(segment[1]); if (stoi(segment[1]) != 0) read += "Wan ";
	if (stoi(segment[1]) != 0 && stoi(segment[2]) < 1000) read += "ling ";
	read += read_segment(segment[2]);
	if (read[read.size() - 1] == ' ') read.erase(read.end() - 1);
	return read;
}


int main(void) {
	string num_s; 
	while (cin >> num_s) {
		vector<int> digit;
		bool neg_flag = false;
		if (num_s[0] == '-') {
			num_s.erase(num_s.begin());
			neg_flag = true;
		}
		if (stoi(num_s) == 0) {
			cout << "ling\n";
			return 0;
		}
		if (num_s.size() < 9) {
			int lim = 9 - num_s.size();
			for (int i = 0; i < lim; i++)
				num_s = "0" + num_s;
		}
		if (neg_flag) cout << "Fu ";
		cout << read_in_chinese(num_s) << endl;
	}
	

	return 0;
}
