#include<bits/stdc++.h>
using namespace std;
long long a[50010],f[50010];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	unsigned long long ans;
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]+=a[i-1];
	}
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		memset(f,-0x3f,sizeof f);
		ans=0;
		scanf("%d%d",&l,&r);
		for(int len=l-1;len<r;len++)
			for(int i=1;i+len<=n;i++)
			{
				long long num=a[i+len]-a[i-1];
				for(int j=i;j<=i+len;j++)f[j]=max(f[j],num);
			}
		for(int i=1;i<=n;i++)ans^=f[i]*i;
		printf("%llu\n",ans);
	}
	return 0;
}
