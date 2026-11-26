#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
bool flag=0;
struct sweet
{
	int x,y;
	int xysum;
};
sweet s[100005];

bool mycmp(sweet a,sweet b)
{
	if(a.xysum==b.xysum) 
	{
		if(a.x!=b.x) return (a.x<b.x);
		else return(a.y<b.y);
	}
	else return (a.xysum<b.xysum);
}

void manba(int c,int money)
{
	if(money==0||c>=n)
	{
		if(flag==0)
		{
			flag=1;cout<<ans;
		}
		return ;
		
	}
	int add;
	add=money/s[c].xysum;
	if (add==0)
	{
		if(money<s[c].x)
		{
			manba(c+1,money);
		    return ;
		}
		else
		{
			money-=s[c].x;ans++;
			manba(c+1,money);
		}
		
	}
	money-=add*s[c].xysum;
	if(money>s[c].x)
	{
		if(s[c].x==s[c+1].x)
		{
			if(s[c+1].x>s[c+1].y)
			{
				ans+=add*2;
			    manba(c+1,money);
			}
			else
			{
				ans+=(add*2+1);
			    money-=s[c].x;
			    manba(c+1,money);
			}
		}
		else
		{
			if(s[c].x>s[c+1].x)
			{
				ans+=add*2;
			    manba(c+1,money);
			}
			else
			{
				ans+=(add*2+1);
			    money-=s[c].x;
			    manba(c+1,money);
			}
		}
	}
	else
	{
		if(s[c].y==s[c+1].x)
		{
			if(s[c+1].x>s[c+1].y)
			{
				ans+=(add*2-1);
			    money+=s[c].y;
			    manba(c+1,money);
			}
			else
			{
				ans+=add*2;
			    manba(c+1,money);
			}
		}
		else 
		{
			if(s[c].y>s[c+1].x)
	    	{
		    	ans+=(add*2-1);
			    money+=s[c].y;
			    manba(c+1,money);
		    }
		    else
		    {
				ans+=add*2;
			    manba(c+1,money);
			}
			
		}
	}
	return ;
}
bool checkstrange()
{
	for(int i=0;i<n;i++) 
	{
		if(s[i].x!=s[i].y) return 0;
	}
	return 1;
}
void strange()
{
	int c,add;
	ans=0;c=0;add=0;
	while(m>0&&c<n) 
	{
		add=m/s[c].x;
		m-=add*s[c].x;
		ans+=add;
		c++;
	}
	cout<<ans;
	return ;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) 
	{
		cin>>s[i].x>>s[i].y;
		s[i].xysum=s[i].x+s[i].y;
	}
	sort(s+0,s+n,mycmp);
	if(checkstrange()==1)
	{
		strange();
		return 0;
	}
	ans=0;
	manba(0,m);
	return 0;
}
