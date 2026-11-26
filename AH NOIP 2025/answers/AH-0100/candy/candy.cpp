#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;

int n;
struct node{
	int id;
	long long x,y,he;	
}a[MAXN],b[MAXN];
bool used[MAXN];
long long m;
long long ans;
long long c[MAXN];

bool cmp(node x, node y){
	if(x.he!=y.he) return x.he<y.he;
	return x.x<y.x;
}
bool cmp1(node x, node y){
	if(x.x!=y.x) return x.x<y.x;
	return x.he>y.he;
}

void solve(){
	long long ans=0;
	ans=m/a[1].x;
	printf("%Illd\n" ,ans);
}

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	scanf("%d%Illd" ,&n,&m);
	bool flag=0;
	for(int i=1; i<=n; i++){
		scanf("%Illd%Illd" ,&a[i].x,&a[i].y);
		if(a[i].x!=a[i].y) flag=1;
		b[i].id=a[i].id=i;
		b[i].he=a[i].he=a[i].x+a[i].y;
		b[i].x=a[i].x; b[i].y=a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp1);
	
	if(flag==0){
		solve();
		return 0;
	}

	for(int i=1; i<=n; i+=2){
		if(b[i].x+b[i+1].x<a[1].he && m>=b[i].x+b[i+1].x && b[i].he!=a[1].he && b[i+1].he!=a[1].he){
			ans+=2;
			m-=b[i].x+b[i+1].x;
			used[b[i].id]=used[b[i+1].id]=1;
		}
		else{
			break;
		}
	}
	
	long long cnt=1ll*max(1ll*0,m/a[1].he);
	ans+=cnt*2;
	m-=cnt*a[1].he;
	for(int i=1; i<=n; i++){
		if(used[a[i].id]==0){
			c[i]=a[i].x;
		}
		else c[i]=a[i].y;
	}
	sort(c+1,c+n+1);
	
	for(int i=1; i<=n; i++){
		if(c[i]<=m){
			m-=c[i];
			ans++;
		}
	}
	printf("%Illd\n" ,ans);
}
//!noip@Nov29,2025:dream
