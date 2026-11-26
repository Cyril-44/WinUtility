#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],mx,l,r;
unsigned long long ans;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]=a[i]+a[i-1];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		scanf("%lld %lld",&l,&r);
		ans=0;
		for(int j=1;j<=n;j++){
			mx=-0x3f3f3f3f3f3f3f3f;
			for(int k=l;k<=r;k++){
				//cout<<"|"<<mx<<' ';
				for(int g=j;g<=j+k-1;g++){
					mx=max(mx,a[g]-a[g-k]);
					cout<<mx<<' ';
				}
				//cout<<'\n';
			}
			//cout<<ans<<' '<<j*mx<<'\n';
			ans=(ans^(j*mx));
		}
		cout<<ans<<'\n';
	}
}
/*
0 10
5 5
10 7 5 5 6
10 7 6 5 5 
48 33 25 24 24
*/
