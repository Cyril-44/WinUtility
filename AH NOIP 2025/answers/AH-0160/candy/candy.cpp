#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int m,id;
}a[100001];
bool cmp(node x,node y)
{
	return x.m<y.m;
}
long long p;
long long minn=20000005,k,idx,kp;
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].m>>p;
        a[i].id=i;
        if(minn>=a[i].m+p)
        {
			minn=a[i].m+p;
			idx=i;
			k=a[i].m;
		}
    }
    kp=k;
    int cnt=0;
    sort(a+1,a+n+1,cmp);
    double k=minn*1.0/2;
    for(int i=1;i<=n;i++)
    {
		if(a[i].m<k)
		{
		    if(a[i].m+a[i+1].m>minn&&(m-(m/minn)*minn)<=a[i].m)
            {
                break;
            }
			cnt++;
			m=m-a[i].m;
			if(a[i].id==idx)
			{
				kp=minn-a[i].m;
			}
		}
		if(a[i].m>=k&&a[i].m<=minn)
		{
			if(m-(m/minn)*minn>=a[i].m)
			{
				cnt++;
				m-=a[i].m;
				if(a[i].id==idx)
				{
					k=minn-a[i].m;
				}
			}
			else
			{
				break;
			}
		}
		if(a[i].m>minn)
		{
			break;
		}
	}
	cnt+=m/minn*2;
	m-=m/minn*minn;
	if(m>=kp)
	{
		cnt++;
	}
	cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
