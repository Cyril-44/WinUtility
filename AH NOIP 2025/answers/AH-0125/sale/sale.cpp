#include <bits/stdc++.h>
using namespace std;
int c, t, n, m, ans;
const int NT = 998244353;
int a[5001] = {1000000001, 0};

int dv[6] = {2000000002, 0};
void dfs(int ti, int v, int m, int lim) {
	dv[ti] = v;
	if(ti == lim) {
		/*Preview start*/
		bool inusing[6] = {1,1,1,1,1,1};
		
		int needv = 0; for(int i = 1; i <= lim; i++) {needv += dv[i];}
		while(needv > m) {
			if((needv - m) > 1) {
				int minum = 1;
				for(int i = 1; i <= lim && inusing[i]; i++) if(2 / dv[i] * a[i] < 2 / dv[minum] * a[minum]) minum = i;
				inusing[minum] = 0, needv -= dv[minum];
			}
			else {
				int minum1 = 0, minum2 = 0;
				for(int i = 1; i <= lim && inusing[i]; i++) {
					if(dv[i] == 1) if(a[i] < a[minum1]) minum1 = i;
					if(dv[i] == 2) if(a[i] < a[minum2]) minum2 = i;
				}
				if(minum1 && minum2) {
					if(a[minum1] >= a[minum2]) minum1 = 0;
					else minum2 = 0;
				}
				
				if(!minum1) inusing[minum2] = 0, needv -= dv[minum2];
				else inusing[minum1] = 0, needv -= dv[minum1];
			}
		}
		long long maxvalue = 0; for(int i = 1; i <= lim; i++) if(inusing[i]) maxvalue += 1 * a[i];
		/*Preview end*/
		
		bool beenseek[6] = {1,1,1,1,1,1};
		int seek = 0; long long tempvalue = 0;
		while(m) {
			for(int i = 1; i <= lim && beenseek[i]; i++) {
				if(a[seek] * 2 / dv[seek] < a[i] * 2 / dv[seek]) seek = i;
			}
			if(m < dv[seek]) break;
			else {beenseek[seek] = 0, tempvalue += a[seek], m -= dv[seek];}
		}
		if(tempvalue == maxvalue) ans++;
		else return ;
	}
	else {
		dfs(ti + 1, 1, m, lim); dfs(ti + 1, 2, m, lim);
	}
	return ;
}

int main() {
	//freopen("sale.in", "r", stdin);
	//freopen("sale.out", "w", stdout);
	
	cin >> c >> t;
	for(int i = 1; i <= t; i++) {
		cin >> n >> m;
		for(int j = 1; j <= n; j++) cin >> a[j];
		
		if(c <= 3) {
			dfs(1, 1, m, n); dfs(1, 2, m, n);
			cout << ans << endl; ans = 0;
		}
		
		else {
			sort(a + 1, a + 1 + n); ans = 1;
			if(a[n] > a[n - 1] * 2) {for(int j = 1; j <= n; j++) {ans *= 2; ans %= NT;}}
			else {
				int j = n - 2; while(a[n] <= a[j] * 2) j--;
				for(int k = 1; k < n; k++) ans *= 2, ans %= NT;
				int anstemp = 1; for(int k = 1; k < j; k++) {anstemp *= 2; anstemp %= NT;}
				ans += anstemp; ans %= NT;
			}
			cout << ans << endl; ans = 0;
		}
	}
	
	return 0;
}
/*n(5000) = 个数, a[n](int) = 原单价, m = 预算, N = 测试点总糖量*/
