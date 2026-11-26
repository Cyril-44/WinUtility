#include<bits/stdc++.h>
using namespace std;
int fa[8005],vis[8005];
vector<int> son[8005];
vector<int> bro[8005];
int zh[8005];
long long ans=0;
void dfs(int u){
	if(son[u].empty()){
		if(bro[u].empty())zh[u]=0;
		else if(vis[fa[u]]==0){
			zh[u]=0;
			vis[fa[u]]=1;
		}
		else{
			int ys=0;
			for(int v:bro[u]){
				ys=max(ys,zh[v]);
			}
			zh[u]=ys+1;
		}
		return;
	}
	int maxn=0;
	for(int f:son[u]){
		dfs(f);
		maxn=max(maxn,zh[f]);
	}
	zh[u]=maxn+1;
	return;
}
void dfs2(int u){
	if(zh[u]==0&&son[u].empty())ans+=1;
	else if(zh[u]!=0&&son[u].empty())ans+=0;
	else ans+=zh[u]+1;
	for(int v:son[u]){
		dfs2(v);
	}
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		memset(fa,0,sizeof(fa));
		memset(zh,0,sizeof(zh));
		memset(vis,0,sizeof(vis));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			bro[i].clear();
			son[i].clear();
		}
		fa[1]=1;
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			fa[i]=x;
			son[x].push_back(i);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(fa[i]==fa[j]){
					bro[i].push_back(j);
					bro[j].push_back(i);
				}
			}
		}
		dfs(1);
		dfs2(1);
		cout<<ans<<endl;
	}
	return 0;
}
