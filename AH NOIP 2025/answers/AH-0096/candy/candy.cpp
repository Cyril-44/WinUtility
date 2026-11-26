#include<bits/stdc++.h>
using namespace std;

long long n, m, x[100005], y[100005], sum[100005], minn = 1, mid, tot, t, ans;

int main(){
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		sum[i] = x[i];
		if(x[i] + y[i] < x[minn] + y[minn])
			minn = i;
	}
	mid = (x[minn] + y[minn]);
	ans = tot = m / mid * 2;
	m %= mid;
	sort(sum + 1, sum + n + 1);
	sum[1] -= m;
	for(int i = 2; i <= n; i++)
		sum[i] += sum[i - 1];
	for(int i = 1; i <= n; i++){
		t = tot;
		if(sum[i] <= 0)
			ans = max(ans, t + i);
		else{
			t -= (sum[i] - 1) / mid * 2;
			sum[i] = (sum[i] - 1) % mid;
			if(sum[i] < y[minn])
				t--;
			else
				t -= 2;
			ans = max(ans, t + i);
		}
	}
	cout << ans;
	return 0;
}
