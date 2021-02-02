#include <iostream>
using namespace std;

int callatz(int n){
	int cnt = 0;
	while(n != 1){
		if(n % 2 == 0) n /= 2;
		else n = (3*n+1) / 2;
		++cnt; 
	}
	return cnt;
}

int main(void){
	int n;
	cin >> n;
	cout << callatz(n) << endl;
}
