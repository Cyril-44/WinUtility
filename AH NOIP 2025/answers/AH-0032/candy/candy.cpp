#include<bits/stdc++.h>
using namespace std;
#define __MY_TEST__ 1
#define int long long
inline int read()
{
	int re=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while( isdigit(ch)) re=(re<<3)+(re<<1)+(ch^48),ch=getchar();
	return re*f;
}
const int N=1e5+5;
int x[N];
signed main(){
#if __MY_TEST__
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n=read(),m=read(),mt=1e16;
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read();
		mt=min(mt,a+b);
		x[i]=a;
	}
	sort(x+1,x+n+1);
	int sum=0,ans=m/mt*2;
	for(int i=1;i<=n;i++)
	{
		sum+=x[i];
		ans=max(ans,i+(m-sum)/mt*2);
	}
	cout<<ans<<endl;
}
