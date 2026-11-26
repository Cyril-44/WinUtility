#include<bits/stdc++.h>
using namespace std;
#define N 8005
int T,f[N],a[N],b[N][N],n,d,ans;
int che(){
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			b[i][j]=0;
	for(int i=1;i<=n;i++)
		b[i][a[i]]=1;
	for(int i=0;i<n;i++)
		for(int j=1;j<=n;j++)
			for(int p=0;p<n;p++)
				if(b[j][p]==1)
					b[f[j]][p]=1;
	int x=0;
	for(int i=1;i<=n;i++){
		int p=0;
		while(b[i][p]==1)
			p++;
		x+=p;
	}
	return x;
}
void dfs(int x){
	if(x>n){
		ans=max(ans,che());
		return;
	}
	for(int i=0;i<n;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>d;
		for(int i=2;i<=n;i++)
			cin>>f[i];
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
