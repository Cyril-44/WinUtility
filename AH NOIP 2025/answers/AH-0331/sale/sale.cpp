#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[100005];
int w[100005];
int bin[10005];
int debugw[1005];
struct df{
	long long a,w,sz;
}p[105];
int pp;
int n,m;
bool dfcmp(df a,df b){
	if(a.a*b.w==b.a*a.w){
		return a.a>b.a;
	}
	return a.a*b.w>b.a*a.w;
}
int dfans;
long long dp[105];
void check(){
	pp=0;
	for(int i=1;i<=n;i++){
		p[++pp].a=a[i];
		p[pp].w=w[i];
		p[pp].sz=0;
	}
	sort(p+1,p+n+1,dfcmp);
	int cnt=m;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(cnt>=p[i].w){
			p[i].sz=1;
			cnt-=p[i].w;
			sum+=p[i].a;
		}
	}
	for(int i=1;i<=m;i++)dp[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=p[i].w;j--){
			dp[j]=max(dp[j],dp[j-p[i].w]+p[i].a);
		}
	}
//	for(int i=1;i<=m;i++)cout<<dp[i]<<" ";
//	cout<<"\n";
	if(dp[m]!=sum){
		for(int i=1;i<=n;i++){
			cout<<w[i]<<" ";
		}
		cout<<"\n";
		cout<<dp[m]<<" "<<sum<<endl;
	}
	dfans+=(dp[m]==sum);
}
void dfs(int step){
	if(step==n+1){
		check();
		return;
	}
	dfs(step+1);
	w[step]=2;
	dfs(step+1);
	w[step]=1;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	bin[0]=1;
	for(int i=1;i<=10000;i++)bin[i]=(bin[i-1]<<1)%mod;
	while(t--){
		
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		if(c<=5){
			dfans=0;
			for(int i=1;i<=n;i++)w[i]=1;
			dfs(1);
			cout<<dfans<<"\n";
		}
		else if(7<=c&&c<=9||c==14||c==15){
		//	for(int i=1;i<=n;i++){
		//		cout<<i<<" "<<a[i]<<"\n"; 
		//	}
		//	cout<<"\n";
			int cant=0;
			for(int i=2;i<=n-1;i++){
				if(a[i]*2<=a[n])continue;
				long long st=lower_bound(a+1,a+n+1,a[n]-a[i])-a-1;
				//cout<<i<<" "<<bin[st]<<endl;
				st=min(st,lower_bound(a+1,a+n+1,(a[n]+1)/2)-a-1ll);
				//cout<<st<<"||";
				if(st>=0){
					cant+=(bin[st]);
					cant%=mod;
				}
			}
			//cout<<ans<<" "<<cant<<endl;
			//dfans=0;
			//for(int i=1;i<=n;i++)w[i]=1;
			//dfs(1);
			//for(int i=1;i<=n;i++){
			//	if(debugw[i]!=0)cout<<i<<" "<<debugw[i]<<"\n";
			//}
			cout<<(bin[n]+mod-cant)%mod<<"\n";
		}
		else if(c==16||c==18){
			cout<<bin[n]<<"\n";
		}
		else if(c==17){
			int cant=0;
			//cout<<a[1]<<" "<<a[2]<<" "<<bin[n]<<endl;
			if(a[1]*2>a[2]&&a[1]!=a[2])cant++;
			cout<<(bin[n]+mod-cant)%mod<<"\n";
		}
		else if(10<=c&&c<=12||c==19||c==20){
			//int maxn=0;
			//for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
			if(m%2==0){
				int cant=0;
				for(int i=1;i<n;i++){
					if(a[i]==a[n])break;
					if(i==1)cant++;
					else cant+=bin[i-1]/2;
					cant%=mod;
				}
				cout<<(bin[n]+mod-cant)%mod<<"\n";
			}
			
			dfans=0;
			for(int i=1;i<=n;i++)w[i]=1;
			dfs(1);
			cout<<dfans<<endl;
		}
	}
	return 0;
}
/*
0 1
3 2
1 3 5

a1+a2<an
a1>an/2
a2<an/2



10 1
20 8
721057517 616261611 616261611 736926413 953834152 727940616 531390528 964368751 736926413 531390528 994832069 990877960 760931295 758826265 721057517 523305625 544138600 703579524 806413846 506470280



10 1
5 6
9 9 9 10 10



*/
