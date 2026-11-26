#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,f[10005],rd[10005];
int cnt=0,head[10005],fa[10005];
int dep[10005];
long long ans=0;
struct st{
	int to,next;
}e[20005];
void add(int x,int y){
	e[++cnt]={y,head[x]},head[x]=cnt;
}
int mx=0;
void dfs2(int x){
	for(int i=head[x];i;i=e[i].next){
		int to=e[i].to;
		if(dep[to]==dep[x]-1){
			f[to]=max(f[to],f[x]+1);
			dfs2(to);
		}
	}
}
void dfs3(int x,int fax){
	for(int i=head[x];i;i=e[i].next){
		int to=e[i].to;
		if(to!=fax){
			dep[to]=dep[x]+1;
			dfs3(to,x);
		}
	}
}
void get(int x,int fax){
	if(rd[x]==0&&f[x]==0) ans++;
	if(rd[x]>0) ans+=f[x]+1; 
	for(int i=head[x];i;i=e[i].next){
		int to=e[i].to;
		if(to!=fax){
			get(to,x);
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cnt=0;
		memset(head,0,sizeof(head));
		memset(rd,0,sizeof(rd));
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++){
			scanf("%d",&x);
			fa[i+1]=x;
			add(i+1,x);
			add(x,i+1);
			rd[x]++;
		}
		for(int i=1;i<=n;i++){
			if(rd[i]==0){
				f[i]=f[fa[i]];
				f[fa[i]]++;
			}
		}
		dfs3(1,0);
		for(int i=1;i<=n;i++){
			if(rd[i]==0){
				dfs2(i);
			}
		}
		get(1,0);
		cout<<ans<<endl;
	}
}
