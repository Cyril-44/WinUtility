#include<bits/stdc++.h>
using namespace std;

bool flag = true;
vector <int> t[100005];
long long T, n, m, x, dep[100005], siz[100005], son[100005], fro[100005], a[100005];

void dfs(long long k, long long deep){
	dep[k] = deep;
	siz[k] = 1;
	for(int i = 0; (long unsigned int)i < t[k].size(); i++){
		int y = t[k][i];
		dfs(y, deep + 1);
		siz[k] += siz[y];
		if(siz[son[k]] < siz[y])
			son[k] = y;
	}
}

void dfs2(long long k, long long front){
	fro[k] = front;
	if(son[k])
		dfs2(son[k], front);
	for(int i = 0;(long unsigned int)i < t[k].size(); i++){
		int y = t[k][i];
		if(y != son[k])
			dfs2(y, y);
	}
}

long long getso(long long roof, long long k){
	long long sum = 0;
	if(son[k])
		sum += getso(roof, son[k]);
	else{
		a[k] = 0;
		return 1;
	}
	a[k] = a[son[k]] + 1;
	for(int i = 0; (long unsigned int)i < t[k].size(); i++){
		int y = t[k][i];
		if(y != son[k]){
			long long t = getso(y, y);
			if(t > (dep[k] - dep[roof] + 1) * siz[y]){
				sum += t;
				a[k] = max(a[k], a[y]);
			}
			else{
				a[k] += siz[y];
			}
		}
	}
	sum += (a[k] + 1);
	return sum;
}

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			dep[i] = 0;
			son[i] = 0;
			a[i] = 0;
			t[i].clear();
			flag = true;
		}
		a[0] = 0;
		for(int i = 1; i < n; i++){
			cin >> x;
			t[x].push_back(i + 1);
		}
		dfs(1, 1);
		dfs2(1, 1);
		cout << getso(1, 1) << endl;
	}
	return 0;
}
