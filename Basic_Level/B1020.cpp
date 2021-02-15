#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class mooncake{
	public:
		int id;
		double stock;
		double sum_price;
		double unit_price;
		void print(){
			cout << id << " stock: "<< stock << " price: "<< sum_price << " "<< unit_price<< endl;
		}
			
};

double max_revenue(double demand, vector<mooncake> moonset){
	
	return max;
}

int main(void){
	double demand;
	int type_sum;
	vector<mooncake> moonset(type_sum);
	cin >> type_sum >> demand;
	double t;
	for(i = 0; i < type_sum; i++){
		moonset[i].id = i;
		cin >> moonset[i].stock;
	}
	for(i = 0; i < type_sum; i++){
		cin >> moonset[i].sum_price;
		moonset[i].unit_price = moonset[i].sum_price / moonset[i].stock;
	}
	cout << mixed << setprecision(2) << max_revenue(demand, moonset) << endl;
	
	return 0;
} 
