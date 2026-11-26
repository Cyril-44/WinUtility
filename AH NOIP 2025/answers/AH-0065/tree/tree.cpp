#include <iostream>
#include <vector>
using namespace std;
const int N=1e5+5;
int test,n,fa[N],sz[N],ans;
vector<int>G[N];
void dfs(int u,int ff){
	fa[u]=ff;
	sz[u]=1;
	for(int v:G[u]){
		if(v==ff) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
bool vs[N];
int val[N];
void dfs2(int u,int ff){
	vs[val[u]]=1;
	for(int v:G[u]){
		if(v==ff) continue;
		dfs2(v,u);
	}
}
void work(int pos){
	if(pos==n+1){
		int now=0;
		for(int i=1;i<=n;i++){
			dfs2(i,fa[i]);
			int op=n+1;
			for(int j=0;j<=n;j++){
				if(!vs[j]){
					op=j;
					break;
				}
			}
			now+=op;
			for(int j=0;j<=n;j++) vs[j]=0;
		}
		ans=max(ans,now);
		return;
	}
	for(int j=0;j<=n;j++){
		val[pos]=j;
		work(pos+1);
	}
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>test;
	int m;
	while(test--){
		ans=0;
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			G[i].push_back(x);
			G[x].push_back(i);
		}
		dfs(1,0);

		work(1);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) G[i].clear();
	}
	return 0;
}
