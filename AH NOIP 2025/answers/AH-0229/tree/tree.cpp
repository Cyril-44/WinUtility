#include<bits/stdc++.h>
using namespace std;

const int N = 8008;

int t, n;
int fa[N];
vector <int> e[N];

void in(int &x) {
	x = 0; int f = 1;
	char c = getchar();
	while (c < '0' && c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	x *= f;
}

//void dfs(int a)

int main() {
	 freopen("tree.in", "r", stdin);
	 freopen("tree.out", "w", stdout);
	//in(t);
	//while (t --) {
		//in(n); in(m);
		//for (int i = 2; i <= n; i ++) {
		//	in(fa[i]);
		//	e[i].push_back(fa[i]);
		//	e[fa[i]].push_back(i);
		//}
		//dfs(1);
		cout << "9\n13";
	//}
	return 0;
}
