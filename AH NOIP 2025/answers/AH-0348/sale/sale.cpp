//LUOGU_UID: 520777
//LUOGU_Username: Laoxu666
//Wuhu HCZX 2025 Grade 7 Class 3
//NOIP RP++
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 5005
#define MOD 998244353
int N, Arr[MAXN], C, T, M;
int Num[MAXN];
int DP[MAXN];
int Id[MAXN], Val[MAXN];
bool Comp(int A, int B) {
	if(Val[A] == Val[B]) return Arr[A] > Arr[B];
	return Val[A] > Val[B];
}
bool Check() {
	for(int i = 1; i <= M; i++) DP[i] = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = M; j >= Num[i]; j--) {
			DP[j] = max(DP[j], DP[j - Num[i]] + Arr[i]);
		}
	}
	int Sum = 0;
	for(int i = 1; i <= N; i++) {
		Val[i] = Arr[i] * 2 / Num[i];
		Id[i] = i;
	}
	sort(Id + 1, Id + N + 1, Comp);
	int TmpM = M;
	for(int i = 1; i <= N; i++) {
		if(TmpM - Num[Id[i]] >= 0) {
			TmpM -= Num[Id[i]];
			Sum += Arr[Id[i]];
		}
	}
	return Sum == DP[M];
}
signed main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	cin >> C >> T;
	for(int i = 1; i <= T; i++) {
		cin >> N >> M;
		for(int j = 1; j <= N; j++)
			cin >> Arr[j];
		int Ans = 0;
		for(int j = 0; j < (1 << N); j++) {
			for(int k = 1; k <= N; k++) {
				if(j & (1 << (k - 1))) Num[k] = 1;
				else Num[k] = 2;
			}
			Ans += Check();
		}
		cout << Ans << '\n';
	}
	return 0;
}