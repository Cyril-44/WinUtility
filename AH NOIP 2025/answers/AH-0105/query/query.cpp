#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=3010;

int n;
int a[N];
LL s[N];
LL w[N][N];
LL k[N];

void init()
{
	for(int len=1;len<=n;len++)
	{
		for(int l=1;l+len<=n;l++)
		{
			int r=l+len;
			LL t=s[r]-s[l-1];
			for(int i=l;i<=r;i++)
			{
				w[len][i]=max(w[len][i],t);
			}
		}
	}
}

__int128 qmi(int a,int k)
{
	__int128 res=1;
	while(k)
	{
		if(k&1)res=(1ll*res*a);
		a=(1ll*a*a);
		k>>=1;
	}
	return res;
}

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}

	init();

	int q;
	cin>>q;
	while(q--)
	{
		memset(k,0,sizeof k);
		int L,R;
		scanf("%d%d",&L,&R);
		for(int len=L;len<=R;len++)
		{
			for(int id=1;id<=n;id++)
			{
				k[id]=max(k[id],w[len][id]);
			}
		}

		LL res=0;
		for(int i=1;i<=n;i++)
		{
			res=res^((k[i])*i);
		}
		cout<<res<<endl;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
