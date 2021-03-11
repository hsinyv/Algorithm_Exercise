/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1033 To Fill or Not to Fill
*  Date: 2021/03/05
***********************************************/
/***********************************************
* Core Mission: 
* Point:  
***********************************************/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef pair<double, int> Station;

bool StationCmp(Station a, Station b) {
	return a.second < b.second;
}

void DistanceTranverse(vector<Station> &all_stations) {
	if (all_stations.size() < 2) return;
	int prev_abs_distance = all_stations[0].second;
	for (int i = 1; i < all_stations.size(); i++)
	{
		int cur_abs_distance = all_stations[i].second;
		all_stations[i].second -= prev_abs_distance;
		cur_abs_distance = prev_abs_distance;		
	}
	return;
}

pair<bool, double> CalculateTravelDistance(int max_capacity_of_tank,\
	int distance, int avg_distance, vector<Station> all_stations) {
	//the cheapest price plan??
	//how to deal with the condition that gas is not used up now but price of next station
	//is higher than adding gas now and reaching next of next station??
}

int main(void) {
	int max_capacity_of_tank, distance, avg_distance, gas_stations_num;
	//avg_distance is average distance per unit gas that the car can run
	cin >> max_capacity_of_tank >> distance >> avg_distance >> gas_stations_num;
	vector<Station> all_stations;
	for (int i = 0; i < gas_stations_num; i++)
	{
		double gas_price; int abs_distance;
		//abs_distance is the distance between this station and Hangzhou
		cin >> gas_price >> abs_distance;
		all_stations.push_back(make_pair(gas_price, abs_distance));
	}
	sort(all_stations.begin(), all_stations.end(), StationCmp);
	DistanceTranverse(all_stations);
	CalculateTravelDistance(max_capacity_of_tank, distance, avg_distance, all_stations);

	return 0;
}
 
