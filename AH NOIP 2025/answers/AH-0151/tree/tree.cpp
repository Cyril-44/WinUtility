#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0,f=1;register char ch=getchar_unlocked();
	while(ch<'0'||'9'<ch){if(f=='-') f=-f; ch=getchar_unlocked();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0',ch=getchar_unlocked();}
	return x*f;
}
const int N=8e3+5;
struct node{
	int u,v,nxt;
}e[N];
int head[N],tot,fa[N],d[N],son[N],mxson[N],val[N],n,ans;
inline void add(int u,int v){
	e[++tot]=(node){u,v,head[u]};
	head[u]=tot;
}
inline void dfs(int x,int dep){
	register int i,v=n+1;
	for(i=head[x];i;i=e[i].nxt){
		v=e[i].v;
		dfs(v,dep);
	}
	d[x]=d[v]+1;
	return;
}
bitset<N>vis[N];
bool vist[N];
inline int mex(int x){
	register int i=0;
	while(vis[x][i]) ++i;
	return i;	
}
inline void work(int x){
	if(vist[x]) return;
	register int i,v=-1;
	for(i=head[x];i;i=e[i].nxt){
		v=e[i].v;
		work(v);
	}
	//printf("work!%d\n",x);
	vis[x][val[x]]=1,vist[x]=1;
	vis[fa[x]]|=vis[x];
	ans+=mex(x);
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	register int T=read();
	while(T--){
		memset(mxson,0,sizeof mxson);
		memset(son,0,sizeof son);
		n=read();
		register int dmx=read(),i,j;
		ans=0;
		fa[1]=0;
		for(i=2;i<=n;++i){
			fa[i]=read();
			add(fa[i],i);
		}
		d[n+1]=-1;
		dfs(1,dmx);
		for(j=1;j<=n;++j){
			if(d[j]) continue;
			val[j]=son[fa[j]],++son[fa[j]];
		}
		for(i=0;i<=dmx;++i){
			for(j=1;j<=n;++j){
				if(d[j]^i) continue;
				val[fa[j]]=max(val[fa[j]],val[j]+1);
			}
		}
		//for(i=1;i<=n;++i) printf("%d %d %d %d %d\n",val[i],d[i],fa[i],son[i],mxson[i]);
		//puts("");
		memset(vis,0,sizeof vis);
		memset(vist,0,sizeof vist);
		work(1);
		printf("%d\n",ans);
	}
	return 0;
}
