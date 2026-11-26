#include<bits/stdc++.h>
using namespace std;
const long long mod=(long long)pow(2,64);
long long n,a[50010],p[50010],q,ans,l,r,k,sm;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]+a[i];
	}
	cin>>q;
	while(q--){
		cin>>l>>r;
		for(int i=1;i<=n;i++){
			for(int k=l;k<=r;k++){
				sm=-mod;
				if(i-k+1<1)
				for(int j=1;j<=i&&j+k-1<=n;j++){
					sm=max(sm,p[j+k-1]-p[j-1]);
				}
				else 
				for(int j=i-k+1;j<=i&&j+k-1<=n;j++){
					sm=max(sm,p[j+k-1]-p[j-1]);
				}
				ans+=((long long)i*sm+mod)%mod;
			}
		}
		cout<<(ans+mod)%mod<<endl;
	}
	return 0;
}
