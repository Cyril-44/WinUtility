#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
struct node{
	double w, v;
}a[N];
bool cmp(node x, node y){
	return x.w < y.w;
}
int main()
{
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ll m, ans = 0;
	int n, x, y;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		scanf("%d %d", &x, &y);
		a[i * 2 - 1].w = x; a[i * 2 - 1].v = 1;
		a[i * 2].w = (x + y) / 2.0; a[i * 2].v = 2; 
	}
	sort(a + 1, a + 2 * n + 1, cmp);
	for(int i = 1;i <= 2 * n;i ++){
		if(a[i].v == 1 && m >= a[i].w){
			ans ++; m -= a[i].w;
		}else if(a[i].v == 2){
			ans += m / a[i].w;
			break; 
		}else break;
	}
	cout << ans;
	return 0;
}
//Hello,world!
