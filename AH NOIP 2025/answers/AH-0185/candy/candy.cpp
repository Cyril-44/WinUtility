#include<bits/stdc++.h>
using namespace std;
struct pp{
	int w,num,nj;
	}sj[200005],sj1[100005];
bool cmp(pp x,pp y)
{
	return x.w<y.w;
	}
long long n,ans=0,a1[100005],a2[100005],sm[100005],ju[100005];
long long m;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a1[i]=a,a2[i]=b;
		}
	for(int i=1;i<=n;i++)
	{
		sj[i].w=a1[i],sj[i].num=i,sj[i].nj=0,sj[i+n].w=a2[i],sj[i+n].num=i,sj[i+n].nj=1;
		sj1[i].w=a1[i],sj1[i].num=i;
		sm[i]=a1[i]+a2[i];
		}
	sort(sj+1,sj+n*2+1,cmp);
	sort(sj1+1,sj1+n+1,cmp);
	sort(sm+1,sm+n+1);
	//for(int i=1;i<=n;i++)
	//	printf("%d ",sj1[i].w);
	//printf("\n");
	for(int i=1;i<=n;i++)
	{
		if(sj1[i].w*2<sm[1]&&sj1[i].w<=m)
		{
			m-=sj1[i].w;
			ju[sj1[i].num]=1;
			ans++;
			//printf("!");
			}
	}
	//for(int i=1;i<=n;i++)
	//	printf("%d ",ju[i]);
	//printf("\n");
	long long t=m/sm[1];
	ans=ans+t*2;
	m=m-t*sm[1];
	while(1)
	{
		int mn=1e9+7,nd=0;
		for(int i=1;i<=2*n;i++)
		{
			if(sj[i].nj==ju[sj[i].num])
			{
				if(mn>sj[i].w)
				{
					mn=sj[i].w;
					nd=sj[i].num;
		//			printf("%d\n",mn);
					break;
					}
				}
			}
		if(m>=mn)
		{
			m-=mn;
			ans++;
			if(ju[nd]==1)
				ju[nd]=0;
			else
				ju[nd]=1;
			}
			else
				break;
		}
	//for(int i=1;i<=2*n;i++)
	//{
	//	int d=sj[i].num;
	//	if()
	//for(int i=1;i<=n;i++)
	//	printf("%d ",ju[i]);
	//printf("\n");
	//for(int i=1;i<=n;i++)
	//	printf("%d %d %d\n",sj[i].w,sj[i].nj,ju[sj[i].num]);
	//printf("\n");
	//printf("\n");
	//printf("%lld\n",m);
	printf("%lld",ans);
	return 0;
	}
