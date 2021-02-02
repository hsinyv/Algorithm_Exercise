#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;
void Spell(char x){
	switch(x){
		case '0':cout << "zero"; break;
		case '1':cout << "one"; break;
		case '2':cout << "two"; break;
		case '3':cout << "three"; break;
		case '4':cout << "four"; break;
		case '5':cout << "five"; break;
		case '6':cout << "six"; break;
		case '7':cout << "seven"; break;
		case '8':cout << "eight"; break;
		case '9':cout << "nine"; break;
	}
	return;
}
int main() {
	long n = 0;
	char c;
	while((c = getchar())!='\n')
		n += c - '0';
	string s = to_string(n); 
	for(int i = 0; i < s.length(); ++i){
		Spell(s[i]);
		if(i + 1 < s.length()) cout << " ";
	}
	return 0;
}
