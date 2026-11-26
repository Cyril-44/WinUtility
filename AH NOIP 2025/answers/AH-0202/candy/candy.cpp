#include<bits/stdc++.h>
using namespace std;
int n,i,k;
unsigned long long m,x[200001],y[100001],j,ans;
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        x[n+i]=x[i]+y[i];
    }
        unsigned long long f[m+1];
        f[0]=0;
        unsigned long long t=x[n+1];
        for(j=1;j<=m;j++)
        {
            f[j]=f[j-1];
            if((j>=t)&&(f[j-t]+2>f[j]))
            {
                f[j]=f[j-t]+2;
            }
        }

        //for(k=1;k<=m;k++) cout<<f[k]<<" ";
        //cout<<endl;

        for(i=n+2;i<=2*n;i++)
        {
            for(j=x[i];j<=m;j++)
            {
                if(f[j-1]>f[j]) f[j]=f[j-1];
                if(f[j-x[i]]+2>f[j])
                {
                    f[j]=f[j-x[i]]+2;
                }
            }
            //for(k=1;k<=m;k++) cout<<f[k]<<" ";
            //cout<<endl;
        }

        for(i=1;i<=n;i++)
        {
            t=x[i];
            //cout<<t<<endl;
            for(j=m;j>=t;j--)
            {
                if((j>=t)&&(f[j-t]+1>f[j]))
                {
                    f[j]=f[j-t]+1;
                }
            }
            //for(k=1;k<=m;k++) cout<<f[k]<<" ";
            //cout<<endl;
        }
        ans=f[m];
    cout<<ans;
    return 0;
}




