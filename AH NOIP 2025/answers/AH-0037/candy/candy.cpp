#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define req(i,a,b) for(int i=a;i>=b;--i)
const int N=100005;
int n;
ll m;
struct node{
	int x,y;
}t[N];
bool cmp(node a,node b){
	return (a.x+a.y==b.x+b.y)?(a.x<b.x):(a.x+a.y<b.x+b.y);
}
bool cmp2(node a,node b){
	return a.x<b.x;
}
ll work(ll left,ll ct){
	ll res=0,tims=0;
	// cout<<"left:"<<left<<'\n';
	// rep(i,2,10)cout<<t[i].x<<' '<<t[i].y<<'\n';;
	// cout<<"ct:"<<ct<<'\n';
	ll now=left,ans=0;
	for(int i=2;i<=n;++i){
		if(t[i].x<=now){
			now-=t[i].x;++res;
		} else {
			while(tims<ct&&t[i].x>now)++tims,now+=t[1].x+t[1].y,res-=2;
			if(now>=t[i].x) ++res,now-=t[i].x;
			else return max(ans,res);
		} ans=max(ans,res);
	}
	return ans;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)cin>>t[i].x>>t[i].y;
	sort(t+1,t+n+1,cmp2);
	
	ll now=m;ll ans=0;
	rep(i,1,n){
		if(now>=t[i].x)now-=t[i].x,++ans;
		else break;
	}  if(ans==0){cout<<0<<'\n';return 0;}
	// cout
	sort(t+1,t+n+1,cmp);
	sort(t+2,t+n+1,cmp2);
	ll num=t[1].x+t[1].y;
	ll cnt=m/num;
	ll left=m-cnt*num;
	ans=max(ans,cnt*2ll+work(left,cnt));
	// cout<<t[1].x<<' ';
	// cout<<left<<' '<<work(left,cnt)<<'\n';
	num=t[1].x+t[1].y;
	cnt=(m-t[1].x)/num;
	left=m-t[1].x-num*cnt;
	ans=max(ans,cnt*2ll+1+work(left,cnt));
	// cout<<left<<' '<<work(left,cnt)<<'\n';
	cout<<ans<<'\n';
	return 0;
}
