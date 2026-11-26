#include<bits/stdc++.h>
using namespace std;
void in(int &x){
	int k=1;
	x=0;
	char c=getchar();
	while (!('0'<=c && c<='9')){
		if (c=='-')
			k=-1;
		c=getchar();
	}
	while (('0'<=c && c<='9')){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	x*=k;
}
int fa[100010];
int siz[100010];
vector <int>son[100010];
int v[100010];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	scanf ("%d",&t);
	while (t--){
		int n,m;
		scanf ("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			son[i].clear();
		for (int i=1;i<=n;++i){
			siz[i]=0;
			v[i]=0;
		}
		for (int i=2;i<=n;++i){
			scanf ("%d",fa+i);
			son[fa[i]].push_back(i);
		}
		if (m==n-1){
			printf("%d\n",(n+1)*n/2);
			continue;
		}
//		if (m<=2){
			if (m==1){
				printf("%d\n",(n+1)*n/2);
				continue;
			}
//		}
		long long ans=1;
		queue<int>qq;
		for (int i=1;i<=n;++i){
			if (son[i].size()!=0){
		//		ans+=son[i].size()+1;	
			}else{
				//if (v[fa[i]]!=1)
			//	ans++;
				v[fa[i]]=1;
				qq.push(fa[i]);
				siz[i]=1;
			}
		}
		while(!qq.empty()){
			int id=qq.front();
			qq.pop();
			siz[id]=1;
			for (int i=0;i<son[id].size();++i){
				siz[id]+=siz[son[id][i]];
			}
			if (v[fa[id]]==0)
				qq.push(fa[id]);
			v[id]=0;
			v[fa[id]]=1;
		}
		for (int i=1;i<=n;++i){
			if (son[i].size()!=0)
				ans+=siz[i];
	//		printf ("[%lld]\n",siz[i]);
		}
		printf ("%lld\n",ans);
	}
	return 0;
}
//!noip@Nov29,2025:dream
