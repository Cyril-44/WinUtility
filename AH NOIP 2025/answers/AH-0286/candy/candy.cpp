#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=INT_MIN,mi=INT_MAX,tx,ty,num;
struct cd
{
	int x,y,s;
} a[100005];
int cmp(cd b,cd c)
{
	return b.x<c.x;
}
long long check(long long d,int x){
	long long numa=(m-d)/mi*2+x,sd=m-((m-d)/mi*mi+d);
	int ta=tx,f=0;
	while(sd>=ta){
		numa++;
		sd-=ta;
		if(f==0){
			ta=ty;
			f=1;
		}
		else {
			ta=tx;
			f=0;
		}
	}
	return numa;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	int t;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].s=a[i].x+a[i].y;
		if(a[i].s<mi){
			mi=a[i].s;
			tx=a[i].x;
			ty=a[i].y;
			t=i;
		}
	}
	a[t].s=INT_MAX;
	a[t].x=INT_MAX;
	a[t].y=INT_MAX;
	sum=max(sum,check(0,0));
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		num+=a[i].x;
		sum=max(sum,check(num,i));
	}
	cout<<sum;
	return 0;
}
