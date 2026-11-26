#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,t[100005],s[100005],m1,m2,o=100000000,ans,rs;
int findcheap(int k)
{
    int l=1,r=n;
    int mid=(l+r+1)/2;
    while(l<r)
    {
        //cout<<"{"<<l<<' '<<r<<' '<<mid<<' '<<k<<"}";
        if(t[mid]>=k)
        {
            r=mid-1;
        }
        else
        {
            l=mid;
        }
        mid=(l+r+1)/2;
    }
    return l;
}
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i]>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        o=min((s[i]+t[i]),o);
    }
    sort(t+1,t+n+1);
    //int u=findcheap(o/2);
    //rs=u+1;
    /*for(int i=1;i<=u;i++)
    {
        if(t[i]+t[i+1]>=o && m<o+a[i])
        {
            rs=i;
            break
        }
        if(t[i]<=m)
        {
            m-=t[i];
            ans++;
            cout<<"{"<<m<<' '<<i<<' '<<ans<<' '<<t[i]<<"}";
        }
        else
        {
            break;
        }
    }
    while(o<=m)
    {
        //cout<<"{"<<m<<' '<<' '<<ans<<' '<<o<<"}";
        m-=o;
        ans+=2;
    }
    for(int i=u+1;i<=n;i++)
    {
        if(t[i]<=m)
        {
            m-=t[i];
            ans++;
        }
        else
        {
            break;
        }
    }*/
    for(int i=1;i<=n;i++)
    {
        if(m<t[i])
        {
            break;
        }
        if(t[i]+t[i+1]<=o)
        {
            m-=t[i];
            ans++;
            //cout<<'{'<<t[i]<<' '<<m<<' '<<ans<<'}';
        }
        else if(m>=o)
        {
            if(m>=o)
            {
                long long s=m/o;
                m-=s*o;
                ans+=2*s;
                //cout<<'{'<<o<<' '<<m<<' '<<ans<<'}';
            }
            if(m>=t[i])
            {
                m-=t[i];
                ans++;
                //cout<<'{'<<t[i]<<' '<<m<<' '<<ans<<'}';
            }
        }
        else
        {
           m-=t[i];
           ans++;
           //cout<<'{'<<t[i]<<' '<<m<<' '<<ans<<'}';
        }
    }
    cout<<ans;
    return 0;
}
