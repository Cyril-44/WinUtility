#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+5,Mod=998242353;
int c,t,f[N];
struct node{
	int w,a,id;
	double k;
}pyrf[N];
bool cmp(node x,node y){
	if(x.k==y.k&&x.a==y.a)
		return x.id<y.id;
	if(x.k==y.k)
		return x.a>y.a;
	return x.k>y.k;
}
bool cmp2(node x,node y){
	return x.id<y.id;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>pyrf[i].a;
	for(int i=1;i<=n;i++)
		pyrf[i].id=i;
	if(n<=40){
		int ans=0;
		for(int mask=0;mask<(1LL<<n);mask++){
			//cout<<mask<<" ";
			for(int i=1;i<=n;i++)
				pyrf[i].w=1;
			int cnt=0,x=mask;
			while(x>0){
				pyrf[++cnt].w=x%2+1;
				x/=2;
			}
			int sum=0;
			for(int i=1;i<=n;i++)
				sum+=pyrf[i].w;
			if(sum<=m){
				ans++;
				break;
			}
			for(int i=1;i<=n;i++)
				pyrf[i].k=pyrf[i].a*1.0/pyrf[i].w*1.0;
			sort(pyrf+1,pyrf+n+1,cmp);
			int p1=0,p2=0;
			x=m;
			for(int i=1;i<=n;i++){
				if(x>=pyrf[i].w){
					p1+=pyrf[i].a;
					x-=pyrf[i].w;
				}
			}
			for(int i=0;i<=m;i++)
				f[i]=0;
			for(int i=1;i<=n;i++){
				for(int j=m;j>=pyrf[i].w;j--)
					f[j]=max(f[j],f[j-pyrf[i].w]+pyrf[i].a);
			}
			p2=f[m];
			if(p1==p2)
				ans++;
			sort(pyrf+1,pyrf+n+1,cmp2);
			ans%=Mod;
		}
		cout<<ans;
		return ;
	}
	//10:24 预估得分 20
	int kkk=0;
	for(int i=1;i<n;i++)
		if(pyrf[i].a!=pyrf[i+1].a)
			kkk=1;
	if(m==n*2-1||kkk==0){
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*2%Mod;
		cout<<ans;
		return ;
	}
	//10：36 好像被卡常了，只有8+8+x=16+x分
	//我赌CCF机子速度比hfyz快！
	if(m==n*2-2){
		for(int i=1;i<=n;i++)
			pyrf[i].w=2;
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*2%Mod;
		ans=(ans-1+Mod)%Mod;
		for(int i=1;i<=n;i++)
			pyrf[i].k=pyrf[i].a*1.0/pyrf[i].w*1.0;
		sort(pyrf+1,pyrf+n+1,cmp);
		int p1=0,p2=0;
		int x=m;
		for(int i=1;i<=n;i++){
			if(x>=pyrf[i].w){
				p1+=pyrf[i].a;
				x-=pyrf[i].w;
			}
		}
		for(int i=0;i<=m;i++)
			f[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=pyrf[i].w;j--)
				f[j]=max(f[j],f[j-pyrf[i].w]+pyrf[i].a);
		}
		p2=f[m];
		//cout<<kkk<<" "<<p1<<" "<<p2<<endl;
		if(p1==p2)
			ans++;
		cout<<ans%Mod;
		return ;		
	}
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}
//分越少的部分分一般更好拿
