#include <bits/stdc++.h>
using namespace std;
const int N = 8e3 + 5;
int m, tem = 0;
struct node{
	int h, s, num = 0;
	vector <int> g;
}a[N];
void dfs(int x){
	for(auto v : a[x].g){
		dfs(v);
		a[x].s += a[v].s + 1;
	}
}
bool cmp(int x, int y){
	return a[x].s > a[y].s;
}
bool cmp2(int x, int y){
	return a[x].s < a[y].s;
}
void find_ans(int x){
	if(a[x].h == m - 1){
		int siz = a[x].g.size();
		for(int i = 0;i < siz;i ++) a[a[x].g[i]].num = i;
		a[x].num = a[x].s;
		return ;
	}
	int maxn = 0;
	for(auto y : a[x].g){
		find_ans(y);
		maxn = max(maxn, a[y].num);
	}
	a[x].num = maxn + 1;
}
void dfs3(int x){
	a[x].num = tem; tem --;
	for(auto y : a[x].g){
		dfs3(y);//cout << "dfs:  " << y <<endl;
	}
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int T, n, p, ans = 0, ans2 = 0;
	cin >> T;
	while(T --){
		cin >> n >> m; tem = n - 1;
		memset(a, 0, sizeof a);
		ans = 0; ans2 = 0;
		for(int i = 1;i <= N - 5;i ++) a[i].g = vector <int> ();
		for(int i = 1;i < n;i ++){
			scanf("%d", &p);
			a[i + 1].h = a[p].h + 1;
			a[p].g.push_back(i + 1);
		}
		dfs(1);
		for(int i = 1;i <= n;i ++) sort(a[i].g.begin(), a[i].g.end(), cmp);
		find_ans(1);
		for(int i = 1;i <= n;i ++) if(a[i].s >= a[i].num) ans += a[i].num + 1;
		for(int i = 1;i <= n;i ++) sort(a[i].g.begin(), a[i].g.end(), cmp2);
		dfs3(1);
		for(int i = 1;i <= n;i ++) if(a[i].s >= a[i].num) ans2 += a[i].num + 1;
		cout << max(ans, ans2) << endl;
	}
	return 0;
}
//Hello,world!
