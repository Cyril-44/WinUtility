#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5+5;
ll a[N],b[N],n,m,ans,x=INT_MAX;
struct node{
	ll a,b;
}s[N];
bool cmp1(node a,node b){
	return a.a+a.b<b.a+b.b;
}
bool cmp2(node a,node b){
	return a.a<b.a;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		x=min(x,s[i].a+s[i].b);
	}
	sort(s+1,s+1+n,cmp2);
	s[n+1].a=INT_MAX;
	for(int i=1;i<=n;i++){
		if(s[i].a*2>=x)break;
		if(s[i+1].a*2>=x&&m%x<s[i].a)break;
		m-=s[i].a,ans++;
		swap(s[i].a,s[i].b);
	}
	ll k=m/x;
	m-=k*x,ans+=2*k;
	sort(s+1,s+1+n,cmp2);
	for(int i=1;i<=n;i++){
		if(s[i].a<=m)ans++,m-=s[i].a;
		else break;
	}
	cout<<ans;
    return 0;
}
