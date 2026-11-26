#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long a[5001],w[5001];
long long fac[5001],invfac[5001];
long long qzh1[5001],qzh2[5001],s1,s2;
struct aw{
	long long aa,ww;
}s[5001];
bool cmp(aw x,aw y){
	if(x.aa*2/x.ww>y.aa*2/y.ww)return true;
	if(x.aa*2/x.ww<y.aa*2/y.ww)return false;
	if(x.aa>y.aa)return true;
	return false;
}
long long ksm(long long a,long long b){
	if(!b)return 1;
	long long ret=ksm(a,b>>1);
	ret=ret*ret%mod;
	if(b&1)ret=ret*a%mod;
	return ret;
}
void work(int c){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	if((10<=c&&c<=12)||c==19||c==20){
		long long ans=1;
		for(int i=1;i<=n;i++)(ans*=2)%=mod;
		for(int k=0;k<=n;k++){
			if(m+k+1<2*k)continue;
			if(k+m+1>2*n)break;
			if((k+m)%2==0)continue;
			ans=(ans-fac[(m+k+1)/2]*invfac[k]%mod*invfac[(m-k+1)/2]%mod+mod)%mod;
		}
		printf("%lld\n",ans);
	}
	else if(c<=5){
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				if(i&(1<<j-1))w[j]=1;
				else w[j]=2;
				s[j].aa=a[j],s[j].ww=w[j];
			}
			sort(s+1,s+n+1,cmp);
			long long sum1=0,now=m,sum2=0;
			for(int j=1;j<=n;j++)if(now>=s[j].ww)now-=s[j].ww,sum1+=s[j].aa;
			s1=s2=0;
			for(int j=1;j<=n;j++)if(w[j]==1){
				s1++;
				qzh1[s1]=qzh1[s1-1]+a[j];
			}else{
				s2++;
				qzh2[s2]=qzh2[s2-1]+a[j];
			}
			for(int j=(s1+m+1)/2;j*2<=m&&j<=s2;j++)sum2=max(sum2,qzh2[j]+qzh1[m-2*j]);
			if(sum1==sum2)ans++;
		}
		printf("%d\n",ans);
	}
	else if(c==16||c==18){
		long long ans=1;
		for(int i=1;i<=n;i++)(ans*=2)%=mod;
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	fac[0]=1;
	for(int i=1;i<=5000;i++)fac[i]=fac[i-1]*i%mod;
	invfac[5000]=ksm(fac[5000],mod-2);
	for(int i=4999;i>=0;i--)invfac[i]=invfac[i+1]*(i+1)%mod;
	scanf("%d%d",&c,&t);
	while(t--)work(c);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
