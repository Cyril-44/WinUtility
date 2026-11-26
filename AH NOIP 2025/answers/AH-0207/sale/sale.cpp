#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[5010],ans,tot;
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=1;
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            ans=(ans%998244353)*2%998244353;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
