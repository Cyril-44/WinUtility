#include<bits/stdc++.h>
using namespace std;
long long n,m,s=0,i,j,ans=-99999999;
struct CD
{
	long long a,b,c;
}cd[100005];
bool cmp1(CD aa,CD bb)
{
	return aa.c<bb.c;
}
bool cmp2(CD aa,CD bb)
{
	return aa.a<bb.a;
}
int main()
{
freopen("candy.in","r",stdin);
freopen("candy.out","w",stdout);
cin>>n>>m;
long long t=m;
for(i=1;i<=n;i++)
{
	cin>>cd[i].a>>cd[i].b;
cd[i].c=cd[i].a+cd[i].b;
}
sort(cd+1,cd+1+n,cmp1);
s+=(m/cd[1].c)*2,m-=(s/2)*cd[1].c;
long long s1[s+1],m1[s+1],ss=s/2;
for(i=1;i<=ss;i++)s1[i]=0,m1[i]=t;
for(i=1;i<=ss;i++)s1[i]=(m1[i]/cd[1].c-i)*2,m1[i]-=(s1[i]/2)*cd[1].c;
sort(cd+1,cd+1+n,cmp2);
for(i=1;i<=n;i++)
{
	if(m>=cd[i].a)s++,m-=cd[i].a;
	else break;
}
ans=s;
for(j=1;j<=ss;j++)
for(i=1;i<=n;i++)
{
	if(m1[j]>=cd[i].a)s1[j]++,m1[j]-=cd[i].a;
	else break;
}
sort(s1+1,s1+1+ss);
cout<<max(s1[ss],s);
//for(i=1;i<=ss;i++)if(s1[i]>ans)ans=s1[i];
//cout<<ans;
return 0;
}
//!noip@Nov29,2025:dream
