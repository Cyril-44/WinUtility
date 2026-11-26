#include<bits/stdc++.h>
#define up(i,l,r) for(int i=l,END##i=r;i<=END##i;i++)
#define dn(i,l,r) for(int i=l,END##i=r;i>=END##i;i--)
#define ve vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define fi first
#define se second
#define great greater<int>
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
using namespace std;
const int INF=0x3f3f3f3f,N=8e3+7;
struct e{
	int nxt,to;
}a[N<<1];
int head[N],tot;
void add(int x,int y){
	a[++tot].to=y,a[tot].nxt=head[x],head[x]=tot;
}
i64 n,ans,w[N],fa[N],m,dp[N];
bool f[N];
i64 ask(int x){
	f[w[x]]=1;
	for(int i=head[x],to;i;i=a[i].nxt) if((to=a[i].to)!=fa[x]) ask(to);
	up(i,0,n+5) if(!f[i]) return i;
	return 0;
}
bool u=0;
void dfs(int x){
	if(x==n+1){
		i64 s=0;
		up(i,1,n) {
			up(j,0,n+1) f[j]=0;
			s+=ask(i);
		}
		//if(s==25&&!u) up(i,1,n) cout<<w[i]<<' '<<ask(i)<<'\n',u=1;
		ans=max(ans,s);
		return;
	}
	up(i,0,n) w[x]=i,dfs(x+1);
}
void dfss(int x){
	bool u=0;
	i64 mx=0;
	for(int i=head[x],to;i;i=a[i].nxt) dfss(to=a[i].to),dp[x]+=dp[to],mx=max(mx,dp[to]),u=1;
	if(u)dp[x]+=mx;
	else dp[x]=1;
}
namespace sol{
	i64 read(){
		i64 f=0,x=0;
		char c=getchar();
		while(c<'0'||c>'9') f|=c=='-',c=getchar();
		while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return f?-x:x;
	}
	void write(i64 x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	void Dianaqwq(){
		memset(a,0,sizeof a),memset(head,0,sizeof head),tot=0,memset(dp,0,sizeof dp);
		n=read(),m=read();
		up(i,2,n) fa[i]=read(),add(fa[i],i);
		if(n<=7){dfs(1);
		write(ans);return;}
		dfss(1);
		write(dp[1]);
	}
}
using namespace sol;
signed main(){
	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T=read();while(T--) Dianaqwq(),puts("");
	return 0;
}
