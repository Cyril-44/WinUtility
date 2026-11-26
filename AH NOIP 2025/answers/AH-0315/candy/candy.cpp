#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int Mod = 1000000007;
const int Inf_I = 0x3f3f3f3f;
const long long Inf_L = 0x3f3f3f3f3f3f3f3f;
long long n, m;
struct Candy {
	long long x, y;
	int id;
	bool Is;
} C[1000005];
bool Cmp (Candy a, Candy b) {
	return a.x + a.y < b.x + b.y;
}
bool vis[1000005];
bool CMp (Candy a, Candy b) {
	return (a.id ? a.y : a.x) < (b.id ? b.y : b.x) ;
}
int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> C[i].x >> C[i].y;
	sort(C + 1, C + n + 1, Cmp);
	Candy Fir = C[1];
	C[1].Is = 1;
//	long long Tot1 = m / (C[1].x + C[1].y) * 2;
//	long long m2 = m % (C[1].x + C[1].y);
//	sort(C + 1, C + n + 1, CMp) 
//	for (int i = 1; i <= n; i++) {
//		if (C[i].x <= m2) m2 -= 
//	}
	sort(C + 1, C + n + 1, CMp);
	long long Tot = m / (Fir.x + Fir.y) * 2 + ((m % (Fir.x + Fir.y)) >= Fir.x ? 1 : 0);
	int dd = 0;
	for (int i = 1; i <= n; i++) {
	//	if (C[i].x * 2 < Fir.x + Fir.y && m >= C[i].x)
	//		m -= C[i].x, ++Tot, C[i].id = 1, cout << C[i].x << '\n';
		if (C[i].Is) continue;
		++dd;
		m -= C[i].x;
		if (m < 0) break;
		long long T = dd;
		T += m / (Fir.x + Fir.y) * 2 + ((m % (Fir.x + Fir.y)) >= Fir.x ? 1 : 0);
		Tot = max(Tot, T);
	}
	
	//cout << m << '\n' << Fir.x << ' ' << Fir.y << '\n';
	//Tot += (m / (Fir.x + Fir.y)) * 2;
	//cout << (m / (Fir.x + Fir.y)) * 2 << '\n';
	//m %= (Fir.x + Fir.y);
	//sort(C + 1, C + n + 1, CMp);
	//cout << m << '\n';
	//for (int i = 1; i <= n; i++) {
	//	if ((C[i].id ? C[i].y : C[i].x) <= m) {
	//		++Tot;
	//		cout << m << ' ' << (C[i].id ? C[i].y : C[i].x) << ' ' << C[i].id << '\n';
	//		m -= (C[i].id ? C[i].y : C[i].x);
	//	} else {
	//		break;
	//	}		
	//}
	cout << Tot;
	return 0;
}
//   NOIP Rp++
//  来中杨、王狗灏
//    一路走好
//   *   *   *
//    \  |  /
//     \ | /
//   |  \|/  |
//   ---------
//   ---------
//T1比滚木还简单 AC 100pts
//Use UTF-8.
