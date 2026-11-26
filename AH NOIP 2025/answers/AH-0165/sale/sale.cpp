#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
struct node{
	long long a,b,id;
}a[10000];
long long C,T,n,m,c[5010][5010];
bool cmp(node a,node b){
	if(a.a*1.0/a.b==b.a*1.0/b.b){
		if(a.a==b.a){
			return a.id<b.id;
		}
		return a.a>b.a;
	}
	return a.a*1.0/a.b>b.a*1.0/b.b;
}
long long k_pow(long long a,long long b){
	if(b==0){
		return 1;
	}
	long long ans=1;
	while(b){
		if(b%2==1){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	for(int i=0;i<=5000;i++){
		c[i][0]=1;
	}
	for(int i=1;i<=5000;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=mod;
		}
	}
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i].a;
			a[i].b=1;
			a[i].id=i;
			a[n+i].a=a[i].a;
			a[n+i].b=2;
			a[n+i].id=i;
		}
		sort(a+1,a+2*n+1,cmp);
		a[2*n+1].a=0;
		a[2*n+1].b=1;
		a[2*n+1].id=n+1;
		long long l,r,ans=0,cnt1,cnt2;
		for(int i=1;i<=2*n+1;i++){
			if(a[i].b==1){
				continue;
			}
			int j=i+1;
			for(;j<=2*n+1&&a[j].b==2;j++){}
			r=j;
			j=i-1;
			for(;j>=1&&a[j].b==2;j--){}
			l=j;
			//cout<<a[l].a<<" "<<a[r].a<<" "<<a[i].a<<endl;
			if(a[l].a+a[r].a>=a[i].a){
				//cout<<i<<" ";
				continue;
			}
			cnt1=0;
			cnt2=0;
			for(int j=i-1;j>=1;j--){
				if(a[j].id==a[i].id){
					continue;
				}
				if(a[j].b==1){
					cnt1++;
				}else if(a[j].b==2){
					cnt1--;
					cnt2++;
				}
			}
			long long c2=m-1-cnt2;
			if(c2<0){
				continue;
			}
			//cout<<c2<<" ";
			long long num=c[cnt1+cnt2][c2];
			if(cnt2>=c2){
				num-=c[cnt2][c2];
				num=num+mod;
				num%=mod;
			}
			//cout<<k_pow(2,n-cnt1-cnt2-1)<<" "<<c[cnt1+cnt2][c2]<<" ";
			num=num*k_pow(2,n-cnt1-cnt2-1);
			num%=mod;
			ans+=num;
			//cout<<num<<" "<<i<<endl;
		}
		cout<<(k_pow(2,n)-ans+mod)%mod<<endl;
	}
	return 0;
}
