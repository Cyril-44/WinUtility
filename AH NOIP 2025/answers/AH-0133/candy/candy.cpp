#include<bits/stdc++.h>
using namespace std;
struct ca{
    int v,id;
    bool operator<(const ca& x) const {
        return v>x.v;
    }
};
priority_queue<ca> p;
long long n,m,ans,sum2;
bool b[100005];
double sum=1000000001.0;
int a[100005][2];
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    long long i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        p.push({a[i][0],i});
        if(sum>(1.0*(a[i][0]+a[i][1]))/2)
        {
            sum=(1.0*(a[i][0]+a[i][1]))/2;
        }
    }
    ca u;
    long long  sum2=2*sum;
    while(m>=p.top().v||m>=sum2)
    {
        u=p.top();
        if(sum<u.v&&m>=sum2)
        {
            ans=ans+(m/sum2)*2;
            m=m%sum2;
        }
        else
        {
        ans++;
        m-=u.v;
        p.pop();
        if(b[u.id]==0)
        {
            b[u.id]=1;
            p.push({a[u.id][1],u.id});
        }
        else
        {
            b[u.id]=0;
            p.push({a[u.id][0],u.id});
        }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            if(m>=a[i][0])
            {
                ans++;
                m-=a[i][0];
            }
        }
        else
        {
            if(m>=a[i][1])
            {
                ans++;
                m-=a[i][1];
            }
        }
    }
    cout<<ans;
    return 0;
}
