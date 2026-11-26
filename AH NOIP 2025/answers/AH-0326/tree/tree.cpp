#include<bits/stdc++.h>
using namespace std;
const int N=8e3+5;
int t;
int n,m,ans,sum;
int a[N],b[N];
vector<int> G[N];
vector<int> dfn(int u,int fa){
	vector<int> c;
	c.clear();
	c.push_back(b[u]);
	for(auto v:G[u]){
		if(v!=fa){
			vector<int> d=dfn(v,u);
			for(int i=0;i<d.size();i++){
				c.push_back(d[i]);
			}
		}
	}
	sort(c.begin(),c.end());
	c.erase(unique(c.begin(),c.end()),c.end());
	for(int i=0;i<c.size();i++){
		if(c[i]!=i){
			sum+=i;
			return c;
		}
	}
	sum+=c.size();
	return c;
}
void dfs(int x){
	if(x==n+1){
		sum=0;
		dfn(1,0);
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<n;i++){
		b[x]=i;
		dfs(x+1);
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		for(int i=2;i<=n;i++){
			cin>>a[i];
			G[a[i]].push_back(i);
		}
		if(n<=7){
			dfs(1);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
