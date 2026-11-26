#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,m;
int fa[8005];
int a[8005];
int rt;
int s;
int ans;
bool su[8005][8005];
vector<int> e[8005];
void f_tree (int u) {
	for(int i=0;i<=n;i++) {
		su[i][u]=false;
	}
	su[a[u]][u]=true;
	for(int i=0;i<e[u].size();i++) {
		int v=e[u][i];
		f_tree(v);
		for(int j=0;j<=n;j++) {
			if(su[j][v]) {
				su[j][u]=true;
			}
		}
	}
	for(int i=0;i<=n;i++) {
		if(!su[i][u]) {
			s+=i;
			break;
		}
	}
	return ;
}
void dfs (int i) {
	if(i==n+1) {
		s=0;
		f_tree(rt);
		ans=max(ans,s);
		return ;
	}
	for(int j=0;j<=n;j++) {
		a[i]=j;
		dfs(i+1);
	}
	return ;
}
signed main () {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	//clock_t st=clock();
	while(t--) {
		cin>>n>>m;
		for(int i=1;i<=n;i++) {
			e[i].clear();
		}
		//cout<<n<<" "<<m<<endl;
		for(int i=2;i<=n;i++) {
			cin>>fa[i];
			e[fa[i]].push_back(i);
		}
		rt=1;
		//cout<<1<<endl;
		dfs(1);
		cout<<ans<<"\n";
	}
	//clock_t en=clock();
	//cout<<en-st;
	return 0;
}
/*
2
5 2
1 1 2 2
7 2
1 1 2 2 2 3
*/
