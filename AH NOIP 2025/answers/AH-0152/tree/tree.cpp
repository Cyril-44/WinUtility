#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=8010,M=2*N;
int n,m;
int head[N],Next[M],ver[M],tot,fa[N];
void add(int x,int y){
	ver[++tot]=y;
	Next[tot]=head[x];head[x]=tot;
}
int mex[N],ans,num[N];
void dfs(int x){
	int son=0,val=0,cnt=0;
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		dfs(y);
		cnt++;
		num[x]+=num[y]-1;
		if(mex[y]>val){
			val=mex[y];
			son=y;
		}
	}
	if(val==0){
		mex[x]=1;
		num[x]=1;
		return;
	}
	mex[x]+=mex[son]+cnt;
	num[x]+=mex[x]+1;
	// cout<<"*"<<x<<" "<<num[x]<<endl;
}
void slove(){
	dfs(1);
	cout<<num[1]<<endl;
}
int sz[N];
void dfssize(int x){
	sz[x]=1;
	for(int i=head[x];i;i=Next[i]){
		dfssize(ver[i]);
		sz[x]+=sz[ver[i]];
	}
}
int nnum[N],ssum;
bitset<N>v[N];
int mexx(int x){
	for(int i=0;i<=n+1;i++)
		if(v[x][i]==0)return i;
	return n+1;
}
void dfs2(int x){
	v[x].reset();
	v[x][nnum[x]]=1;
	// cout<<nnum[x]<<"*";
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		dfs2(y);
		v[x]|=v[y];
	}
	// cout<<x<<":"<<endl;
	// cout<<ssum<<endl;
	// if(v[x][0]==1)cout<<"^";
	ssum+=mexx(x);
}
int st;
void dfs1(int x){
	// if(clock()-st>5.2*CLOCKS_PER_SEC)return;
	if(x>n){
	// 	int add=0;
	// for(int i=1;i<=n;i++)
	// 	add+=nnum[i];
	// if(add<(1+n)*n/4)return;

	// 	for(int i=1;i<=n;)
		// cout<<nnum[i]<<" ";
		// cout<<endl;
		ssum=0;
		dfs2(1);
		// cout<<ssum<<endl;
		ans=max(ans,ssum);
		return;
	}
	for(int i=sz[fa[x]]+1;i>=0;i--){
		nnum[x]=i;
		dfs1(x+1);
	}
}
void sol1(){
	// memset(sz,0,sizeof sz);
	dfssize(1);
	// cout<<endl;
	fa[1]=1;
	dfs1(1);
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
	memset(head,0,sizeof head);
	memset(mex,0,sizeof mex);
	memset(num,0,sizeof num);
	tot=0;
	ans=0;
		cin>>n>>m;
	for(int i=2;i<=n;i++){
		cin>>fa[i];
		add(fa[i],i);
	}
		if(m<=2)
		slove();
		else{
			st=clock();
			sol1();
		}
	}
	return 0;
}