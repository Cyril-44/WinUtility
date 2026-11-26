#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
struct node{
	int next,to;
}edge[N*2];
int head[N],cnt=0;
void addedge(int u,int v){
	edge[++cnt].next=head[u];
	head[u]=cnt;
	edge[cnt].to=v;
}
ll ans=0,s=0,a[N],n,m;
vector<int>vis[N];
void dfs(int u,int fa){
	vis[u].clear();
	vis[u].push_back(a[u]);
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,u);
		for(int j=0;j<vis[v].size();j++)
			vis[u].push_back(vis[v][j]);
	}
	sort(vis[u].begin(),vis[u].end());
	int k=0;
	for(int i=0;i<vis[u].size();i++){
		if(vis[u][i]==k)k++;
		else if(vis[u][i]>=k+1)
			break;
	}
	s+=k;
}
void dfs1(int u){
	if(u>n){
		s=0,dfs(1,0);
		ans=max(ans,s);
		return;
	}
	for(int i=0;i<=n+1;i++)
		a[u]=i,dfs1(u+1);
}
void cl(){
	memset(head,0,sizeof(head));
	cnt=0;
	n=read(),m=read();
	for(int i=2;i<=n;i++){
		int k=read();
		addedge(i,k),addedge(k,i);
	}
	ans=0;
	dfs1(1);
	printf("%lld\n",ans);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t=read();
	while(t--){
		cl();
	}
	return 0;
}