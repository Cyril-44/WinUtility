#include <bits/stdc++.h>
#define int long long
#define afor(x, y, z) for(int x = y; x <= z; x++)
using namespace std;
const int N = 1e5 + 10;
int a[N][2], b[N];
int read(){
	int s = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * f;
}
signed main()
{
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	int n = read(), m = read();
	bool pd = 1;
	afor(i, 1, n){
		a[i][1] = read(), a[i][2] = read();
		
		if(a[i][1] != a[i][2]) pd = 0;
	}
	
	if(pd == 1){
		int zhx = 1e9 + 10;
		afor(i, 1, n)
			zhx = min(zhx, a[i][1]);
		cout << m / zhx;
		return 0;
	}
	
	int abs = 0, zby = 1e9 + 1;
	afor(i, 1, n) zby = min(zby, a[i][1]);
	afor(i, 1, n){
		int v = a[i][1] + a[i][2];
		int t = m / v * 2;
		if(m % v >= zby) t++;
		abs = max(abs, t);
	}
	
	int sum = 0;
	
	int ans = a[1][1] + a[1][2], idx = 1;
	afor(i, 2, n){
		int x = a[i][1] + a[i][2];
		if(x < ans) ans = x, idx = i;
	}
	
	int y = 0;
	while(1){
		int zx = 1e9 + 1, cx = 1e9 + 1, zd = 0, cd = 0;
		afor(i, 1, n){
			if(b[i] != 1){
				if(a[i][1] < zx){
					cx = zx, cd = zd;
					zx = a[i][1], zd = i;
				}
				else if(a[i][1] < cx) cx = a[i][1], cd = i;
			}
		}
		
		int y = zx + cx;
		if(y <= ans){
			if(m - y >= 0){
				sum += 2; m -= y;
				b[zd] = 1; b[cd] = 1;
			}
			else {
				cout << 1;
				return 0;
			}
		}
		else break;
	}
	
	int k = m / ans;
	sum += k * 2;
	m -= k * ans;

	int smx = 1e9 + 1;
	afor(i, 1, n){
		if(b[i] == 1) smx = min(smx, a[i][2]);
		else smx = min(smx, a[i][1]);
	}
	
	if(m - smx >= 0){
		cout << max(sum + 1, abs);
		return 0;
	}
	else cout << max(sum, abs);
	return 0;
}
