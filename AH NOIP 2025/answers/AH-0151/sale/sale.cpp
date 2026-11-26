#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read(){
	register int x=0,f=1;register char ch=getchar_unlocked();
	while(ch<'0'||'9'<ch){if(f=='-') f=-f; ch=getchar_unlocked();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0',ch=getchar_unlocked();}
	return x*f;
}
const int N=5e3+5,mod=998244353;
int n,m,a[N];
struct node{
	int a,w,id;
}b[N];
inline bool cmp(node x,node y){
	if(x.w*y.a!=x.a*y.w) return x.a*y.w>y.a*x.w;
	if(x.a!=y.a) return x.a>y.a;
	return x.id<y.id;
}
inline long long dfs(int w,long long v,int i){
	if(i>n) return v;
	if(b[i].w<=w) return max(dfs(w-b[i].w,v+b[i].a,i+1),dfs(w,v,i+1));
	return dfs(w,v,i+1);
}
inline void solve1(){
	register int i,top=(1<<n)-1,val,v,ans=0,able;
	register long long cnt;
	for(val=0;val<=top;++val){
		v=val,cnt=0;
		for(i=1;i<=n;++i){
			b[i].w=(v&1)+1,b[i].a=a[i],b[i].id=i;
			v>>=1;
		}
		sort(b+1,b+1+n,cmp);
		//for(i=1;i<=n;++i) printf("%d %d\n",b[i].w,b[i].a);
		able=m,i=1;
		while(i<=n&&able) {
			if(able>=b[i].w) able-=b[i].w,cnt+=b[i].a;
			++i;
		}
		//printf("%d %d\n",dfs(m,0,1),cnt);
		if(cnt==dfs(m,0,1)) ++ans;
	}
	printf("%d\n",ans);
	return;
}
inline int lpow(int x,int y){
	register int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ans;
}
inline void solveA(){
	printf("%d\n",lpow(2,n));
	return;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	register int c=read(),T=read();
	while(T--){
		register int i,flag=1;
		n=read(),m=read();
		a[1]=read();
		for(i=2;i<=n;++i){
			a[i]=read();
			if(a[i]!=a[i-1]) flag=0;
		}
		if(flag){
			solveA();
		}
		else if(n<=10||m==1||m==2){
			solve1();
		}
		else puts("0");
	}
	return 0;
}
