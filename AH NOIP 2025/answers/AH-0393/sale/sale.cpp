#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5, mod = 998244353, M = 2e3 + 1;
struct node{
	int a, w, num;
	double v;
	bool flag = 0;
}g[N], g2[N];
int n, ans;
double m, s, s2;
bool out = 0;
bool cmp(node x, node y){
	if(x.v != y.v) return x.v > y.v;
	else if (x.a != y.a) return x.a > y.a;
	return x.num < y.num;
}
void check(){
	double temp = 0;
	for(int i = 1;i <= n;i ++) if(g[i].flag == 1) temp += g[i].a;
	s2 = max(temp, s2);
	if(s2 > s) {out = 1; return;}
}
void dfs2(int x, int y){
	if(out == 1) return ;
	if(y > m) return ;
	if(x == n + 1){check();return;}
	g[x].flag = 0;
	dfs2(x + 1, y);
	g[x].flag = 1; 
	dfs2(x + 1, y + g[x].w);
}
void dfs(int x){
	if(x == n + 1){
		s = s2 = 0; double mm = m;
		for(int i = 1;i <= n;i ++) g[i].v = double(g[i].a) / g[i].w;
		for(int i =1;i <= n;i ++) g2[i].a = g[i].a, g2[i].w = g[i].w, g2[i].v = g[i].v;
		sort(g2 + 1, g2 + n + 1, cmp);
		for(int i = 1;i <= n;i ++){
			if(mm >= g2[i].w){
				mm -= g2[i].w;
				s += g2[i].a;
			}
		}
		out = 0;
		dfs2(1, 0);
		if(s == s2 && out == 0) {ans ++;ans = ans % mod;}
		return;
	}
	g[x].w = 2; 
	dfs(x + 1);
	g[x].w = 1;
	dfs(x + 1);
}
int main()
{
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T --){
		ans = 0;
		scanf("%d %lf", &n, &m);
		for(int i = 1;i <= n;i ++) {scanf("%d", &g[i].a); g[i].num = i;}
		dfs(1);
		printf("%d\n", ans);	
	}
	return 0;
}
//Hello,world!
