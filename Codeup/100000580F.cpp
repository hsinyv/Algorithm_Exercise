#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void){
	char c;
	string s;
	while((c = getchar()) != EOF){
		if(c != '\n'){
			s += c;
		}
		else{
			reverse(s.begin(),s.end());
			cout << s << endl;
			s.clear();
		}
	}
	return 0;
}
