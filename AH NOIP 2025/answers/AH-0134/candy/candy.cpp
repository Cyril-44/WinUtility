#include<bits/stdc++.h>
using namespace std;
long long m,sum,num=INT_MAX,f,t,n,ans,w,k;
struct node{
        int x,y;
        bool op=0;
}a[200005];
bool cmp(node q,node p)
{
    return q.x<=p.x;
}
int main()
{
        freopen("candy.in","r",stdin);
        freopen("candy.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
			if(num>=a[i].x+a[i].y) k=i,num=a[i].x+a[i].y;
		}
        a[k].op=1;
        w=a[k].x;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
			if(a[i].op==1)
			{
				if(i==n)
				{
					ans=ans+n-1;
					m=m-sum;
                    sum=0;
				}
				else ans--;
				continue;
			}
			if(a[i-1].op==0) f=a[i-1].x;
			else if(i==1) f=0;
			else f=a[i-2].x;
			t=a[i].x;
            sum+=t;
            if(f+t>num)
            {
				ans=ans+i-2;
				m=m-(sum-f-t);
                sum=0;
	            break;
             }
            if(sum>m)
			{
				ans=ans+i-1;
                m=m-(sum-t);
                sum=0;
                break;
			}
        }
        ans+=(m/num)*2;
        m=m-(m/num)*num;
        if(m>=w) ans+=1,m-=w;
        if(m>=f) ans+=1;
        cout<<ans;
        return 0;
}
