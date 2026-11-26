//LUOGU_UID: 520777
//LUOGU_Username: Laoxu666
//Wuhu HCZX 2025 Grade 7 Class 3
//NOIP RP++
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100005
int N, M;
pair<int, int> Arr[MAXN];
vector<int> Graph[MAXN];
//CODE
bool Compare1(pair<int, int> A, pair<int, int> B) {
	return A.first + A.second < B.first + B.second;
}
bool Compare2(pair<int, int> A, pair<int, int> B) {
	return A.first < B.first;
}
int Sum[MAXN];
signed main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	//CODE
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		cin >> Arr[i].first >> Arr[i].second;
	}
	sort(Arr + 1, Arr + N + 1, Compare2);
	for(int i = 1; i <= N; i++) {
		Sum[i] = Sum[i - 1] + Arr[i].first;
	}
	sort(Arr + 1, Arr + N + 1, Compare1);
	int Ans = 0;
	for(int i = 1; i <= N; i++) {
		int This = M - Sum[i];
		int Num = This / (Arr[1].first + Arr[1].second) * 2 + i;
		Ans = max(Ans, Num);
	}
	cout << Ans << '\n';
	return 0;
}