#include<bits/stdc++.h>
using namespace std;
int d[1009],f[1009],s[1009][1009];  
int dfs(int x){
	if(d[x]!=0)  return d[x];
	else  return d[x]=dfs(f[x])+1;
}
void sfd(int x){
	if(x==1)  return;
	else s[f[x]][x]++,sfd(f[x]);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int ttt,m,n;
	scanf("%d",&ttt);
	for(int ggg=0;ggg<ttt;ggg++){
		long long ans1=0,ans2=0,ans;  int mx;
		scanf("%d%d",&n,&m);  memset(d,0,sizeof d);
		for(int i=2;i<=n;i++)  scanf("%d",&f[i]);
		d[1]=1;  for(int i=2;i<=n;i++)  d[i]=dfs(i);
		for(int i=1;i<=n;i++)  sfd(i);
		for(int i=1;i<=n;i++){
			mx=s[i][1];
			for(int j=2;j<=n;j++)  mx=max(mx,s[i][j]);
			ans1+=mx;
		}  for(int i=1;i<=n;i++)  ans2+=d[i];
		if(ans1>ans2)  ans=ans1;
		else  ans=ans2;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
