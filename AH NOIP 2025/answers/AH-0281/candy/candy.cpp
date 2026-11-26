#include<bits/stdc++.h>
using namespace std;
struct S{
	int x,y;
}a[100005];
bool cmp(S a,S b)
{
	return a.x<b.x;
}
int n;
long long maxx=0,ans=0;
void dfs(long long m,int num)
{
	if(num>n)return;
	if(m<0)return;
	long long money=m;
	for(int i=0;;i++)
	{
		if(i%2==0){
			m=m-(a[num].x+a[num].y)*(i/2);
			ans+=i;
		}
		else{
			m=m-(a[num].x+a[num].y)*(i/2)-a[num].x;
			ans+=i;
		}		
		if(m<0)return;
		dfs(m,num+1);	
		//cout<<m<<' '<<num<<' '<<i<<endl;
		//cout<<ans<<endl;
		maxx=max(maxx,ans);
		m=money;
		ans=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long m;
	cin>>n>>m;
	bool A=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		if(a[i].x!=a[i].y)A=false;
	}
	if(A==true){
		sort(a+1,a+1+n,cmp);
		cout<<m/a[1].x<<endl;
	}
	else{
		dfs(m,1);
		cout<<maxx<<endl;
	}
	return 0;
}
