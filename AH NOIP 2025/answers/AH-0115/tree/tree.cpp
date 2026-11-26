#include<bits/stdc++.h>
using namespace std;
int t,n,m,p,v[8005],num[8005],ans,leaf[8005];
vector<int>e[8005];
void dfs(int fa,int now){
	int cnt=0;
	for(int i=0;i<e[now].size();i++){
		if(fa==e[now][i])continue;
		dfs(now,e[now][i]);
		if(leaf[e[now][i]]==0){
			num[e[now][i]]=cnt;
			v[e[now][i]]=int(cnt++==0);
		}
		num[now]=max(num[e[now][i]]+1,num[now]);
		v[now]=num[now]+1;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		for(int i=1;i<=n;i++)e[i].clear();
		memset(leaf,0,sizeof(leaf));
		memset(num,0,sizeof(num));
		memset(v,0,sizeof(v));
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++){
			scanf("%d",&p);
			leaf[p]=1;
			e[p].push_back(i+1);
		}
		dfs(0,1);
		for(int i=1;i<=n;i++){
			ans+=v[i];
		}
		printf("%d\n",ans);
	}
}
