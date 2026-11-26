#include<bits/stdc++.h>
using namespace std;
struct candy{
    long long x,y,z;
}a[100005],b[100005];
long long n,m,ans,t,r,s,tmp;
bool cmp1(candy p,candy q){return p.z<q.z;}
bool cmp2(candy p,candy q){return p.x<q.x;}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
        a[i].z=a[i].x+a[i].y;
        b[i].x=a[i].x;
        b[i].y=a[i].y;
        b[i].z=a[i].z;
    }
    sort(a,a+n,cmp1);
    sort(b,b+n,cmp2);
    t=a[0].x;
    for(r=0;r<n;r++)
    {
        if(b[r].x>=t)break;
        if(m<b[r].x)break;
        ans++;
        m-=b[r].x;
    }
    if(m>=t)
    {
        ans++;
        m-=t;
		t=a[0].y;
    }
    for(;r<n;r++)
    {
        if(b[r].x>=t)break;
        if(m<b[r].x)break;
        ans++;
        m-=b[r].x;
    }
    if(m>=t)
    {
        ans++;
        m-=t;
		if(t!=a[0].x)t=a[0].x;
		else t=a[0].y;
    }
    while(1)
    {
        if(m<t)break;
        ans++;
        m-=t;
        if(t==a[0].x)t=a[0].y;
        else t=a[0].x;
    }
    r--;
    for(long long i=r;i>=0;i--)
    {
        s+=b[i].x;
        if(m+s>=a[0].z)tmp=max(tmp,(m+s)/a[0].z*2-(r-i+1));
    }
    cout<<ans+tmp;
	return 0;
}
