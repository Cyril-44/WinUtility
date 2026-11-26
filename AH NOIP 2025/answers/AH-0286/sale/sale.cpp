#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,tt;
long long sum;
struct cd
{
	int a,aa;
	double w;
}sa[5005];
struct cda
{
	int ab,aaa;
	double wa;
}saa[5005];
int cmp(cda b,cda c)
{
	if(b.wa!=c.wa)
		return b.wa>c.wa;
	else
		return b.ab>c.ab;
}
void check()
{
	long long ma[20][20]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j-sa[i].aa>=0){
				ma[i][j]=max(ma[i-1][j],ma[i-1][j-sa[i].aa]+sa[i].a);
			}
			else
				ma[i][j]=ma[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		saa[i].ab=sa[i].a;
		saa[i].aaa=sa[i].aa;
		saa[i].wa=sa[i].w;
	}
	sort(saa+1,saa+n+1,cmp);
	long long sumb=0,tm=m;
	for(int i=1;i<=n;i++){
		if(saa[i].aaa<=tm){
			tm-=saa[i].aaa;
			sumb+=saa[i].ab;
		}
	}
	if(sumb==ma[n][m]){
		sum++;
	}
}
void dfs(int d){
	if(d==n){
		check();
		return ;
	}
	sa[d+1].aa=1;
	sa[d+1].w=sa[d+1].a;
	dfs(d+1);
	sa[d+1].aa=2;
	double ta=sa[d+1].a;
	sa[d+1].w=ta/2;
	dfs(d+1);
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>m;
		int f=0;
		for(int i=1;i<=n;i++){
			cin>>sa[i].a;
			if(i==1)
				tt=sa[i].a;
			if(sa[i].a!=tt)
				f=1;
		}
		if(f==0||m==n*2-1){
			sum=2;
			for(int i=2;i<=n;i++){
				sum=sum*2%998244353;
			}
			cout<<sum<<endl;
		}
		else if(m==n*2-2){
			sum=2;
			for(int i=2;i<=n;i++){
				sum=sum*2%998244353;
			}
			int mia=INT_MAX,mib=INT_MAX,su;
			for(int i=1;i<=n;i++){
				if(sa[i].a<mia){
					mia=sa[i].a;
					su=1;
				}
				else if(sa[i].a==mia){
					su++;
				}
			}
			for(int i=1;i<=n;i++){
				if(sa[i].a>mia&&sa[i].a<=mib)
					mib=sa[i].a;
			}
			if(mia>mib/2&&su==1){
				sum--;
				if(sum<0){
					sum=998244352;
				}
			}
			cout<<sum<<endl;
		}
		else if(m==2&&n>=40){
			sum=2;
			for(int i=2;i<=n;i++){
				sum=sum*2%998244353;
			}
			int maa=INT_MIN,mab=INT_MIN,te;
			for(int i=1;i<=n;i++){
				if(sa[i].a>maa){
					maa=sa[i].a;
					te=i;
				}
			}
			for(int i=1;i<=n;i++){
				if(sa[i].a<=maa&&i!=te&&sa[i].a>=mab)
					mab=sa[i].a;
			}
			if(mab<=maa/2)
				cout<<sum<<endl;
			else 
				cout<<sum-n<<endl;
		}
		else {
			sa[1].aa=1;
			sa[1].w=sa[1].a;
			dfs(1);
			sa[1].aa=2;
			double ta=sa[1].a;
			sa[1].w=ta/2;
			dfs(1);
			cout<<sum<<endl;
		}
	}
	return 0;
}
