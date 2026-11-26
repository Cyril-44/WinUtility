#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    int n,m;
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<int> >q,qq;
    for(int i=1,no,a;i<=n;i++)
    {
        scanf("\n%lld %lld",&a,&no);
        q.push(a+no);
        qq.push(a);
    }
    int ans=m/q.top();
    int sy=m-(ans*q.top());
    sy-=q.top();
    ans*=2;
    int na=ans;
    na+=2;
    for(int c=0;c<=ans/2;c++)
    {
        na-=2;
        sy+=q.top();
        while(!qq.empty())
        {
            if(sy>=qq.top())
            {
                na++;
                sy-=qq.top();
                qq.pop();
            }
            else
            {
                break;
            }
        }
        if(na>=ans)
            ans=na;
        else
            break;
    }
    cout<<ans;
    return 0;
}
