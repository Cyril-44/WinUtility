#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
int c,t,cnt;
int n,m;
struct stu{
	int y,b;
	double xj;
}a[50005],k[50005];
int f[50005];
bool cmp(stu x,stu y){
	if(x.xj!=y.xj)
		return x.xj>y.xj;
	return x.y>y.y;
}
bool cmp2(stu x,stu y){
	return x.y>y.y;
}
void check(){
	for(int i=1;i<=m;i++) f[i]=0;
	int sum=m,sum2=0;
	for(int i=1;i<=n;i++){
		k[i].y=a[i].y;
		k[i].b=a[i].b;
	}
	for(int i=1;i<=n;i++){
		k[i].xj=k[i].y*1.0/k[i].b;
	}
	sort(k+1,k+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(sum>=k[i].b){
			sum-=k[i].b;
			sum2+=k[i].y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=k[i].b;j--){
			f[j]=max(f[j],f[j-k[i].b]+k[i].y);
		}
	}
	if(f[m]==sum2) cnt++;
}
void dfs(int x){
	if(x==n+1) {
		check();
		return ;
	}
	a[x].b=1;
	dfs(x+1);
	a[x].b=2;
	dfs(x+1);
}
void js(){
	sort(a+1,a+n+1,cmp2);
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=2;
		sum%=mod;
	}
	int num=0;
	for(int i=2;i<=n;i++){
		if(a[i].y>a[1].y/2){
			num++;
		}
	}
	int sum2=1;
	for(int i=num+2;i<=n;i++){
		sum2*=2;
		sum2%=mod;
	}
	cnt=sum+mod-sum2%mod*num%mod;
	cnt%=mod;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			a[i].b=a[i].xj=a[i].y=0;
			k[i].b=k[i].xj=k[i].y=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].y;
		}
		if(n<=10){
			dfs(1);
			cout<<cnt<<endl;
			continue;
		}
		if(m==2){
			js();
			cout<<cnt<<endl;
			continue;
		}
		cnt=1;
		for(int i=1;i<=n;i++){
			cnt*=2;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
