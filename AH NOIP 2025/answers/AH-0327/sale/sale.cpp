#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int C,T;
int n,m;
int a[5005];
struct node{
	int a,w;
}z[20];
bool cmp1(node a,node b){
	return a.a*b.w>b.a*a.w;
}
int qpow(int a,int b){
	if(b==0) return 1;
	int x=qpow(a,b>>1);
	if(b&1) return x*x%mod*a%mod;
	else return x*x%mod;
}
int jc[5005],rjc[5005];
int Ca(int a,int b){
	return jc[a]*rjc[b]%mod*rjc[a-b]%mod;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>C>>T;
	jc[0]=rjc[0]=1;
	for(int i=1;i<=5000;i++){
		jc[i]=jc[i-1]*i%mod;
		rjc[i]=qpow(jc[i],mod-2);
	}
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1,greater<int>());
		if(C<=5){
			int ans=0;
			for(int k=2;k<=(1<<n+1);k+=2){
				for(int i=1;i<=n;i++)
					z[i]={a[i],((k>>i)&1)+1};
				sort(z+1,z+n+1,cmp1);
				int s1=0,s2=0,M=m;
				for(int i=1;i<=n;i++)
					if(M>=z[i].w) M-=z[i].w,s1+=z[i].a;
				int f[20];
				memset(f,0,sizeof(f));
				for(int i=1;i<=n;i++)
					for(int j=m;j>=z[i].w;j--)
						f[j]=max(f[j],f[j-z[i].w]+z[i].a);
				//cerr<<s1<<' '<<f[m]<<'\n';
				if(f[m]==s1) ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
		else if(m==2*n-1||C==18){
			cout<<qpow(2,n)<<'\n';
			continue;
		}
		else if(m==2*n-2){
			//int N=unique(a+1,a+n+1)-a-1;
			//cerr<<a[N]<<' '<<a[N-1]<<'\n';
			if(a[n]!=a[n-1]&&a[n]*2>a[n-1]) cout<<(qpow(2,n)-1+mod)%mod;
			else cout<<qpow(2,n);
			cout<<'\n';
			continue;
		}
		else if(C==10||C==11||C==12||C==19||C==20){
			int s=qpow(2,n);
			int l[5005];
			l[1]=0;
			for(int i=2;i<=n;i++) if(a[i]==a[i-1]) l[i]=l[i-1];else l[i]=i-1;
			for(int i=1;i<=n;i++){
				if(i>=m) break;
				if(i&1==0) continue;
				int b=(m-i)/2;
				for(int j=b+i;j<=n;j++){
					if(i-(j-l[j])<0) continue;
					s=(s-Ca(l[j],i-(j-l[j]))+mod)%mod;
				}
			}
			cout<<s<<'\n';
			continue;
		}
	}
	return 0;
}
