#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int h;
int a[80001],b[80001],c[80001];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int t,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        b[1]=0;
        a[1]=1;
        c[1]=0;
        ans=0;
        for(i=1;i<=n;i++)
            c[i]=0;
        for(i=2;i<=n;i++)
        {
                cin>>a[i];
                b[i]=b[a[i]]+1;
                h=max(b[i],h);
                c[a[i]]++;
        }
        if(h==1)
        {
            cout<<1+n<<"\n";
            continue;
        }
        if(h==2)
        {
            int sum=0,sm2=0;
            for(i=1;i<=n;i++)
            {
                if(b[i]==1)
                {
                    if(c[i]!=0)
                    {
                        sum=max(c[i]+1,sum);
                        ans+=c[i]+2;
                    }
                    else
                        ans++;
                }
            }
            cout<<ans+sum+1<<"\n";
        }
        if(h>2)
        {
            cout<<2*n+1;
        }
    }
    return 0;
}
