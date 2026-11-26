#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=998244353,N=8005;
ll c,t,n,m,a[N],s[N];
bool cmp(int x,int y){
    return x>y;
}
ll cmn(int n,int m){
    if(m==1)return n;
    if(m==0)return 1;
    ll ans=1;
    for(int i=1;i<=n;i++)ans=ans*i%INF;
    for(int i=1;i<=m;i++)ans=ans/i;
    for(int i=1;i<=n-m;i++)ans=ans/i;
    return ans%INF;
}
ll er(int x){
    ll ans=1;
    for(int i=1;i<=x;i++)ans=ans*2%INF;
    return ans;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
        cin>>n>>m;
        bool f=true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>1&&a[i]!=a[i-1])f=false;
        }
        if(f){
            int ans=1;
            for(int i=1;i<=n;i++){
                ans=ans*2%INF;
            }
            cout<<ans<<endl;
            continue;
        }
        int l=(m+1)/2,r=min(m,n);
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            s[i]=s[i-1]+a[i];
        }
        ll ans=0;
        for(int i=l;i<=r;i++){
            int cnt=0;
            for(int j=i+1;j<=n;j++){
                 if(a[j]*2<a[i])break;
                 cnt++;
            }
            ans+=cmn(i-cnt,m-i-cnt)*er(cmn(n-i,n-i-cnt))+(cmn(i,m-i)-cmn(i-cnt,m-i-cnt))*er(cmn(n-i,n-i-cnt)-cmn(n-i-cnt,n-i-2*cnt));
            ans%=INF;
        }
        cout<<ans<<endl;
	}
	return 0;
}
