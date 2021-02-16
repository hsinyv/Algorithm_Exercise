#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


class GameOdds {
public:
	char result;
	double odd;
	GameOdds(char r, double o) {
		result = r;
		odd = o;
	}
};
bool my_com(GameOdds A, GameOdds B) {
	return A.odd > B.odd;
}

GameOdds find_max(vector<double> res) {
	vector<GameOdds> result;
	for (int i = 0; i < 3; i++) {
		switch (i) {
		case 0: {
			GameOdds g('W', res[i]);
			result.push_back(g);
			break;
		}
		case 1: {
			GameOdds g('T', res[i]);
			result.push_back(g);
			break;
		}
		case 2: {
			GameOdds g('L', res[i]);
			result.push_back(g);
			break;
		}
		}

	}
	sort(result.begin(), result.end(), my_com);
	return result[0];
}

int main() {
	vector<GameOdds> max;
	for (int i = 0; i < 3; i++) {
		vector<double> temp_result;
		for (int j = 0; j < 3; j++) {
			double t;
			cin >> t;
			temp_result.push_back(t);
		}
		max.push_back(find_max(temp_result));
	}
	double max_profit = (max[0].odd *max[1].odd *max[2].odd *0.65 - 1) * 2;
	cout << max[0].result << " " << max[1].result << " " << max[2].result << " ";
	cout << fixed << setprecision(2) << max_profit << endl;
	return 0;
}
