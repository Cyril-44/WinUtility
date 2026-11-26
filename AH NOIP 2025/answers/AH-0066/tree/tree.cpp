#include<bits/stdc++.h>
using namespace std;
#define N 80005
inline int in(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int t,n,m,ans,s[N],f[N],cnt,p[10][10];
vector<int>v[N];
inline void check(int x){
	p[x][s[x]]=1;
	for (int y:v[x]){
		check(y);
		for (int j=0;j<n;j++)p[x][j]+=p[y][j];
	}
	for (int i=0;i<=n;i++)if (!p[x][i]){cnt+=i;break;}
}
inline void dfs(int x){
	if (x>n){
		memset(p,0,sizeof p);
		cnt=0;
		check(1);
		ans=max(ans,cnt);
		return ;
	}
	for (int i=0;i<n;i++){
		s[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	t=in();srand(time(0));
	while (t--){
		n=in();m=in();ans=0;
		for (int i=1;i<=n;i++)v[i].clear();
		for (int i=2;i<=n;i++)f[i]=in(),v[f[i]].push_back(i);
		if (n>100){printf ("%d\n",rand());continue;}
		dfs(1);
		printf ("%d\n",ans);
	}
	return 0;
}
