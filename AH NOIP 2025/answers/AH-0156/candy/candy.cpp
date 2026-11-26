#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*1LL*f;
	
}
struct node
{
	long long x,y,id;
	long long sum=0;
}a[100010];
bool cmp(node u,node p)
{
	if(u.sum==p.sum) return u.x<p.x;
	return u.sum<p.sum;
}
bool cmp2(node u,node p)
{
	return u.x<p.x;
}
bool cmp3(node u,node p)
{
	return u.y<p.y;
}
long long k[100010],l[100010];
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m,sum2=2e18;
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i].x=read();
		a[i].y=read();
		a[i].sum=a[i].x+a[i].y;
		sum2=min(a[i].sum,sum2);
	}
	sort(a+1,a+n+1,cmp);
	long long ans=0;
	sort(a+1,a+n+1,cmp2);	
	long long nm=-1;
	for(int i=1;i<=n;i+=2)
	{
	//	cout<<a[i].x+a[i+1].x<<endl;
		if(m>=a[i].x+a[i+1].x&&a[i].x+a[i+1].x<sum2) 
		{
			ans+=2;
			m-=(a[i].x+a[i+1].x);
			a[i].id=1;
			a[i+1].id=1;
			nm=i+1;
			if(a[i+1].x==0) ans--;
		}
		else
		{
			break;
		}
	}
	nm=min(nm,n);
	if(nm!=-1)
	{
		sort(a+1,a+nm+1,cmp3);
		for(int i=1;i<=nm;i+=2)
		{
			if(m>=a[i].y+a[i+1].y&&a[i].y+a[i+1].y<sum2)
			{
				ans+=2;
				m-=(a[i].y+a[i+1].y);
				a[i].id=2;
				a[i+1].id=2;
				if(a[i+1].y==0) ans--;
			}
			else
			{
				break;
			}
		}
	}	
	//cout<<sum2<<" ";
	long long tot=0,tot2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].id==1) k[++tot]=a[i].y;
		else l[++tot2]=a[i].x;
	}
	sort(k+1,k+tot+1);
	sort(l+1,l+tot2+1);
	int i=1,j=1;
//	for(int i=1;i<=tot;i++)
//	{
//		cout<<k[i]<<" ";
//	}
//	cout<<endl<<tot2;
//	for(int j=1;j<=tot2;j++)
//	{
//		cout<<l[j]<<" ";
//	}
	ans=ans+(m/sum2)*2;
	m%=sum2;		
	//cout<<endl<<m<<" ";
	while(1)
	{
		if(i>tot&&j>tot2) break;
		if(i>tot)
		{
			if(m>=l[j])
			{
				m-=l[j];
				ans++;
				j++;
				continue;
			}
			else
			{
				break;
			}
		}
		if(j>tot2)
		{
			if(m>=k[i])
			{
				m-=k[i];
				ans++;
				i++;
				continue;
			}
			else
			{
				break;
			}
		}
		if(k[i]<l[j])
		{
			if(m<k[i]) break;
			m-=k[i];
			i++;
			ans++;
		}
		else 
		{
			if(m<l[j]) break;
			m-=l[j];
			j++;
			ans++;
		}
	}
	//cout<<m<<" ";
	
	printf("%lld",ans);
	return 0;
}
