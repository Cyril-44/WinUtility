#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long x[100001], y[100001], sumi[100001];
bool used[100001], Erision = 1;
long long E_limit = 3355033699933550337;

long long smin = 1145141919810, nmin;
int type;

int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	cin >> n >> m; /*m = money, n = types*/
	
	for(long long i = 1; i <= n; i++) {
		cin >> x[i] >> y[i]; if(x[i] != y[i]) Erision = 0;
		sumi[i] = x[i] + y[i];
		if(smin > sumi[i]) {smin = sumi[i], nmin = i;}
	}
	
	if(Erision) {
		E_limit = m / x[nmin];
	}
	
	if(x[nmin] < y[nmin]) type = 1;
	if(x[nmin] > y[nmin]) type = 2;
	if(x[nmin] == y[nmin]) type = 3;
	
	long long ans = 0, temp = m;
	bool last_buy = 1;/* 0 = x, 1 = y*/
	ans += temp / smin * 2; temp -= ans / 2 * smin;
	for(long long i = 1; i <= n; i++){
		if(x[i] * 2 < (x[nmin] + y[nmin])) {
			ans++, temp -= x[i], used[i] = 1; 
			if(temp < 0) {
				ans--;
				if(last_buy == 1) temp += y[nmin]; else temp += x[nmin];
				last_buy = 1 - last_buy;
			}
		}
	}
	for(long long i = 1; i <= n; i++) {
		if(temp >= x[i] && used[i] == 0) {ans++;}
	}
	if(Erision) {
		ans = max(E_limit, ans);
	}
	cout << ans;
	return 0;
}
