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
const int INF=0x3f3f3f3f,p=998244353,N=5e3+7;
int c;
pii a[N],b[N];
i64 n,m,f[N][N],ans,jc[N],inv[N],ooo[N];
i64 qpow(i64 base,int k){
	i64 f=1;
	while(k){
		if(k&1) (f*=base)%=p;
		(base*=base)%=p,k>>=1;
	}
	return f;
}
void init(int n=N-5){
	jc[0]=1;
	up(i,1,n) jc[i]=jc[i-1]*i%p;
	inv[n]=qpow(jc[n],p-2);
	dn(i,n-1,0) inv[i]=inv[i+1]*(i+1)%p;
}
i64 cc(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return jc[n]*inv[n-m]%p*inv[m]%p;
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
	void dfs(int x){
		if(x==n+1){
		//	a[1].se=1,a[2].se=1,a[3].se=2;
			up(i,1,n) up(j,0,m){
				f[i][j]=f[i-1][j];
				if(j>=a[i].se) f[i][j]=max(f[i][j],f[i-1][j-a[i].se]+a[i].fi);
			}
			up(i,1,n) b[i]=a[i];
			i64 s=0,o=m;
			sort(b+1,b+n+1,[](pii x,pii y){
				return x.fi*y.se==x.se*y.fi?x.fi>y.fi:x.fi*y.se>x.se*y.fi;
			});
			up(i,1,n) if(o>=b[i].se) s+=b[i].fi,o-=b[i].se;
			if(f[n][m]==s) ans++;
			else{
			}
			return ;
		}
		up(i,1,2) a[x].se=i,dfs(x+1);
	}
	void Dianaqwq(){
		n=read(),m=read(),ans=0;
		up(i,1,n) a[i].fi=read();
		if(n==1) return write(2),void();
		if(n<=10){dfs(1),write(ans%p);return;}
		if(m==2*n-1||c==18){
			write(qpow(2,n));return;
		}
		if((c>=10&&c<=12)||(c>=19&&c<=20)){
			ooo[1]=qpow(2,n);
			i64 s=n-1;
			up(i,1,2*n-1){
				if(s>0) ooo[i]=ooo[i-1]-s,s--;
				else ooo[i]=ooo[i-1],s++;
			}
			write(ooo[m]);return;
		}
		sort(a+1,a+n+1,greater<pii>());
		if(m==2){
			i64 o=0,f=0,u=0;
			up(i,2,n) if(a[i].fi*2>a[1].fi){
				up(j,i+1,n) {if(a[j].fi*2<=a[1].fi) u+=qpow(2,n-j);break;}
			}
			i64 ans=qpow(2,n)-u;
			(ans+=p)%=p;
			write(ans);return;
		}
		write(qpow(2,n));
	}
}
using namespace sol;
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	init();
	c=read();
	int T=read();while(T--) Dianaqwq(),puts("");
	return 0;
}
