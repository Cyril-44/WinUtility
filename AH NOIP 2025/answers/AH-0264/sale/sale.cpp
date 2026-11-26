#include <bits/stdc++.h>
using namespace std;
int n,c,t,m;
int ans,k,mi;
const int mod=998244353;
struct sweet
{
	int a,w,xjb,bh;
}s[5500];
bool mycmp(sweet x,sweet y)
{
	if(x.a!=y.a) return (x.a>y.a);
	else return (x.bh<y.bh);
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	if(c==18)
	{
		for(int i=1;i<=t;i++)
		{
			n=0;m=0;
			cin>>n>>m;
		    for(int j=0;j<n;j++) cin>>s[j].a;
		    k=n-m;mi=1;
		    for(int j=1;j<=k;j++) 
		    {
		    	mi*=2;
		    	if(mi>=mod) mi=mi%mod;
		    }
		    mi+=1;mi=mi%mod;
		    cout<<mi;
		    
		}
		return 0;
	}
	if(c==7||c==9||c==14||c==15)
	{
		for(int i=1;i<=t;i++)
		{   
			memset(s,0,sizeof(s));
			n=0;m=0;ans=0;
			cin>>n>>m;
			
		    for(int j=0;j<n;j++) 
		    {
		    	cin>>s[j].a;s[j].bh=j;
		    }
		    sort(s+0,s+n,mycmp);
		    
		    k=1; 
		    while(s[k].a*2>s[0].a) k++;
		    k=n-k;mi=1;
		    for(int j=1;j<=k;j++) 
		    {
		    	mi*=2;
		    	if(mi>=mod) mi=mi%mod;
		    }
		    ans+=mi;
		    k=n-2;mi=1;
		    for(int j=1;j<=k;j++) 
		    {
		    	mi*=2;
		    	if(mi>=mod) mi=mi%mod;
		    }
		    ans+=mi;
		    ans=ans%mod;
		    cout<<ans;
		    return 0;
		    
		}
		return 0;
	}
	
	
	for(int i=1;i<=t;i++)
	{
		memset(s,0,sizeof(s));
		cin>>n>>m;
		for(int j=0;j<n;j++) 
		{
			cin>>s[j].a;s[j].bh=j;
		}
		
	}
	
	return 0;
}
