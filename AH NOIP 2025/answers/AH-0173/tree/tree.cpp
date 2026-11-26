#include<iostream>
#include<vector>
using namespace std;
int fa[8010];
vector < int > adj[8010];
bool vis[8010];
int h[8010];
int zhi[8010];
int n,m;
int cn[8010];
void dfs(int q){
	if(q==1){
		h[q]=1;
	}
	else{
		h[q]=h[fa[q]]+1;
	}
	for(int i=0;i<cn[q];i++){
		int u=adj[q][i];
		dfs(u);
	}
	return;
}
bool check(int q){
	if(vis[q]==1){
		return 1;
	}
	for(int i=0;i<cn[q];i++){
		if(vis[adj[q][i]]==1){
			vis[q]=1;
			zhi[q]=max(zhi[q]-1,zhi[adj[q][i]])+1;
		}
	}
	return vis[q];
}
void find(int q){
	if(q==0){
		return;
	}
	for(int i=1;i<=n;i++){
		if(h[i]==h[q]&&vis[i]==0){
			if(check(fa[i])){
				zhi[fa[i]]++;
			}
			else{
				zhi[fa[i]]=2;
				zhi[i]=1;
				vis[fa[i]]=1;
			}
			vis[i]=1;
		}
		else if(h[i]==h[q]&&vis[i]!=0){
			check(fa[i]);
		}
	}
	find(fa[q]);
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			cin>>fa[i];
			adj[fa[i]].push_back(i);
			cn[fa[i]]++;
		}
		dfs(1);
		int ma=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			if(h[i]>ma){
				ma=h[i];
				cnt=i;
			}
		}
		zhi[cnt]=1;
		zhi[fa[cnt]]=2;
		vis[cnt]=1;
		vis[fa[cnt]]=1;
		find(cnt);
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=zhi[i];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
