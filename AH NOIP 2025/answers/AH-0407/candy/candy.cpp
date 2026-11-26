#include<bits/stdc++.h>
using namespace std;
int n,mn=1,cnt,a[100005],b[100005],f[100005];
long long m,sum;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]+b[i]<a[mn]+b[mn])mn=i;
		else if(a[i]+b[i]==a[mn]+b[mn]&&a[i]<a[mn])mn=i;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<a[mn])f[++cnt]=a[i];
	}
	int ms=a[mn]+b[mn];
	long long ans=m/ms*2+m%ms/a[mn],p=m/ms,yu=m%ms,j=1,c=cnt;
	while(j<=cnt&&p>=0){
		for(;j<=cnt;j++){
			yu-=f[j];
			if(yu<0){
				c=j-1;
				yu+=f[j];
				break;
			}
		}
		ans=max(ans,p*2+c);
		cout<<ans<<" "<<p<<" "<<c<<"\n";
		yu+=b[mn];
		for(;j<=cnt;j++){
			yu-=f[j];
			if(yu<0){
				c=j-1;
				yu+=f[j];
				break;
			}
		}
		ans=max(ans,p*2+c-1);
		yu+=a[mn];
		p--;
		cout<<ans<<" "<<p<<" "<<c<<"\n";
	}
	cout<<ans;
	return 0;
}
