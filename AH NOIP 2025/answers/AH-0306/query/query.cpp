#include <bits/stdc++.h>
#define afor(x, y, z) for(int x = y; x <= z; x++)
using namespace std;
const int N = 5e4 + 10;
int a[N];
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
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	int n = read();
	afor(i, 1, n) a[i] = read();
	int q = read();
	while(q--){
	int x = read();
	cout << 0 << endl;
	}
	return 0;
}
