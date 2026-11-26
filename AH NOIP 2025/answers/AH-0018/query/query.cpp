#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 5e4, Q = 1024;
const ll inf = 1e15;
bool ed;
ll S[N + 10];
int fr = 1, tl = 0, que[N + 10];
int n, a[N + 10], q;
ll ans[Q + 3][N + 3], tmp[N + 10], b[N + 10];
int ql[N + 10], qr[N + 10];
bool vis[N + 10];
bool st;
vector <int> qy[N + 3];
void work(int len) {
	fr = 1, tl = 0;
	// for(int i = 1; i <= n; i++) tmp[i] = -inf;
	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= i; j++) {
	// 		if(j + len - 1 <= n && j + len - 1 >= i)
	// 			tmp[i] = max(tmp[i], S[j + len - 1] - S[j - 1]);
	// 	}
	// }
	for(int i = 1; i <= n - len + 1; i++) b[i] = S[i + len - 1] - S[i - 1];
	for(int i = 1; i <= n; i++) {
		while(fr <= tl && i <= n - len + 1 && b[que[tl]] <= b[i]) tl--;
		while(fr <= tl && que[fr] + len - 1 < i) fr++;
		if(i <= n - len + 1) que[++tl] = i;
		tmp[i] = b[que[fr]];
		// if(b[que[fr]] != tmp[i]) {
			// cout << "?\n";
			// return ;
		// }
	}
}
int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], S[i] = S[i - 1] + a[i];
	cin >> q;
	for(int i = 1; i <= q; i++) {
		cin >> ql[i] >> qr[i];
		for(int j = ql[i]; j <= qr[i]; j++)
			vis[j] = 1, qy[j].push_back(i);
		for(int j = 1; j <= n; j++)
			ans[i][j] = -inf;
	}

	for(int i = 1; i <= n; i++) {
		if(!vis[i]) continue;
		work(i);

		for(int J = 0; J < qy[i].size(); J++) {
			int j = qy[i][J];
			if(i >= ql[j] && i <= qr[j])
				for(int k = 1; k <= n; k++)
					ans[j][k] = max(ans[j][k], tmp[k]);
		}
	}
	for(int i = 1; i <= q; i++) {
		ull rest = 0;
		for(int j = 1; j <= n; j++)
			rest ^= (ull)((ull)j * (ull)ans[i][j]);
		cout << rest << '\n';
	}
	// cerr << (&ed - &st) / 1024.0 / 1024.0 << '\n';
}