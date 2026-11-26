#include<bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=(j);i<=(k);i++)
typedef long long LL;
const int M=20010;
const LL mod=998244353;
int c,T,n,m;
LL a[M],jc[M],jc_inv[M],ans;
pair<LL,LL> f[M];
//~ #define int long long
LL power(LL a,LL b){
	LL ans=1;
	for(;b;b>>=1){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
inline int read(){
	int ans=0,f=1;
	char c=getchar_unlocked();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>=48&&c<=57){
		ans=ans*10+c-48;
		c=getchar_unlocked();
	}
	return ans*f;
}
LL C(int x,int y){
	if(y<0||y>x||x<0) return 0;
	return jc[x]*jc_inv[y]%mod*jc_inv[x-y]%mod;
}
void check(pair<LL,LL> t[]){
	For(i,1,n){
		if(t[i].second==1) t[i].first*=2ll;
	}
	sort(t+1,t+1+n);reverse(t+1,t+1+n);
	int las=0,las2=0,cnt=0;
	int i=1;
	while(i<=n&&cnt!=m){
		if(cnt+t[i].second<=m) cnt+=t[i].second;
		else las2=i;
		if(cnt==m) break;
		if(t[i].second==1) las=i;
		i++;
	}
	if(t[i].first+t[las].first<t[las2].first*2) ans++;
}
void dfs(int k){
	if(k==n+1) {check(f);return ;}
	dfs(k+1);
	f[k].second=2;
	dfs(k+1);
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	jc[0]=1;
	For(i,1,M-1) jc[i]=jc[i-1]*i%mod;
	jc_inv[M-1]=power(jc[M-1],mod-2);
	for(int i=M-1;i>=1;i--) jc_inv[i-1]=jc_inv[i]*i%mod;
	
	c=read(),T=read();
	while(T--){
		n=read(),m=read();
		For(i,1,n) a[i]=read();
		if(c==18||c==16){
			printf("%lld\n",power(2,n));
			continue;
		}
		sort(a+1,a+1+n);reverse(a+1,a+1+n);
		if((c>=10&&c<=12)||c==19||c==20){
			LL dis=0;
			for(int i=(m&1)^1;i<n;i+=2){
				if(2*n-i<=m||i>=m) break;
				for(int j=i+1+(m-i)/2;j<=n;j++){
					dis=(dis+C(j-1,i-1))%mod;
				}
			}
			printf("%lld\n",(power(2,n)-dis+mod)%mod);
		}
		For(i,1,n) f[i].second=1,f[i].first=a[i];
		ans=0;dfs(1);printf("%lld\n",(power(2,n)-ans+mod)%mod);
 	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
