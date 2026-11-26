#include<bits/stdc++.h>
using namespace std;
int fa[8005],u[8005];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t,n,m,x,s,kk;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(m==2){
			x=0;
			s=0;
			kk=0;
			memset(u,0,sizeof(u));
			fa[1]=-1;
			for(int i=2;i<=n;i++){
				scanf("%d",&fa[i]);
				x=x+(fa[i]==1);
				u[fa[i]]++;
			}
			for(int i=2;i<=n;i++){
				if(fa[i]==1&&u[i]){
					s++;
					kk=max(kk,u[i]);
				}
			}
			if(n-1-x==s){
				printf("%lld\n",1ll*(3+s*2+(n-1-s)));
			}else{
				printf("%lld\n",1ll*(kk+2+kk+1+1+(s-1)*2+n-1-s-kk));
			}
		}
	}
	return 0;
}
