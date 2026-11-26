#include<queue>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
struct node
{
	int x;
	int y;
};
node a[100100];
node b[100100];
int c[5];
bool cmp1(node x,node y)
{
	return x.x + x.y < y.x + y.y;
}
bool cmp2(node x,node y)
{
	return x.x < y.x;
}
struct Node
{
	int x;
	int id;
};
struct cmp3
{
	bool operator() (Node x,Node y)
	{
		return x.x > y.x;
	}
};
priority_queue<Node,vector<Node>,cmp3> q;
priority_queue<Node,vector<Node>,cmp3> p;
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	int i;
	int flag = 1;
	int mn1 = 1ll << 50;
	int mn2 = 1ll << 50;
	for(i = 1;i <= n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		b[i].x = a[i].x;
		b[i].y = a[i].y;
		if(a[i].x != a[i].y)	flag = 0;
		if(a[i].x < mn1)	mn1 = a[i].x;
		if(a[i].x + a[i].y < mn2)	mn2 = a[i].x + a[i].y;
	}
	if(flag)
	{
		printf("%lld",m/mn1);
		return 0;
	}
	sort(a + 1,a + 1 + n,cmp1);
	sort(b + 1,b + 1 + n,cmp2);
	int ans = 0;
	int aas = 0,mm = m;
	ans += m / mn2 * 2;
	aas = ans;
	m %= mn2;
	mm %= mn2;
	
	
	
	
	for(i = 1;i <= n;i++)
	{
		Node x;
		x.id = i;
		x.x = a[i].x;
		q.push(x);
	}
	int j = 1;
	c[1] = a[1].y;
	c[0] = a[1].x;
	for(i = 1;i <= n;i++)
	{
		Node z = q.top();
		int x = z.x;
		int id = z.id;
		q.pop();
		if(x > m)
		{
			if(m + c[j] < x)	break;
			m = m + c[j] - x;
			Node y;
			y.id = id;
			if(a[id].x == x)	y.x = a[id].y;
			else  y.x = a[id].x;
			q.push(y);
			j = !j;
		}
		else
		{
			ans++;
			m -= x;
			Node y;
			y.id = id;
			if(a[id].x == x)	y.x = a[id].y;
			else  y.x = a[id].x;
			q.push(y);
		}
	}
	
	for(i = 1;i <= n;i++)
	{
		Node x;
		x.id = i;
		x.x = a[i].x;
		p.push(x);
	}
	aas--;
	j = 0;
	c[1] = a[1].y;
	c[0] = a[1].x;
	for(i = 1;i <= n;i++)
	{
		Node z = p.top();
		int x = z.x;
		int id = z.id;
		p.pop();
		if(x > mm)
		{
			if(mm + c[j] < x)	break;
			mm = mm + c[j] - x;
			Node y;
			y.id = id;
			if(a[id].x == x)	y.x = a[id].y;
			else  y.x = a[id].x;
			p.push(y);
			j = !j;
		}
		else
		{
			aas++;
			mm -= x;
			Node y;
			y.id = id;
			if(a[id].x == x)	y.x = a[id].y;
			else  y.x = a[id].x;
			p.push(y);
		}
	}
	
	
	printf("%lld",max(aas,ans));
	return 0;
}
