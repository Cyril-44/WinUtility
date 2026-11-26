#include <iostream>
using namespace std;

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	int t;
	cin >> t;
	srand(time(0));
	int randints[t];
	for (int i = 0; i < t; i++)
		randints[i] = rand() % 100;
	for (int i = 0; i < t; i++)
		cout << randints[i] << endl;
	
	return 0;
}
