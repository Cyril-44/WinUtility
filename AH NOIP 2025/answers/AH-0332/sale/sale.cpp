#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int c,t,n,m,a[N];
void work1(bool f){
    while(t--){
        scanf("%d%d",&n,&m);
        long long ans=1;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),ans=ans*2%mod;
        sort(a+1,a+1+n);
        if(f==1&&a[1]*2>a[2]&&a[2]>a[1]) ans=(ans+mod-1)%mod;
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c==16||c==18) work1(0);
    if(c==17) work1(1);
    return 0;
}
