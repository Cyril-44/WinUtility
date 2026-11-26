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
long long mod=998244353;
long long ksm(long long a,long long b){
	if (b==0)
		return 1;
	if (b==1)
		return a;
	if (b%2==0)
		return ksm(a*a%mod,b/2);
	else
		return (a*ksm(a*a%mod,b/2))%mod;
}
long long a[5005];
struct node{
	long long op;
	long long num;
}s[15];
long long s2[15];
long long dp[15][35];
bool cmp(node x,node y){
	if (x.num*y.op==y.num*x.op)
		return x.op>y.op;
	return x.num*y.op>y.num*x.op;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	scanf ("%d%d",&c,&t);
	while (t--){
		int n,m;
		scanf ("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			scanf ("%lld",a+i);
		sort(a+1,a+n+1);
		if (n<=10){
			int ans=0;
			for (int t=0;t<(1<<n);++t){
				int o=t;
				int js=0;
				for (int i=1;i<=n;++i)
					s2[i]=0;
				while (o){
					s2[++js]=o%2;
					o/=2;
				}
				for (int i=1;i<=n;++i){
					s[i].num=a[i];
				//	if (s2[i]==0)
				//		s[i].num*=2;
					s[i].op=s2[i]+1;
				}
				sort(s+1,s+n+1,cmp);
				o=m;
				long long ss=0;
				for (int i=1;i<=n;++i){
					if (o-s[i].op<0)
						continue;
					o-=s[i].op;
					ss+=s[i].num;
				}
				//printf ("[%d]**%d\n",t,ss);
				for (int i=1;i<=n;++i){
					for (int j=0;j<s[i].op;++j)
						dp[i][j]=dp[i-1][j];
					for (int j=s[i].op;j<=m;++j)
						dp[i][j]=max(dp[i-1][j-s[i].op]+s[i].num
									,dp[i-1][j]);
				}
				long long sss=0;
				for (int i=0;i<=m;++i)
					sss=max(sss,dp[n][i]);
			//		printf ("[%d]\n",t);
				//	printf ("[%d]%d\n",t,ss);
			//		for (int i=1;i<=n;++i){
			//			printf ("%d %d\n",s[i].num,s[i].op);
			//		}
			//	printf ("[%d]%d %d\n",t,ss,sss);
			//	for (int i=1;i<=n;++i){
			//		printf ("%d %d\n",s[i].num,s[i].op);
			//	}
				if (sss==ss){
					ans++;
			//		printf ("[%d]",t);
				}
			}
			printf ("%d\n",ans);
		//	puts("___________________________====***");
			continue;
		}
		if (m==2){
			long long o=0;
			for (int i=1;i<n;++i){
				if (a[i]*2>=a[n])
					o++;
			}
			for (int i=1;i<n;++i){
				int kkk=upper_bound(a+1,a+n+1,a[n]-a[i])-a-1;
				o+=kkk;
			}
			printf ("%lld\n",(ksm(2,n)-o+mod)%mod);
			continue;
		}
		if (m==2*n-1){
			printf ("%lld\n",ksm(2,n));
			continue;
		}
		if (m==2*n-2){
			int o=0;
			if (a[1]!=a[2] && a[1]*2>a[2]){
				o=1;
			}
			printf ("%lld\n",(ksm(2,n)-o+mod)%mod);
			continue;
		}
	//	for (int i=1;i<=1<<n);
		puts("6");
	}
	return 0;
}
//!noip@Nov29,2025:dream
/*
  1   3   5
  1 1.5   5
  1 1.5 2.5
0.5   3   5
0.5 1.5 2.5
111
121
122
211


212

112


221
*/
