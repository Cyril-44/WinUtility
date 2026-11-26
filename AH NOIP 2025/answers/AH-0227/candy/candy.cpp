#include<bits/stdc++.h>
using namespace std;
int m,n,Amn=1100000000,x[100010],y[100010],sum,cnt[100010],t,f,temp[100010];
bool A=1,f1;
void n10dfs(int k,int v)
{
	if(f==1) return;
	if(v>=m)
	{
		if(v==m) sum=max(sum,k-1);
		else sum=max(sum,k-2);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f==1) break;
		cnt[i]++;
		t++;
		if(t==3000000)
		{
			f=1;
			break;
		}
		if(cnt[i]%2!=0){temp[k]=x[i]; n10dfs(k+1,v+x[i]);} 
		else{temp[k]=y[i]; n10dfs(k+1,v+y[i]);} 
		cnt[i]--;
	}
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		if(x[i]!=y[i]) A=0;
		Amn=min(Amn,x[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++) if(x[i]+y[i]>x[j]+y[j])
		{
			swap(x[i],x[j]);
			swap(y[i],y[j]);
		}
	}
	if(A) cout<<m/Amn;
	else if(n==1)
	{
		sum=m/(x[1]+y[1])*2,m%=x[1]+y[1];
		if(m>=x[1]) sum++;
		cout<<sum;
	}
	else
	{
		n10dfs(1,0);
		cout<<sum<<endl;
	}
	return 0;
}
