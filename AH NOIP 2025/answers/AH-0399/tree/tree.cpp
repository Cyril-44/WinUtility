#include <bits/stdc++.h>
using namespace std;
struct Edge{
	long long u,v,p;
}e[8005];
long long head[8005],t,n,m,cnt,qx,k[8005],dep[8005];
void AddEdge(int u,int v){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].p=head[u];
	head[u]=cnt;
}
int main(){
	freopen ("tree.in","r",stdin);
	freopen ("tree.out","w",stdout);
	scanf ("%lld",&t);
	while (t--){
		scanf ("%lld%lld",&n,&m);
		for (int i=2;i<=n;i++){
			scanf ("%lld",&qx);
			AddEdge(qx,i);
			k[qx]++;
			dep[i]=dep[qx]+1;
		}
		long long ans=0;
		for (int i=2;i<=n;i++){
			if (dep[i]==m)
				continue;
			else if (dep[i]==(m-1))
				ans+=k[i]*dep[i];
			else
				ans++;
		}
		printf ("%lld",ans);
	}
	return 0;
}
