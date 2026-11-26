#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=8888;
struct Edge{
	int u,v,nxt;
}e[MAXN<<2];
int ec,h[MAXN],T,n,m;
inline void Add(int u,int v)
{
	e[++ec].u=u;
	e[ec].v=v;
	e[ec].nxt=h[u];
	h[u]=ec;
}
struct Node{
	int id,dep,val,siz,son,fa,top,pos;
	#define id(x) dot[x].id
	#define fa(x) dot[x].fa
	#define dep(x) dot[x].dep
	#define siz(x) dot[x].siz
	#define son(x) dot[x].son
	#define top(x) dot[x].top
	#define val(x) dot[x].val
	#define pos(x) dot[x].pos
}dot[MAXN];
inline void dfs1(int x,int f){
	id(x)=x,fa(x)=f,dep(x)=dep(f)+1;
	siz(x)=1,val(x)=dep(x);
	for(int i=h[x];i;i=e[i].nxt){
		if(e[i].v==f)continue;
		dfs1(e[i].v,x);
		siz(x)+=siz(e[i].v);
		if(val(e[i].v)>val(x)||(val(e[i].v)==val(x)&&siz(e[i].v)>siz(son(x))))val(x)=val(e[i].v),son(x)=e[i].v;
	}
}
int val[MAXN],dp[MAXN],lzy[MAXN];
inline void dfs2(int x,int t)
{
	top(x)=t;
	if(!son(x)){
		val[x]=pos(x)=1;
		return;
	}
	dfs2(son(x),t);
	pos(x)=pos(son(x))+1;
	val[x]=pos(x)+val[son(x)];
	for(int i=h[x];i;i=e[i].nxt)if(e[i].v!=fa(x)&&e[i].v!=son(x))dfs2(e[i].v,e[i].v);
}
inline void dfs3(int x){
	if(!son(x))return;
	dfs3(son(x));
	val[x]+=lzy[son(x)];
	lzy[x]+=lzy[son(x)];
	pos(x)=pos(son(x))+1;
	int sum=dep(x)-dep(top(x))+1,tmp=pos(x),mem=0;
	//printf("%d %d\n",x,sum);
	for(int i=h[x];i;i=e[i].nxt)
	{
		if(e[i].v==fa(x)||e[i].v==son(x))continue;
		dfs3(e[i].v);
		int s1=siz(e[i].v)*sum,s2=val[e[i].v];
		if(s1>=s2)pos(x)++;
		val[x]+=max(s1,s2);
		lzy[x]+=max(s1,s2);
	}
}
inline void init()
{
	memset(e,0,sizeof e);
	memset(h,0,sizeof h);
	memset(dp,0,sizeof dp);
	memset(val,0,sizeof val);
	memset(lzy,0,sizeof lzy);
	memset(dot,0,sizeof dot);
	n=m=ec=0;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d %d",&n,&m);
		for(int i=2,f;i<=n;i++)scanf("%d",&f),Add(i,f),Add(f,i);
		dfs1(1,1);dfs2(1,1);dfs3(1);
		//for(int i=1;i<=n;i++)printf("%d ",siz(i));
		printf("%d\n",val[1]);
	}
	return 0;
}
