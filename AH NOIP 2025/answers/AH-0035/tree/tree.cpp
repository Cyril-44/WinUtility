#include<bits/stdc++.h>
using namespace std;
const int N=8010;
int T,n,m,vl[N];
vector<int> e[N];
int ans,cnt;
bitset<1610> f[N];
void dfs(int u){
	//cout<<u<<' ';
	f[u][vl[u]]=true;
	for(auto v:e[u]){
		dfs(v);
		f[u]|=f[v];
	}
	for(int i=0;i<=m*2;i++) {
		if(!f[u][i]) {cnt+=i;break;}
	}
}
void fil(int dep){
	//cout<<dep<<endl;
	if(dep==n+1){
		cnt=0;
		for(int i=1;i<=n;i++) f[i]&=0;
		dfs(1);
		//for(int i=1;i<=n;i++) cout<<vl[i]<<' ';cout<<endl;
		//cout<<cnt<<'\n';
		ans=max(ans,cnt);return;
	}
	for(int i=0;i<=m*2;i++) vl[dep]=i,fil(dep+1);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;memset(vl,0,sizeof(vl));cnt=0;
		cin>>n>>m;for(int i=1;i<=n;i++) f[i]&=0;
		for(int i=1,fa;i<=n-1;i++) cin>>fa,e[fa].push_back(i+1);
		fil(1);
		cout<<ans<<'\n';
	}
	return 0;
}
