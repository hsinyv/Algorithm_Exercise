#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool modify_flag = false;

class user{
	public:
		string name;
		string password;
	user(string n, string p){
		name = n;
		password = p;
	}
	friend ostream &operator<<(ostream &out, user &A){
		out << A.name << " "<< A.password << endl;
	}
};

void check_password(user &u, bool &flag){
	for(int i = 0; i < u.password.size(); i++){
		switch (u.password[i]){
			case '1':{
				u.password[i] = '@'; flag = true; modify_flag = true;
				break;
			}
			case '0':{
				u.password[i] = '%'; flag = true; modify_flag = true;
				break;
			}
			case 'l':{
				u.password[i] = 'L'; flag = true; modify_flag = true;
				break;
			}
			case 'O':{
				u.password[i] = 'o'; flag = true; modify_flag = true;
				break;
			}
			default: break;
		}
	}
	return;
}
int main(void){
	int n;	cin >> n;
	if(n == 1){
		cout << "There is 1 account and no account is modified\n";
		return 0;
	}
	vector<user> v, modify_v; 
	for(int i = 0; i < n; i++){
		string n, p;
		cin >> n >> p;
		user u(n,p);
		v.push_back(u);
	}
	
	for(int i = 0; i < n; i++){
		bool flag = false;
		check_password(v[i], flag);
		if(flag) modify_v.push_back(v[i]);
	}
	if(!modify_flag) cout << "There are " << n <<" accounts and no account is modified\n";
	else{
		cout << modify_v.size() << endl;
		for(auto it : modify_v)
			cout << it;
	}
	return 0;
}


