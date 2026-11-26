#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 100005
using namespace std;
ll n,m;
ll a[N],b[N],ans,cnt,i=1,s[N];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d%d",&x,&y);
        a[i]=x+y,b[i]=x;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+b[i];
        if(s[i]>m) break;
        cnt=i;
    }
    ans=(m/a[1])*2;
    for(int i=1;i<=cnt;i++){
        ans=max(ans,((m-s[i])/a[1]*2+i));
    }
    cout<<ans;
    return 0;
}
