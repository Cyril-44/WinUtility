#include<bits/stdc++.h>
using namespace std;
long long c,T,n,m,a[5001],ans,anschu,can,tmp,tmp2,tmp3,tmp4,x;
const int MOD=998244353;
int tg(int s,int e)
{
	can=1;
	int i1;
	for(i1=n;i1>=a[e];i1++)
	{
		if((a[i1]/2)>a[s])can+=2;
		else break;
	}
	can+=(e-s-1);
	can+=(i1-e);
	return i1;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((a[i]*2)<a[j]){break;}
				else
				{
					x=tg(i,j);
					if(can>=m-1)
					{
						//x-j+1
						tmp=1;
						for(int k=1;k<i;k++){tmp*=2;tmp%=MOD;}
						tmp2=1;
						tmp4=0;
						tmp3=can-m+1;
						tmp4+=(j-i-1);
						tmp4+=(n-j);
						for(int k=(tmp4-tmp3+1);k<=tmp4;k++)
						{
							tmp2*=k;
							tmp2%=MOD;
						}
						tmp*=tmp2;
						ans+=tmp;
					}
				}
			}
		}
		anschu=1;
		for(int i=1;i<=n;i++)
		{
			anschu*=2;
			anschu%=MOD;
		}
		cout<<anschu-ans<<endl;
	}
	return 0;
	
}
