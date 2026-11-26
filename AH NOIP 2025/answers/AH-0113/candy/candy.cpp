#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c,id;
}a[N];
int A[N];
bool cmp(node a,node b)
{
	if(a.c==b.c){
		if(a.a==b.a)return a.b<b.b;
		return a.a<b.a;
	}
	return a.c<b.c;
}
int col(int x)
{
	if(x)return a[1].b;
	return a[1].a;
}
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
		a[i].c=a[i].a+a[i].b;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	int c=0;
	for(int i=1;i<=n;i++){
		if(a[i].a!=a[1].a||a[i].b!=a[1].b){
			c++;
			A[c]=a[i].a;
		}
	}
	sort(A+1,A+1+c);
	int ans=0;
	bool id=1;
	ans=m/a[1].c*2;
	m%=a[1].c;
	if(m>=a[1].a){
		ans++;
		m-=a[1].a;
		id=0;
	}
	int t=1;
	while(m-A[t]>0){
		ans++;
		m-=A[t];
		t++;
	}
	int ma=0;
	int c1=0,c2=col(id),x=1,s=0;
	for(int i=t;i<=c;i++){
		c1+=A[i];
		s++;
		if(c1>c2){
			ma=max(ma,s-1-x);
			x++;
			id=!id;
			c2+=col(id);
		}
	}
	if(x==1)ans+=s-1;
	cout<<ans+ma;
}
