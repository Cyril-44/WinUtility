#include<bits/stdc++.h>
using namespace std;
unsigned long long mod=1;
int n,q,l,r,a[50005],mx[50005],sum[50005];
unsigned long long ans;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	for(int i=1;i<=63;i++){
		mod=mod*2;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	cin>>q;
	while(q--){
		scanf("%d%d",&l,&r);
		memset(mx,-0x3f,sizeof(mx));
		ans=0;
		for(int i=1;i<=n;i++){
			int x=max(1,i-r+1);
			while(x<=i){
				for(int y=max(x+l-1,i);y-x+1<=r;y++){
					mx[i]=max(sum[y]-sum[x-1],mx[i]);
				}
				x++;
			}
			mx[i]=mx[i]*i;
			if(ans==0) ans=mx[i];
			else if(mx[i]<0){
				if(ans<0){
					ans=(mod+ans+mod)^(mod+mx[i]+mod);
				}
				else ans=ans^(mod+mx[i]+mod);
			}
			else ans=ans^mx[i];
		}
		cout<<ans<<endl;
	}
	return 0; 
}
