#include<bits/stdc++.h>
#define P 998244353
using namespace std;
int c,t;
int n,m,ans,a[5010];
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			ans=ans*2%P;
		cout<<ans<<endl;
	}
    return 0;
}
