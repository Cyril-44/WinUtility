#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,fa[10005],deep[10005],son[10005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&t);
    while(t--){
		memset(fa,0,sizeof(fa));
		memset(deep,0,sizeof(deep));
		memset(son,0,sizeof(son));
		scanf("%d%d",&n,&m);deep[1]=0;
		for(int i=2;i<=n;i++){
			scanf("%d",&fa[i]);
			son[fa[i]]++;
		}
		for(int i=2;i<=n;i++)
			deep[i]=deep[fa[i]]+1;
		int ans=0,mx=0;
		if(m==2){
			for(int i=1;i<=n;i++)
				if(deep[i]==1&&son[i]!=0){
					ans+=2+son[i];
					mx=max(mx,son[i]+2);
				}
				else if(deep[i]==1)
					ans+=1;
			ans+=mx;
			printf("%d\n",ans);
			continue;
		}
		for(int op=m;op>=0;op--){
			for(int i=1;i<=n;i++)
				if(deep[i]==op){
					ans+=son[i];
					son[fa[i]]+=son[i];
				}	
		}
		printf("%d\n",ans);
	}
    return 0;
}
/*!noip@Nov29,2025:dream*/
