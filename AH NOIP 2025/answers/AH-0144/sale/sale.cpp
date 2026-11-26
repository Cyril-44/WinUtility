#include <bits/stdc++.h>
using namespace std;
const long long N=998244353;
struct node{
	long long a,w;
	int ii;
};
int C,T;
int n,m;
long long ans;
vector <node> A;
long long a10[5005],a20[5005];int a11,a21;
bool cmp (node x,node y)
{
	double d1=x.a/x.w*1.0,d2=y.a/y.w*1.0;
	if (d1==d2)
	{
		if (x.a==y.a) return x.ii<y.ii;
		return x.a>y.a;
	}
	return d1>d2;
}
bool cmp1 (long long x,long long y){return x>y;}
void dfs(int x)
{
	if (x==n)
	{
		vector <node> B=A;
		sort(B.begin(),B.end(),cmp);
		long long sum1=0,sum2=0,M=m;
		for (node X : B)
		{
			//cout<<X.a<<' '<<X.w<<' ';
			if (M>=X.w)
			{
				sum1+=X.a;
				M-=X.w;
			}
		}
		//cout<<'\n';
		M=m;
		long long a1[5005],a2[5005];
		for (int i=1;i<=a11;i++) a1[i]=a10[i];
		for (int i=1;i<=a21;i++) a2[i]=a20[i];
		sort(a1+1,a1+1+a11,cmp1);sort(a2+1,a2+1+a21,cmp1);
		bool flag=true;
		for (int i=1,j=1;M>0 && flag;)
		{
			flag=false;
			if (j>a21 && i<=a11)
			{
				M--;sum2+=a1[i];i++;flag=true;
				//cout<<sum2<<'\n';
				//cout<<"a";
			}
			else if (i>a11 && j<=a21 && M>=2)
			{
				M-=2;sum2+=a2[j];j++;flag=true;
			}
			else if (a1[i]>a2[j])
			{
				M--;sum2+=a1[i];i++;flag=true;
			}
			else if (i<=a11-1 && M>=2 && a1[i+1]+a1[i]>=a2[j])
			{
				//cout<<a1[i+1]<<' '<<i<<'\n';
				M-=2;sum2+=a1[i+1]+a1[i];i+=2;flag=true;
				//cout<<'b';
			}
			else if (M>=2)
			{
				
				M-=2;sum2+=a2[j];j++;flag=true;
				//cout<<'c';
			}
			else if (M==1 && i<=a11)
			{
				M--;sum2+=a1[i];i++;flag=true;
			}
		}
		if (sum1==sum2) ans++;
		//cout<<sum1<<' '<<sum2<<'\n';
		ans%=N;
		return;
	}
	A[x].w=1;
	a10[++a11]=A[x].a;
	dfs(x+1);
	a11--;
	A[x].w=2;
	a20[++a21]=A[x].a;
	dfs(x+1);
	a21--;
	return;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>C>>T;
	while (T--)
	{
		cin>>n>>m;
		A.clear();
		for (int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			node NUM;
			NUM.a=a;
			NUM.ii=i;
			A.push_back(NUM);
		}
		ans=a11=a21=0;
//if (m==2)
//{
		
		//continue;
//}
		dfs(0);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
3 2
1 3 5
*/
