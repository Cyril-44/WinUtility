#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+25;
struct node{
	ll x,y;
	bool operator < (const node& u)const{
		if(x!=u.x)return x>u.x;
		return y>u.y;
	}
}a[N];
bool cmp(node u,node v){
	if(u.x!=v.x)return u.x<v.x;
	return u.y<v.y;
}
//priority_queue<node> q;
ll val[N];
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m,i,mi=1e18,ans=0,num=0,sum=0;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y,mi=min(mi,a[i].x+a[i].y);
		val[i]=a[i].x;
	}
	sort(val+1,val+n+1);num=n;
	while(num>=1&&val[num]>=mi)num--;
	for(i=0;i<=num;i++){
		sum+=val[i];
		if(sum>m)break;
		ll t=i+(m-sum)/mi*2;
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}

	/*for(i=1;i<=n&&a[i].x<=ha;i++){
		if(a[i].x==ha&&a[i].y==ha)break;
		if(m<a[i].x)break;
		m-=a[i].x;ans++;
		swap(a[i].x,a[i].y);
	}
	ans+=(m/mi)*2;m%=mi;
	for(i=1;i<=n;i++)q.push(a[i]);
	while(m>=q.top().x){
		ans++,m-=q.top().x;
		node t=q.top();q.pop();
		swap(t.x,t.y);q.push(t);
	}*/
