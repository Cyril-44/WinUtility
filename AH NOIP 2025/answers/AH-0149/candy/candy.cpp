#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
long long m,n;
struct node
{
    long long x,y,tot1;
}candy[maxn];
priority_queue<long long ,vector<long long>,greater<long long > >X;
priority_queue<long long ,vector<long long>,greater<long long > >Y;
long long totm1=3000000100,po1,xm,ym;
long long ans;
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		candy[i].x=x;
		candy[i].y=y;
		candy[i].tot1=x+y;
		if(x+y<totm1)
        {
            totm1=x+y;
            po1=i;
            xm=x;
            ym=y;
        }
	}
	if(candy[po1].x<candy[po1].y)
    {
        sort(candy+1,candy+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(m>=candy[i].x)
            {
                if(candy[i].x<xm)
                {
                    ans++;
                    m-=candy[i].x;
                    Y.push(candy[i].y);
                }
                else
                    X.push(candy[i].x);
            }
        }
        long long num=m/totm1;
        m=m%totm1;
        ans+=num*2;
        for(int i=1;i<=X.size()+Y.size();i++)
        {
            if(X.empty())
                X.push(2000000100);
            if(Y.empty())
                Y.push(2000000100);
            if(X.top()<Y.top())
            {
                if(m>=X.top())
                {
                    ans++;
                    m-=X.top();
                    X.pop();
                }
                else
                    break;
            }
            else
            {
                if(m>=Y.top())
                {
                    ans++;
                    m-=Y.top();
                    Y.pop();
                }
                else
                    break;
            }
        }
        cout<<ans;
    }
    else//candy[po1].x>=candy[po1].y
    {
        for(int i=1;i<=n;i++)
        {
            if(m>=candy[i].x)
            {
                if(candy[i].x<ym)
                {
                    ans++;
                    m-=candy[i].x;
                    Y.push(candy[i].y);
                }
                else
                    X.push(candy[i].x);
            }
        }
        long long num=m/totm1;
        m=m%totm1;
        ans+=num*2;
        for(int i=1;i<=X.size()+Y.size();i++)
        {
            if(X.empty())
                X.push(3000000100);
            if(Y.empty())
                Y.push(3000000100);
            if(X.top()<Y.top())
            {
                if(m>=X.top())
                {
                    ans++;
                    m-=X.top();
                    X.pop();
                }
                else
                    break;
            }
            else
            {
                if(m>=Y.top())
                {
                    ans++;
                    m-=Y.top();
                    Y.pop();
                }
                else
                    break;
            }
        }
        cout<<ans;
    }
	return 0;
}

