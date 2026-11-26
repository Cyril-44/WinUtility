#include<bits/stdc++.h>
using namespace std;
#define N 10005
int t,n,m;
struct node{
	int to,nex;
}edge[N];
int head[N],cnt=0;
void add(int u,int v){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].nex=head[u];
	head[u]=cnt;
}
/*int dep[N],ans[N],val[N];
vector<int> son[N];
int sv[N];
void dfs(int u,int f){
//cout<<u<<endl;
	int v;
	for(int i=head[u];i;i=edge[i].nex){
		v=edge[i].to;
		dfs(v,u);
		son[u].push_back(val[v]);
	}
	son[u].push_back(val[u]);
	int l=son[u].size();
	for(int i=0;i<l;i++){
		sv[i]=son[u][i];
	}
	sort(sv,sv+l);
	int now=-1;
	for(int i=0;i<l;i++){
		if(sv[i]!=now+1){
			ans[u]=now+1;
		}
		else{
			now=sv[i];
		}
	}
*/
int fin_ans=0;
int siz[N];
void dfs3(int u,int f){
	int v;
	siz[u]=1;
	for(int i=head[u];i;i=edge[i].nex){
		v=edge[i].to;
		dfs3(v,u);
		siz[u]+=siz[v];
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&t);
	int f,v,maxN=0;
	while(t--){
		scanf("%d%d",&n,&m);
		memset(head,0,sizeof(head));
		cnt=0;
		for(int i=2;i<=n;i++){
			scanf("%d",&f);
			add(f,i);
		}
		if(m<=2){
			fin_ans=0;
			maxN=0;
			memset(siz,0,sizeof(siz));
			dfs3(1,0);
			for(int j=head[1];j;j=edge[j].nex){
				v=edge[j].to;
				maxN=max(maxN,siz[v]);
				fin_ans+=siz[v]+1;
				if(siz[v]==1){
					fin_ans--;
				}
			}
			printf("%d\n",fin_ans+maxN+1);
		}
	}

	return 0;
}
/*
2
5 2
1 1 2 2
7 2
1 1 2 2 2 3
*/
