#include <bits/stdc++.h>
using namespace std;
struct candy {
	int a,m;
	float c;
}x[10010];
long long n,w,s[5010][20][2],ans;
bool check (candy q,candy p) {
	return q.c>p.c||(q.c==p.c&&q.a>p.a);
}
void dfs(int e) {
	if (e==n+1) {
		for (int i=0;i<=w;i++) {
			for (int j=0;j<=n;j++) {
				s[i][j][0]=s[i][j][1]=0;
			}
		}
		for (int i=1;i<=w;i++) {
			for (int j=1;j<=n;j++) {
				if (i>=x[j].m) {
					s[i][j][1]=max(s[i-x[j].m][j-1][0],s[i-x[j].m][j-1][1])+x[j].a;
				}
				s[i][j][0]=max(s[i][j-1][0],s[i][j-1][1]);
			}
		}
		candy x1[10010];
		for (int i=1;i<=n;i++) {
			x[i].c=x[i].a*1.0/x[i].m;
		}
		for (int i=1;i<=n;i++) {
			x1[i].a=x[i].a;
			x1[i].m=x[i].m;
			x1[i].c=x[i].c;
		}
		sort (x1+1,x1+n+1,check);
		int d=w,mx=0;
		for (int i=1;i<=n;i++) {
			if (d>=x1[i].m) {
				d-=x1[i].m;
				mx+=x1[i].a;
			}
		}
		if (mx==max(s[w][n][0],s[w][n][1])) {
			ans++;
			ans%=998244353;
		}
	} else {
		for (int i=1;i<=2;i++) {
			x[e].m=i;
			dfs(e+1);
		}
	}
	return;
}
int main () {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int z,t;
	cin>>z>>t;
	while (t--) {
		ans=0;
		cin>>n>>w;
		for (int i=1;i<=n;i++) {
			cin>>x[i].a;
		}
		dfs(1);
		cout<<ans;
	}
	return 0;
}
