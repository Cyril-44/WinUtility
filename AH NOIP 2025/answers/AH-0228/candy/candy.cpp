#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long ans,m,n,mincost,miny,sum=0;
struct Candy{
	int costx,costy,cost,id;
}c[N];
struct Cx{
	int x,id;
}x[N];
bool ok[N];
bool cmp(Candy x,Candy y){
	return x.cost<y.cost;
}
bool cmp1(Cx x,Cx y){
	return x.x<y.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i].costx>>c[i].costy;
		c[i].cost=c[i].costx+c[i].costy;
		c[i].id=i;
		if(c[i].costx<c[i].costy){
			sum++;
			x[sum].x=c[i].costx;
		}
	}
	sort(c+1,c+1+n,cmp);
	sort(x+1,x+1+sum,cmp1);
	for(int i=1;i<=sum&&x[i].x*2<=c[1].cost;i++){
		m-=x[i].x;
		ans++;
		ok[x[i].id]=1;
	}
	if(m){
		ans+=(m/c[1].cost)*2;
		m%=c[1].cost;
		if(m){
			if(ok[c[1].id]){
				if(m>=c[1].costy)ans++;
			}else if(m>=c[1].costx)ans++;
		}
	}
	cout<<ans;
}
