#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<=b;++i)
#define forl(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int qmi(int a,int b)
{
    int ans=1,qer=1;
    while(b){
        qer*=a;
        if(b%2==1)ans*=qer;
        b/=2;
    }
    return ans;
}

void solve()
{
    int n,m;cin>>n>>m;
    int ans=1,iner;
    forr(i,1,n)
    {
        cin>>iner;
        ans*=2;
        ans%=998244353;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    int c,t;cin>>c>>t;
    while (t--)solve();
    return 0;
}


