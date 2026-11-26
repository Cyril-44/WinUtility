#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=8010;
int T,n,m,a[N],fa[N],sz[N];
vector<int>g[N];
LL res;
bool st[N];
void add(int a,int b){
	g[a].emplace_back(b);
}
void Dfs(int u){
	st[a[u]]=true;
	for(int j:g[u]){
		Dfs(j);
	}
}
LL calc(){
	LL res=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n+1;j++) st[j]=false;
		Dfs(i);
		for(int j=0;j<=n+1;j++){
			if(!st[j]){
				res+=j;
				break;
			}
		}
	}
	return res;
}
void DFS(int u){
	sz[u]=1;
	for(int &j:g[u]){
		DFS(j);
		sz[u]+=sz[j];
	}
}
void dfs(int u){
	if(u==n+1){
		res=max(res,calc());
		return;
	}
	for(int i=0;i<=sz[u]+1;i++){
		a[u]=i;
		dfs(u+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	for(cin>>T;T--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			g[i].clear();sz[i]=0;
		}
		for(int i=2;i<=n;i++){
			cin>>fa[i];
			add(fa[i],i);
		}
		DFS(1);
		res=0;
		dfs(1);
		cout<<res<<"\n";
	}
	return 0;
}