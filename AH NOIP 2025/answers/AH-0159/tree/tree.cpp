#include<bits/stdc++.h>
using namespace std;
int t,n,m,head[8005],v[8005],dp[8005],f[8005][2];
struct edge{
	int to,next;
}e[8005];
inline void dfs(int now){
	v[now]=1;
	int xu=0;
	for(int i=head[now];i;i=e[i].next){
		dfs(e[i].to);
		v[now]+=v[e[i].to];
		dp[now]=max(dp[now],dp[e[i].to]);
		if(f[e[i].to][1]>f[xu][1]) xu=e[i].to;
	}
	if(xu!=0){
		f[now][1]=f[xu][1]+1;
		f[now][0]=f[xu][0]+f[now][1]+1;
	}
	for(int i=head[now];i;i=e[i].next){
		if(e[i].to==xu) continue;
		if(v[e[i].to]>=f[e[i].to][0]) f[now][1]+=v[e[i].to];
		f[now][0]=max(f[now][0]+f[e[i].to][0],f[now][0]+v[e[i].to]);
	}
	dp[now]+=v[now];
	if(dp[now]>=f[now][0]) f[now][0]=dp[now],f[now][1]=v[now]-1;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		memset(head,0,sizeof(head));
		memset(dp,0,sizeof(dp));
		memset(f,0,sizeof(f));
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			int x;
			scanf("%d",&x);
			e[i-1]={i,head[x]};
			head[x]=i-1;
		}
		dfs(1);
		cout<<f[1][0]<<endl;
	}
}
