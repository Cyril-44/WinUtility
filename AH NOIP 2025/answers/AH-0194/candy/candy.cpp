#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,ans;
bool vis[100005];
struct node{
	long long x,y,id;
}a[100005];
bool cmp(node a,node b){
	if(a.x+a.y!=b.x+b.y)return a.x+a.y<b.x+b.y;
	return a.x<b.x;
}
bool cmp2(node a,node b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	long long c=a[1].x+a[1].y,p=a[1].x,q=a[1].y,id=a[1].id,sum=0;
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n;i++){
        sum+=a[i].x;
		if(m<=sum)break;
		ans=max(ans,(m-sum)/c*2+i);
	}
	ans=max(ans,m/c*2);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
