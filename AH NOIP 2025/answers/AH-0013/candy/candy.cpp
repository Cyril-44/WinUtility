#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N],c=2e9;ll m,ans;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int x,y,i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        c=min(c,x+y);a[i]=x;
    }
    sort(a+1,a+n+1);
    ll s=0;
    for(int i=0;i<=n;i++){
        s+=a[i];
        if(s>m)break;
        ans=max(ans,i+(m-s)/c*2);
    }
    cout<<ans;
}