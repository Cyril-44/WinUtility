//long long  freopen 多测
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10010,mod=998244353;
int c,T;
int n,m,a[N],w[N],p[N],dp[N];
int DP(){
	memset(dp,0xcf,sizeof(dp));dp[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+a[i]);
	return *max_element(dp,dp+1+m);
}
bool cmp(int x,int y){
	if(a[x]*w[y]==a[y]*w[x]) return a[x]>a[y];
	return a[x]*w[y]>a[y]*w[x];
}int greedy(){
	sort(p+1,p+1+n,cmp);
	int tot=m,ans=0;
	for(int i=1;i<=n;i++){
		if(tot>=w[p[i]]){
			tot-=w[p[i]];ans+=a[p[i]];
		} 
	}
	return ans;
}
void solve1(){
	int ans=0;
	for(int msk=0;msk<(1<<n);msk++){
		for(int i=1;i<=n;i++) w[i]=(msk>>(i-1))&1,w[i]++,p[i]=i;
		//for(int i=1;i<=n;i++) cout<<w[i]<<' '<<a[i]<<'\n';
		int d=DP();int g=greedy();
		//if(d!=g){cout<<d<<' '<<g<<'\n';for(int i=1;i<=n;i++) cout<<w[i]<<' '<<a[i]<<'\n';}
		//cout<<d<<' '<<g<<' ';
		ans+=d==g;
	}
	cout<<ans<<'\n';
	return;
}
// 钦定ij
int f[N],pw[N];

void solve2(){
	sort(a+1,a+1+n);
	int ans=0;
	for(int j=2;j<=n;j++){
		for(int i=1;i<=j-1;i++){
			int cnt=0;
			if(2*a[i]<=a[j]) continue;
			memset(f,0,sizeof(f));
			f[n-j]=1;
			for(int k=j+1;k<=n;k++){
				for(int use=m;use>=1;use--){
					f[use]+=f[use-1];
					f[use]+=f[use-2];
				}
			}
			(cnt+=f[m-2])%=mod;
			for(int k=1;k<=i-1;k++){
				if(a[k]+a[i]>=a[j]) continue;
				(cnt+=(pw[k-1])*f[m-2])%=mod;
			}
			//for(int i=0;i<=m;i++) cout<<f[i]<<' ';cout<<'\n';
			//cout<<i<<' '<<j<<' '<<cnt<<'\n';
			(ans+=cnt)%=mod;
		}
	}
	cout<<(mod*10+pw[n]-ans)%mod<<'\n';
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	pw[0]=1;
	for(int i=1;i<=5000;i++) pw[i]=pw[i-1]*2%mod;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		if(c<=5){solve1();continue;}
		else if(c<=15){solve2();continue;}
		else if(c==16||c==18){cout<<pw[n]<<'\n';continue;}
	}
	return 0;
}

