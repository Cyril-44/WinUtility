#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[5005],c,t,n,m;
const int p=998244353;
LL ksm(int d,int v){
	if(v==1)
		return d;
	if(v%2==1)
		return (ksm(d,v/2)%p*ksm(d,v/2)%p*d)%p;
	if(v%2==0)
		return (ksm(d,v/2)%p*ksm(d,v/2)%p)%p;
	}

bool cmp(int x,int y){
	return x>y;
	}
int ef(int d)
{
	int	l=0,r=n+1;
	int mid=(l+r)/2;
	while(l+1<r)
	{
	//	printf("1");
		if(a[mid]>=d)
			l=mid+1;
		else
			r=mid-1;
		}
	return l-1;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		LL sum=0,sum1=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			}
		sum1=ksm(2,n-1);
		sort(a+1,a+n+1,cmp);
	//	for(int i=1;i<=n;i++)
//			printf("%d ",a[i]);
	//	printf("\n");
		int mx=a[1];
		for(int i=2;i<=n;i++)
		{
			
			if(a[i]*2>=mx)
			{
				int l=0;
				for(int j=i;j<=n;j++)
				{
					if(mx-a[j]>a[i])
					{
						l=j-1;
						break;
					}
					}
	//		printf("%d\n",l);
				if(l!=0)
					sum1=(sum1+ksm(2,l-2))%p;
				}
			}
		printf("%lld\n",sum1);
		}
	return 0;
	}
