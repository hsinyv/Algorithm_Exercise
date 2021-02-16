#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Stu {
public:
	string id;
	string gender;
	string course;
	int grade;
	Stu(){
	}
	Stu(string i, string ge, string c, int g){
		id = i;
		gender = ge;
		course = c;
		grade = g;
	}
	friend ostream &operator<<(ostream &output, Stu &A);
};

ostream &operator<< (ostream &output, Stu &A)
{
	if(A.id == "##"){
		output << "Absent" << endl;
	}
	else{
		output << A.id << " " << A.course << endl; 
	}
	return output;
}

bool my_com(Stu A, Stu B){
	return A.grade > B.grade;
}

int main() {
	int n;
	cin >> n;
	vector<Stu> male_stu, fem_stu;
	string id, gender, course; int grade;
	for(int i = 0 ; i < n; i++){
		cin >> id >> gender >> course >> grade;
		if(gender == "M"){
			Stu s(id,gender, course,grade);
			male_stu.push_back(s);
		}
		else{
			Stu s(id,gender, course,grade);
			fem_stu.push_back(s);
		}
	}
	Stu male_min, fem_max;
	sort(male_stu.begin(),male_stu.end(),my_com);
	sort(fem_stu.begin(),fem_stu.end(),my_com);
	if(male_stu.size() == 0){
		male_min.id = "##";
	}
	else{
		male_min = *male_stu.rbegin();
		//ATTENTION: left value is a instrance of class Stu, and rbegin() is a iterator, so do not ignore *
	}
	if(fem_stu.size() == 0){
		fem_max.id = "##";
	}
	else{
		fem_max = *fem_stu.begin();
	}
	cout << fem_max << male_min;
	if(male_stu.size() && fem_stu.size()){
		cout << fem_max.grade - male_min.grade << endl;
	}
	else{
		cout << "NA" << endl;
	}
	return 0;
}


