#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Student{
	public:
		string ID;
		string in_time;
		string out_time;
	friend ostream & operator<<(ostream &, Student&);
	Student(string id, string in, string out){
		ID = id; in_time = in; out_time = out;
	}
};

ostream & operator<<(ostream & output, Student&A)
{
	output <<"Student:\n" << A.ID << endl;
	output << A.in_time << endl;
	output << A.out_time << endl;
	return output;
}
bool in_com(Student A, Student B){
	return A.in_time < B.in_time;
}
bool out_com(Student A, Student B){
	return A.out_time > B.out_time;
}

string find_unlock(vector<Student> A){
	sort(A.begin(), A.end(), in_com);
	return A[0].ID;
} 
string find_lock(vector<Student> A){
	sort(A.begin(), A.end(), out_com);
	return A[0].ID;
} 
int main() {
	int n;
	cin >> n;
	vector<Student> A;
	string a,b,c;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		Student t(a,b,c);
		A.push_back(t); 
	}
	cout << find_unlock(A)<< " "<< find_lock(A) << endl;
//	for(int i = 0; i < n; i++){
//		cout << A[i]; 
//	}
	return 0;
}


