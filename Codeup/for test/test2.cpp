#include <fstream>
#include <iostream>
using namespace std;
int main(){
	ifstream in("temp.txt");
	string d,m,y,d2; int num;
	in >> d >> m >> y >> d2 >> num;
	int ini = num;
	while(in >> d >> m >> y >> d2 >> num){
		if((num - ini + 7) % 7 != 1){
			cout << d << m << y << endl;
			break;
		}
		ini = num;
	}
	cout << "No wrong!\n";
	return 0;
}
