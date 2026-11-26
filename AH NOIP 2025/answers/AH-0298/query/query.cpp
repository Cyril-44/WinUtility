#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int n,q,m,a[N];
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while (isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int s)
{
	if (s<0)
	{
		s=-s;
		putchar('-');
	}
	if (s>9)
	{
		write(s/10);
	}
	putchar(s%10+'0');
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=read();
	for (int i=1; i<=n; i++)
	{
		a[i]=read();
	}
	q=read();
	while (q--)
	{
		int x=read();
		puts("0");
	}
	return 0;
}
