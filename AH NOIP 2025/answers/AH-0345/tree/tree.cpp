#include<bits/stdc++.h>
using namespace std;
const int N=8005;
int t,n,m;
int fa[N],ans,a[N],f[N];
bool num[N];
vector<int>son[N];
void check(int now){
	num[a[now]]=1;
	int k=son[now].size();
	for(int i=0;i<k;i++){
		check(son[now][i]);
	}
}
int gow(int now){
	if(f[now]!=-1)return f[now];
	int k=son[now].size();
	int sum=0;
	for(int i=0;i<k;i++){
		sum+=gow(son[now][i]);
	}
	memset(num,0,sizeof(num));
	check(now);
	int pp=0;
	for(int i=0;i<n;i++){
		if(!num[i]){
			pp=i;
			break;
		}
	}
	return f[now]=sum+pp;
}
void dfs(int now){
	if(now==n+1){
		ans=max(ans,gow(1));
		return;
	}
	for(int i=0;i<n;i++){
		a[now]=i;
		dfs(now+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			int x;
			scanf("%d",&x);
			fa[i]=x;
			son[x].push_back(i);
		}
		if(m==n-1){
			cout<<(1+n)*n/2<<"\n";
			continue;
		}
		ans=0;
		memset(f,-1,sizeof(f));
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
