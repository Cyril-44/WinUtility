#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const long long MAXN=5005,Mod=998244353;
int c,T,n,m,a[MAXN];
long long C[MAXN][MAXN],cnt;
inline bool cmp(int x,int y){return x>y;}
inline long long pow(long long int x,long long int y)
{
	long long res=1;
	while(y)
	{
		if(y&1)(res*=x)%=Mod;
		x=x*x%Mod,y>>=1;
	}return res;
}
signed main()
{
	//froepen("sale3.in","r",stdin);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d %d",&c,&T);
	for(int i=0;i<=5000;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	//~ for(int i=0;i<=6;i++){
		//~ for(int j=0;j<=i;j++)printf("%d ",C[i][j]);
		//~ puts("");
	//~ }
	while(T--)
	{
		cnt=0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		sort(a+1,a+1+n,cmp);
		for(int i=1,p;i<=n;i++){
			for(p=i-1;p>=1&&a[p]<(a[i]<<1);p--);
			if(a[(++p)]==a[i])continue;
			int r=i;
			for(int j=p;j<i;j++)
			{
				while((a[r+1]*2>a[j]||a[r+1]+a[i]>=a[j])&&r<n)
				{
					r++;
				}
				if(m-i<0)break;
				//~ printf("%d %d %d %d %d %lld\n",i,j,p,m-i,r,cnt);
				(cnt+=C[p-1][m-i]*pow(2,n-r))%=Mod;
			}
		}
		//~ printf("%lld ",cnt);
		printf("%lld\n",(pow(2,n)-cnt+Mod)%Mod);
		
	}
	return 0;
}
/*
0 1
5 3
7 5 3 1 2
*/
