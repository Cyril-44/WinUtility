#include<bits/stdc++.h>
using namespace std;
long long n,m,u[100005];
struct can{
	long long x,y;
	long long h;
}a[100005];
int cnt=0;

struct pow{
	long long f[5]={0,0,0,0,0};
	int t=0;
}b[100005];

bool cmp(can p,can q){
	return p.x<q.x;
}
bool cmp2(can p,can q){
	return p.h<q.h;
}
void dfs(long long sum,int k){
	if(sum>m){
		k--;
		cnt=max(cnt,k);
		return ;
	}else if(sum==m){
		cnt=max(cnt,k);
		return ;
	}
	for(int i=1;i<=n;i++){
		dfs(sum+b[i].f[(++b[i].t)%2],k+1);
		b[i].t--;
	}
	return ;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool ok=1;
	bool r=1;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].h=a[i].x+a[i].y;
		if(a[i].x!=a[i].y) ok=0;
		if(a[i].x<a[i].y) r=0;
	}
	if(ok==1){
		sort(a+1,a+n+1,cmp);
		cout<<m/a[1].x;
	}else if(n==1){
		long long k=a[1].x;
		int t=1,ans=0;
		while(m>=k){
			m-=k;
			ans++;
			t++;
			if(t%2==0) k=a[1].y;
			else k=a[1].x;
		}
		cout<<ans<<endl;
	}else if(r==1){
		sort(a+1,a+n+1,cmp2);
		cnt=(m/a[1].h)*2;
		long long w=m%a[1].h;
		for(int i=1;i<=n;i++){
			u[i]=a[i].x;
		}
		sort(u+1,u+n+1);
		for(int i=1;i<=n;i++){
			if(w>=u[i]) w-=u[i],cnt++;
			else continue;
		}
		cout<<cnt<<endl;
	}else{
		for(int i=1;i<=n;i++){
			b[i].f[1]=a[i].x;
			b[i].f[0]=a[i].y;
		}
		dfs(0,0);
		cout<<cnt<<endl;
	}
	return 0;
}
