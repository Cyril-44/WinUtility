#include<bits/stdc++.h>
using namespace std;
int t,n,m,hav[4005],ans,dep2,havm=0;
bool dep1[4005];
int read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<'0' or ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' and ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	t=read();
	for(int G=1;G<=t;G++)
	{
		ans=0;havm=0;dep2=0;
		n=read();m=read();
		for(int i=2;i<=n;i++){dep1[i]=false;hav[i]=0;}
		for(int i=2;i<=n;i++)
		{
			int x;
			x=read();
			if(x!=1)
			{
				dep2++;
				hav[x]++;
				if(hav[x]>havm)havm=hav[x];
			}
			else dep1[i]=true;
		}
		ans+=dep2;
		for(int i=2;i<=n;i++)
		{
			if(dep1[i]&&hav[i]==0)ans+=1;
			else if(dep1[i])ans+=2;
		}
		ans+=3;
		cout<<max(ans,2+havm+n)<<endl;
	}
	return 0;
}
