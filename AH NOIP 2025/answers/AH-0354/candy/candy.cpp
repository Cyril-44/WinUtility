#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int x[100005],y[100005];
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	int n=read();
	long long m=read();
	int minv=INT_MAX;
	for(int i=1;i<=n;i++)
		x[i]=read(),y[i]=read(),minv=min(minv,x[i]+y[i]);
	sort(x+1,x+n+1);
	long long ans=m/minv*2;
	for(int i=1;i<=n;i++)
	{
		if(m<x[i]) break;
		m-=x[i];
		ans=max(ans,i+m/minv*2);
	}
	write(ans);
	return 0;
}
