#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll n,m;
struct candy{
	int x,y,cnt;
	int add(){
		if(cnt%2)return y;
		return x;
	}
	int addother(){
		if(add()==y)return x;
		return y;
	}
};
vector<candy>a;
namespace taska{
	bool cmp(candy a,candy b){return a.x<b.x;}
	void solve(){
		sort(a.begin(),a.end(),cmp);
		ll ans=0;
		int index=0;
		while(index<n){
			if(m<a[index].x){
				index++;
				continue;
			}
			m-=a[index].x;
			ans++;
		}
		cout<<ans<<endl;
	}
}
namespace task1{
	void solve(){
		int ans=0;
		while(m>0){
			if(ans%2)m-=a[0].x;
			else m-=a[0].y;
			++ans;
		}
		if(m<0)ans--;
		cout<<ans<<endl;
	}
}
namespace task2{
	void solve(){
		int sum,maxnum=0;
		for(int i=0;i<=m;++i){
			for(int j=0;j<=m;++j){
				sum=(a[0].x+a[0].y)*i/2;
				sum+=(a[1].x+a[1].y)*j/2;
				if(i%2)sum+=a[0].x;
				if(j%2)sum+=a[1].x;
				if(sum>m)continue;
				maxnum=max(maxnum,i+j);
			}
		}
		cout<<maxnum;
	}
}
namespace task3{
	void solve(){
		int sum,maxnum=0;
		for(int i=0;i<=m;++i){
			for(int j=0;j<=m;++j){
				for(int k=0;k<=m;++k){
					sum=(a[0].x+a[0].y)*i/2;
					sum+=(a[1].x+a[1].y)*j/2;
					sum+=(a[2].x+a[2].y)*k/2;
					if(i%2)sum+=a[0].x;
					if(j%2)sum+=a[1].x;
					if(k%2)sum+=a[2].x;
					if(sum>m)continue;
					maxnum=max(maxnum,i+j+k);
				}
			}
		}
		cout<<maxnum;
	}

}
namespace tanxin{
	bool cmp(candy a,candy b){
		int x,_x,y,_y;
		x=a.add();_x=a.addother();
		y=b.add();_y=b.addother();
		if(x!=y)return x<y;
		else return  _x<_y;
	}
	void solve(){
		while(m>0){
			int minindex=0;
			for(int i=0;i<n;++i){
				if(cmp(a[i],a[minindex]))minindex=i;
			}
			m-=a[minindex].add();
			a[minindex].cnt++;
		}
		ll ans=0;
		for(int i=0;i<n;++i){
			ans+=a[i].cnt;
		}
		if(m<0)ans--;
		cout<<ans;
	}
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	bool flag=true;
	for(int i=0;i<n;++i){
		cin>>a[i].x>>a[i].y;
		a[i].cnt=0;
		if(a[i].x!=a[i].y)flag=false;
	}
	if(flag)taska::solve();
	else if(n==1)task1::solve();
	else if(n==2)task2::solve();
	else if(n==3)task3::solve();
	else tanxin::solve();
	return 0;
}
