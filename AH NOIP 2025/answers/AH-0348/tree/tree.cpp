//LUOGU_UID: 520777
//LUOGU_Username: Laoxu666
//Wuhu HCZX 2025 Grade 7 Class 3
//NOIP RP++
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 15
#define MAXSTAT (1 << 13)
int N, Arr[MAXN], T, M;
vector<int> Graph[MAXN];
int DP[MAXN][MAXSTAT];
int Tmp[MAXSTAT];
int Size[MAXN];
int Mex(int Stat) {
	for(int i = 0; i < N; i++) {
		if(!(Stat & (1 << i))) return i;
	}
	return N;
}
void DFS(int Node1, int Previous) {
	memset(DP[Node1], -0x1F, sizeof DP[Node1]);
	DP[Node1][0] = 0;
	Size[Node1] = 0;
	for(int Node2 : Graph[Node1]) {
		if(Node2 != Previous) {
			DFS(Node2, Node1);
			Size[Node1] += Size[Node2];
			memcpy(Tmp, DP[Node1], sizeof Tmp);
			for(int i = 0; i < (1 << N); i++) {
				if(__builtin_popcount(i) > Size[Node1]) continue;
				for(int j = 0; j < (1 << N); j++) {
					if(__builtin_popcount(j) > Size[Node2]) continue;
					Tmp[i | j] = max(Tmp[i | j], DP[Node1][i] + DP[Node2][j]);
					//if(DP[Node1][i] + DP[Node2][j] >= 0) //cerr << (i | j) << ' ' << i << ' ' << j << ' ' << ' ' << DP[Node1][i] << ' ' << DP[Node2][j] << '\n';
				}
			}
			memcpy(DP[Node1], Tmp, sizeof Tmp);
		}
	}
	Size[Node1]++;
	memset(Tmp, -0x1F, sizeof Tmp);
	//cerr << Node1 << "  ";
	for(int i = 0; i < (1 << N); i++) {
		if(__builtin_popcount(i) >= Size[Node1]) continue;
		//cerr << Tmp[i] << ' ';
		for(int j = 0; j < N; j++) {
			Tmp[i | (1 << j)] = max(Tmp[i | (1 << j)], DP[Node1][i] + Mex(i | (1 << j)));
		}
	}
	//cerr << '\n';
	memcpy(DP[Node1], Tmp, sizeof DP[Node1]);
}
//CODE
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	//CODE
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N >> M;
		for(int j = 1; j <= N; j++) Graph[j].clear();
		for(int j = 2; j <= N; j++) {
			int Node1, Node2;
			cin >> Node2;
			Node1 = j;
			Graph[Node1].push_back(Node2);
			Graph[Node2].push_back(Node1);
			// //cerr << Node1 << ' ' << Node2 << '\n';
		}
		DFS(1, 0);
		int Ans = 0;
		for(int j = 0; j < (1 << N); j++) {
			Ans = max(Ans, DP[1][j]);
		}
		cout << Ans << '\n';
	}
	return 0;
}