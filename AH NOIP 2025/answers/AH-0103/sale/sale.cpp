#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,m,n,mod=998244353,f,dp[5005];
struct Item{
    int a,p,w,num;
    bool operator<(const Item &x){
        if(w==x.w){
            if(a==x.a) return num<x.num;
            return a<x.a;
        }
        return w<x.w;
    }
}a[5005];
void span(int x){
    int cnt=1;a[cnt].p++;
    while(a[cnt].p>2){
        a[cnt].p=2;
        cnt++;
        a[cnt].p++;
    }
    if(cnt>n) f=1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i].a,a[i].num=i;
        if(c==7||c==8||c==9||c==14||c==15){
            sort(a+1,a+1+n);
            int ans=1;
            for(int i=1;i<=n-1;i++)
                ans=ans*2%mod;
            cout<<ans<<endl;
        }if(c>=1&&c<=3){
            for(int i=1;i<=n;i++)a[i].p=1,dp[i]=0;
            int cnt=0;
            while(!f){
                for(int i=1;i<=n;i++)
                    for(int j=m;j>=a[i].p;j--)
                        dp[j]=max(dp[j],dp[j-a[i].p]+a[i].a);
                for(int i=1;i<=n;i++) a[i].w=a[i].a*2/a[i].p;
                sort(a+1,a+1+n);
                int ans=0;
                for(int i=1;i<=n;i++){
                    if(m>=a[i].p){
                        ans+=a[i].a;
                        m-=a[i].p;
                    }
                }
                if(ans==dp[m]) cnt++;
                span(n);
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
