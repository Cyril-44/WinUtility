#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
}a[100005];
int b[100005];
long long s[100005];
bool cmp(node a,node b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,k=1,pos;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i].x;
		if(s[i]<=m)pos=i;
	}
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++){
		int he=a[i].x+a[i].y;
		int q=upper_bound(b+1,b+k+1,a[i].y)-b-1;
		q=min(q,pos);
		sum=q+(m-s[q])/he*2;
		if((m-s[q])%he>=a[i].x)sum++;
		ans=max(ans,sum);
	//	printf("%d %lld\n",q,sum);
		//if(sum==80)printf("%d %d %d %d\n",i,a[i].x,a[i].y,q);

		b[++k]=a[i].x;
		b[k+1]=0x3f3f3f3f;
	}
	cout<<ans;
	return 0;
}
