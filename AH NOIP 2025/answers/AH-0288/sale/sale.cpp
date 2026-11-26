#include<iostream>
#include<algorithm>
using namespace std;
int n,m,i,j,t,k,l,w9,f1,a[100001];
long long ans1=1;
int main()
{
   freopen("sale.in","r",stdin);
   freopen("sale.out","w",stdout);
    cin>>w9;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        f1=1;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(k!=a[i]&&i!=0) f1=0;
            k=a[i];
        }
            for(i=0;i<n;i++)
        {
            ans1*=2;
            ans1=ans1%998244353;
        }
    }
    if(f1==1)
    cout<<ans1;
    else cout<<ans1-2;
        return 0;
}
