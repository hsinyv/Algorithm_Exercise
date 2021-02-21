#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
vector<int> toll;

void date_trans(string date, int &day, int &hour, int &minute);

class Rec{
	public:
		string user;
		string month;
		string date;
		string status;
		int day, hour, minute;
	Rec(string u, string m, string d, string s){
		user = u;
		month = m; 
		date = d;
		status = s;
		date_trans(date, day, hour, minute);
	}	
};

class CheckedRec{
		public:
		string user;
		string month;
		string on_time;
		string off_time;
		int lasting;
		int cost;
	CheckedRec(Rec prev, Rec cur, int l, int c){
		user = prev.user;
		month = prev.month; 
		on_time = prev.date; 
		off_time = cur.date;
		lasting = l;
		cost = c;
	}
	friend ostream &operator<<(ostream &out, CheckedRec &a){
		out << a.user << " " << a.month << endl;
		out << a.on_time << " " << a.off_time << " " << a.lasting << " $";
		out << fixed << setprecision(2) << a.cost/100.0 << endl;
		return out;
	}
};

void date_trans(string date, int &day, int &hour, int &minute){
	day = stoi(date.substr(0,2));
	hour = stoi(date.substr(3,2));
	minute = stoi(date.substr(6,2));
	return;
}

void insert_record(vector<vector<Rec>> &all_rec, Rec n_rec){
	for(auto it = all_rec.begin(); it < all_rec.end(); it++){
		if((((*it)[0]).user == n_rec.user) && (((*it)[0]).month == n_rec.month)){
			(*it).push_back(n_rec);
			return;
		}
	}
	vector<Rec> new_user_month;
	new_user_month.push_back(n_rec);
	all_rec.push_back(new_user_month);
	return;
}

bool vec_compare(Rec a, Rec b){
	if(a.day == b.day){
		if(a.hour == b.hour){
			return a.minute < b.minute;
		}
		return a.hour < b.hour;
	}
	return a.day < b.day;
}

bool rec_compare(vector<Rec> a, vector<Rec> b){
	if(a[0].user == b[0].user){
		return a[0].month < b[0].month;
	}
	return a[0].user < b[0].user;
}

bool status_pair(Rec a, Rec b){
	if(a.status == "on-line" && b.status == "off-line")
		return true;
	return false;
}
int cal_day_cost(int h1, int m1, int h2, int m2){
	int cost = 0;
	for(int i = h1 + 1; i <= h2; i++){
		cost += 60 * toll[i];
	}
	cost += (60 - m1) * toll[h1];
	cost += m2 * toll[h2];
	return cost;
}
void cal_cost(Rec a, Rec b, int &lasting, int &cost){
	int day_interval = b.day - a.day; 	    	lasting = day_interval * 24 * 60;
	int hour_interval = b.hour - a.hour; 		lasting += hour_interval * 60;
	int minute_interval = b.minute - a.minute; 	lasting += minute_interval;
	cost = day_interval * toll[24];
	if(a.day != b.day){
		cost += cal_day_cost(a.hour, a.minute, 24, 0);
		cost += cal_day_cost(0,0,b.hour,b.minute);
	}
	else{
		cost += cal_day_cost(a.hour, a.minute, b.hour,b.minute);
	}
	return;
}

vector<CheckedRec> cal_bill(vector<Rec> rec){
	auto prev = rec.begin();
	auto cur = prev;
	vector<CheckedRec> checked_rec;
	for(auto it = rec.begin() + 1; it < rec.end(); it++){
		cur = it;
		if(status_pair(*prev, *cur)){
			int lasting, cost;
			cal_cost(*prev, *cur, lasting, cost);
			CheckedRec cr(*prev, *cur, lasting, cost);
			checked_rec.push_back(cr);
		}
	}
	return checked_rec;
}

int main(void){
	//get toll for each hour
	int toll_sum;
	for(int i = 0; i < 24; i++){
		int t; 
		cin >> t;
		toll_sum += t;
		toll.push_back(t);
	}
	toll.push_back(toll_sum);
	
	int n; cin >> n;
	vector<vector<Rec>> all_rec;
	for(int i = 0; i < n; i++){
		string user, month_date, month, date, status;
		cin >> user >> month_date >> status;
		month = month_date.substr(0,2);
		date = month_date.substr(3,9);
		Rec new_record(user, month, date, status);
		insert_record(all_rec, new_record);
	}
	for(int i = 0; i < all_rec.size(); i++){
		sort(all_rec[i].begin(), all_rec[i].end(), vec_compare);
	}
	sort(all_rec.begin(), all_rec.end(), rec_compare);
	vector<vector<CheckedRec>> all_checked_rec;
	for(auto it = all_rec.begin(); it < all_rec.end(); it++){
		all_checked_rec.push_back(cal_bill(*it));
	}
	for(auto it : all_checked_rec){
		int bill_sum = 0;
		for(auto i : it){
			
			bill_sum += i.cost;
			cout << i;
		}
		cout << "Total amount: $";
		cout << fixed << setprecision(2) << bill_sum / 100.0 << endl;
	}	
}
