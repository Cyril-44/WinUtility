#include <bits/stdc++.h>
#define int long long
#define afor(x, y, z) for(int x = y; x <= z; x++)
using namespace std;
const int N = 8e3 + 10;
const int p[N];
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
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int t = read();
	while(t--){
		int n = read(), m = read();
		afor(i, 1, n){
			int ans = 0;
			p[i] = read();
			ans += p[i];
		}
		printf("%lld", ans + 1);
	}
	return 0;
}//lbjllswcl
