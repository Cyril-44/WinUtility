/*
Correct strategy:
- if M mod 2 = 1 then choose #1(w = 1)
- compare #1(w = 2) with [#1(w = 1) + #2(w = 1)] --- (X) 
- repeat X until M spent
Greedy is wrong if:
- in the last round of X
- 2 * #1(w = 1) > #1(w = 2) > [#1(w = 1) + #2(w = 1)]
- hereinafter: 2 * B > A > B + C
Algorithm:
- enumerate B and C
- use two-pointer to find valid A interval
- contribution: C(M - id(A) - 1, id(B) - 2) * power(2, N - id(C))
- final answer: power(2, N) - sum(contribution)
- O(N^2) time, O(N^2) memory
- WARNING: M can be 1; C can be NULL
*/
#include <bits/stdc++.h>
using namespace std;
int x[5012],C[5012][5012],p2[5012];
const int P=998244353;
inline int cc(int l,int r,int x)
{
	if(l>r||l>x||r<0) return 0;
	if(r>x) r=x;
	if(l<=0) return C[x][r];
	int res=C[x][r]-C[x][l-1];
	if(res<0) res+=P;
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	p2[0]=1;
	for(int i=1;i<=5011;i++)
	{
		p2[i]=p2[i-1]*2;
		if(p2[i]>=P) p2[i]-=P;
	}
	for(int i=0;i<=5011;i++)
	{
		C[i][0]=1;
		C[i][i]=1;
	}
	for(int i=2;i<=5011;i++)
		for(int j=1;j<=i-1;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>=P) C[i][j]-=P;
		}
	for(int i=0;i<=5011;i++)
		for(int j=1;j<=5011;j++)
		{
			C[i][j]+=C[i][j-1];
			if(C[i][j]>=P) C[i][j]-=P;
		}
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=n+2;i++)
			x[i]=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		sort(x+1,x+n+1,greater<int>());
		int ans=p2[n];
		if(m==1||m==2*n-1)
		{
			cout<<ans<<endl;
			continue;
		}
		for(int b=2;b<=n;b++)
		{
			int al=1;
			while(al<b&&2*x[b]<=x[al]) al++;
			if(al==b) continue;
			int ar=al-1;
			for(int c=b+1;c<=n+1;c++)
			{
				while(ar<=b-2&&x[ar+1]>x[b]+x[c]) ar++;
				ans-=1ll*cc(m-ar-1,m-al-1,b-2)*p2[max(n-c,0)]%P;
				if(ans<=0) ans+=P;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
// 08:40 - 10:10, samples passed (693 ms), 100 points
