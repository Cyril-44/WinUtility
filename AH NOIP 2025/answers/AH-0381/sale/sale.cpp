#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,tt;
int n,m;
int a[5010];
int cf[5010];
const int mod=998244353;
int kkk_sc[5010];
bool cmp(int a,int b){return a>b;}
int cnt=0;
struct node{
	int f;
	double g;
}xt[5010];
bool cmp2(node a,node b){return a.g!=b.g?a.g>b.g:a.f>b.f;}
int ff[5010];
bool check(){
	int mm=m;
	bool ppp=true;
	for(int i=1;i<=n;i++)xt[i].g=a[i]/1.0/ff[i],xt[i].f=ff[i];
	sort(xt+1,xt+n+1,cmp2);
	int ls2=0,ls1=0;
	for(int i=1;i<=n;i++){
		if(!mm)break;
		if(mm==1){
			if(xt[i].f==1){
				if(ls1&&ls2){
					if(xt[i].g+xt[ls1].g<xt[ls2].g*2)return false;
					else return true;
				}else return true;
			}else if(ppp)ls2=i,ppp=false;
		}
		if(xt[i].f<=mm){mm-=xt[i].f;}
		if(xt[i].f==1)ls1=i;
	}
	if(mm==1&&ls2&&ls1&&xt[ls1].g<xt[ls2].g*2)return false;
	return true;
}
int C[1010][1010];
void dfs(int i){
	if(i==n+1){
		if(check()){cnt++;/*for(int i=1;i<=n;i++)cout<<ff[i]<<' ';cout<<'\n';*/}
		return ;
	}
	dfs(i+1);
	ff[i]=2;
	dfs(i+1);
	ff[i]=1;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	kkk_sc[0]=1;
	for(int i=1;i<=5000;i++)kkk_sc[i]=kkk_sc[i-1]*2%mod;
	cin>>c>>tt;
	if(c==10||c==11||c==12||c==19||c==20){
		C[0][0]=1;
		for(int i=1;i<=1000;i++){
			for(int j=0;j<=i;j++){
				if(i==j||j==0)C[i][j]=1;
				else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
			}
		}
	}
	while(tt--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1,cmp);
		if(1<=c&&c<=5){
			cnt=0;
			for(int i=1;i<=n;i++)ff[i]=1;
			dfs(1);
			cout<<cnt<<'\n';
			continue;
		}
		if(c==16||c==18||m==2*n-1){
			cout<<kkk_sc[n]%mod<<'\n';
			continue;
		}
		if(c==17){
			int ans=0;
			if(a[n]>a[n-1]/2&&a[n]<a[n-1])ans++;
			cout<<(kkk_sc[n]+mod-ans)%mod<<'\n';
			continue;
		}
		if(c==10||c==11||c==12||c==19||c==20){
			int anss=0;
			for(int i=1;i<=n;i++){
				for(int j=m%2;j<i;j+=2){
					if(i+j+1>m)
					anss=(anss+C[i-1][j])%mod;
				}
			}
			cout<<(kkk_sc[n]+mod-anss)%mod<<'\n';
			continue;
		}
		if(m==2){
			int ans=0;
			int t=n;
			for(int i=2;i<=n;i++){
				if(a[i]>a[1]/2){
					while(a[t]<a[1]-a[i])t--;
					ans=(ans+kkk_sc[n-t])%mod;
				}
			}
			cout<<(kkk_sc[n]-ans+mod)%mod<<'\n';
			continue;
		}
	}
	return 0;
}
