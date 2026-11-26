#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 1;
int a[N];
long long s[N];
int main()
{
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	long long pow = 1;
	for(int i = 1;i <= 62;i ++) pow = pow * 2;
	pow = pow + (pow - 1);
	int n, q, l, r;
	cin >> n;
	for(int i = 1;i <= n;i ++) {scanf("%d", &a[i]); s[i] = s[i - 1] + a[i];}
	cin >> q;
	while(q --){
		cin >> l >> r;
		long long ans = 0;
		for(int i = 1;i <= n;i ++){
			long long maxn = -1e18;
			for(int j = 1;j <= i;j ++){
				for(int k = i;k <= n;k ++){
					if(l > k - j + 1 || r < k - j + 1) continue;
					long long s1 = s[k] - s[j - 1];
					maxn = max(maxn, s1);
				}
			}
			ans ^= (maxn * i) % pow;
		}
		cout << ans << endl;
	}
	return 0;
}
//Hello,world!
/*
diary:
30min AC A 100pts
2h WA C 8pts
1h TLE B 20pts
40min WA D may5pts
20min check
100+20+8+5=133
im only a girl in junior high school. dont laugh at me. qwq 
*/
