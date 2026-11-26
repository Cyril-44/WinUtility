#include<bits/stdc++.h>
using namespace std;
#define __MY_TEST__ 1
#define int long long
inline int read()
{
	int re=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while( isdigit(ch)) re=(re<<3)+(re<<1)+(ch^48),ch=getchar();
	return re*f;
}
const int mod=998244353;
int n,m;
int C[5005][5005],a[5005];
int ksm(int a,int b)
{
	int k=1;
	while(b)
	{
		if(b&1) k*=a,k%=mod;
		a*=a,a%=mod;
		b/=2;
	}
	return k;
}
namespace SOL
{

void work()
{
	if(m>=n)
	{
		int ans=1;
		for(int i=n;i>=n+n-m;i--) ans=(ans+C[n][i])%mod;
		for(int i=n+n-m-1;i>0;i--)
		{
			if(m%2==i%2)
			{
				ans=(ans+C[n][i])%mod;
				continue;
			}
			int s1=i,s2=(m-i)/2;
			int val=a[n-s1-s2+1],cv=0,gv=0;
			for(int j=1;j<=n;j++) if(a[j]==val) cv++;
			for(int j=1;j<=n;j++) if(a[j]>val) gv++;
			for(int i=max(0ll,s1-gv);i<=min(s1-(gv-s2),min(cv,s1));i++) ans=(ans+C[cv][i]*C[gv][s1-i])%mod;
		}
		cout<<ans<<endl;
		return ;
	}
	int ans=1;
	for(int i=m-1;i>0;i--)
	{
		if(m%2==i%2)
		{
			ans=(ans+C[n][i])%mod;
			continue;
		}
		int s1=i,s2=(m-i)/2;
		int val=a[n-s1-s2+1],cv=0,gv=0;
		for(int j=1;j<=n;j++) if(a[j]==val) cv++;
		for(int j=1;j<=n;j++) if(a[j]>val) gv++;
		for(int i=max(0ll,s1-gv);i<=min(s1-(gv-s2),min(cv,s1));i++) ans=(ans+C[cv][i]*C[gv][s1-i])%mod;
	}
	for(int i=n;i>=m;i--) ans=(ans+C[n][i])%mod;
	cout<<ans<<endl;
}	

}
namespace SOL2
{

void work()
{
	int ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		vector<int>v1,v2;
		for(int j=1;j<=n;j++) if(i&(1<<(j-1))) v1.push_back(a[j]); else v2.push_back(a[j]);
		reverse(v1.begin(),v1.end());
		reverse(v2.begin(),v2.end());
		int maxn=0,sum=0;
		for(int i=0;i<v1.size();i++)
		{
			sum+=v1[i];
			int tmp=sum;
			for(int j=0;j<v2.size()&&2*(j+1)+i+1<=m;j++) tmp+=v2[j];
			if(i+1<=m) maxn=max(maxn,tmp);
		}
		int re=m,tot=0;
		int p1=0,p2=0;
		while(p1<v1.size()&&p2<v2.size()&&re)
		{
			if(p1<v1.size()&&(v1[p1]*2>=v2[p2]||re==1)) re--,tot+=v1[p1++];
			else if(re>=2) re-=2,tot+=v2[p2++];
		}
		if(tot==maxn) ans++;
	}
	cout<<ans<<'\n';
}

}
void work()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	if(a[n]<=a[1]*2)
	{
		SOL::work();
		return ;
	}
	else
	{
		SOL2::work();
		return ;
	}
}
signed main(){
#if __MY_TEST__
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(int i=0,j;i<=5000;i++) for(j=C[i][0]=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	read();int t=read();
	while(t--) work();
}

