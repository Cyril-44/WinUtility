#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
struct node{ll x, y;}a[100010];
bool cmp1(node a, node b){return a.x + a.y < b.x + b.y;}
bool cmp2(node a, node b){return a.x < b.x;}

int main(){
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1, cmp1);
	ll k = a[1].x + a[1].y;
	sort(a + 1, a + n + 1, cmp2);
	ll sum = 0, ans = m / k * 2;
	for(int i = 1; i <= n; i ++){
		sum += a[i].x;
		if(m < sum) break;
		ll tmp = (m - sum) / k * 2;
//		cout << tmp + i << '\n';
		if(tmp + i >= ans) ans = tmp + i;
	}
	cout << ans;
	return 0;
}
//!noip@Nov29,2025:dream
