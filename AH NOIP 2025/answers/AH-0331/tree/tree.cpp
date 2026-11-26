#include<bits/stdc++.h>
using namespace std;
vector<int>vt[10005];
int fa[100005];
int siz[100005];
int son[100005];
int nval[100005];
int dep[100005];
int f[100005];
void dfs1(int now,int deep){
	siz[now]=1;
	dep[now]=deep;
	int maxsiz=0;
	for(int i=0;i<vt[now].size();i++){
		dfs1(vt[now][i],deep+1);
		siz[now]+=siz[vt[now][i]];
		if(siz[vt[now][i]]>maxsiz){
			maxsiz=siz[vt[now][i]];
			son[now]=vt[now][i];
		}
	}
}
int ans[8005];
void dfs2(int root,int now){
	if(!son[now]){
		nval[now]=0;
		ans[now]++;
		return;
	}
	dfs2(root,son[now]);
	ans[now]=ans[son[now]];int ksiz=0;
	ksiz=nval[son[now]]+1;
	
	for(int i=0;i<vt[now].size();i++){
		int v=vt[now][i];
		if(v==son[now])continue;
		if((dep[now]-dep[root])*siz[v]>=ans[v]){
			ksiz+=siz[v];
		}
		else{
			ans[now]+=ans[v];
			nval[now]=max(nval[now],nval[v]);
		}
	}
		nval[now]+=ksiz;
	ans[now]+=nval[now]+1;
}
void dfs3(int now){
	for(int i=0;i<vt[now].size();i++){
		int v=vt[now][i];
		if(v==son[now])continue;
		dfs3(v);
	}
	memset(nval,-1,sizeof(nval));
	dfs2(now,now);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=8000;i++){
		f[i]=(1+i)*i/2;
	}
	while(t--){
		memset(siz,0,sizeof(siz));
		memset(nval,-1,sizeof(nval));
		memset(dep,0,sizeof(dep));
		memset(son,0,sizeof(son));
		memset(ans,0,sizeof(ans));
		//memset)
		for(int i=1;i<=8000;i++)vt[i].clear();
		int n,m;
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			cin>>fa[i];
			vt[fa[i]].push_back(i);
		}
		dfs1(1,1);
		dfs3(1);
		cout<<ans[1]<<"\n";
	}
	return 0;
}
