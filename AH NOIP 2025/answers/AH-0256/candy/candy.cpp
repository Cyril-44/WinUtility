#include <iostream>
using namespace std;

int main(){
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n, m;
	cin >> n >> m;
	long long kinds[n][2];
	for (int i = 0; i < n; i++)
		cin >> kinds[i][0] >> kinds[i][1];
	long long cheapest = 0;
	long long current_cheapest_price = kinds[0][0] + kinds[0][1];
	long long current_price;
	for (int i = 1; i < n; i++){
		current_price = kinds[i][0] + kinds[i][1];
		if (current_price < current_cheapest_price){
			current_cheapest_price = current_price;
			cheapest = i;
		}
	}
	
	long long candies = 0;

	for (int i = 0; i < n; i++){
		if ((kinds[i][0] < kinds[cheapest][0]) and (kinds[i][0] + kinds[cheapest][0] <= kinds[cheapest][0] + kinds[cheapest][1])){
			++candies;
			m -= kinds[i][0];
		}
	}

	long long candies_cheapest = 0;
	while (true){
		if (candies_cheapest % 2 == 1){
			if (m - kinds[cheapest][0] >= 0){
				m -= kinds[cheapest][0];
				++candies_cheapest;
			}
			else
				break;
		}

		else{
			if (m - kinds[cheapest][1] >= 0){
				m -= kinds[cheapest][1];
				++candies_cheapest;
			}
			else
				break;
		}
	}
	
	long long candies_total = candies + candies_cheapest;
	cout << candies_total << endl;
	
	return 0;
}
