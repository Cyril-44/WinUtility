#include<bits/stdc++.h>
using namespace std;
long long c,T,n,m,f,p=998244353,a[5009];
long long B(long long x){
	long long sum=1,aa=2;
	while(x){
		if(x%2==1) sum=sum*aa%p;
		aa=aa*aa%p,x/=2;
	}
	return sum%p;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m>>a[1],f=1;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			if(a[i-1]!=a[i]) f=0;
		}
		if(f==1){cout<<B(n)%p<<endl;continue;}
		if(m==2){
			sort(a+1,a+n+1);
			long long w,ans=0;
			for(int i=n;i>0;i--)
				if(a[i]<=a[n]/2){w=i;break;}
			for(int i=w+1;i<=n;i++)
				for(int j=w;j>0;j++)
					if(a[i]+a[j]<a[n]){ans=(ans+B(j)%p)%p;break;}
			cout<<(B(n)%p-ans+p)%p<<endl;
		}
	}
	return 0;
}
