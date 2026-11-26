#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
ll op,n,m,T,a[N],n1[15],n2[15],b[15],ns1,ns2;
/*
void dfs(ll u)
{
    if(u==11)
        sort(n1+1,n1+ns1+1,greater<ll>());
        sort(n2+1,n2+ns2+1,greater<ll>());
        ll t1=1,t2=1,rans=0,cnt=0;
        while(m){
            if(t2>ns2&&t1>ns1)break;
            if(t2>ns2){
                rans+=n1[t1];
                t1++;
                m--;
                if(t1>ns1)break;
                rans+=n1[t1];
                t1++;
                m--;
            }else if(t1>ns1){
                rans+=n2[t2];
                t2++;
                m-=2;
            }else{
                if(n1[t1]+n1[t1+1]>n2[t2]){
                    rans+=n1[t1];
                    t1++;
                    m--;
                    if(t1>ns1)continue;
                    rans+=n1[t1];
                    t1++;
                    m--;
                }else{
                    rans+=n2[t2];
                    t2++;
                    m-=2;
                }
            }
        }
        for(int i=1;i<=ns1;i++)n1
    }
}*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>op>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        /*
        if(op<=5)
        {

            dfs(1);
            cout<<ans;
        }*/
        if(op==16||op==18)
        {
            ll ans=1;
            for(int i=1;i<=n;i++)
            {
                ans=(ans*2)%998244353;
            }
            cout<<ans<<"\n";
        }
        if((op>=7&&op<=9)||(op>=14&&op<=15))
        {
            ll ans=1,p=0,q=0;
            for(int i=1;i<=n-2;i++)ans=(ans*2)%998244353;
            sort(a+1,a+n+1);
            for(int i=1;i<=n-2;i++)
            {
                if(a[i]*2>a[n-1])p++;
                if(a[i]*2>a[n])q++;
            }
            for(int i=1;i<=n-2-p;i++)ans=(ans*2)%998244353;
            if(a[n-1]*2<=a[n])for(int i=1;i<=n-2-q;i++)ans=(ans*2)%998244353;
            p=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]*2>a[n]||a[i]*2>a[n-1])p++;
            }
            for(int i=1;i<=n-2-p;i++)ans=(ans*2)%998244353;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
