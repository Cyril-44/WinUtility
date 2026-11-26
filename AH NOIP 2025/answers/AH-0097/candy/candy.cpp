#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
struct candy256{
	int x,y;
}a[N],b[N];
int n,m;
bool cmp1(candy256 u,candy256 v){
	return u.x+u.y<v.x+v.y;
}
bool cmp2(candy256 u,candy256 v){
	return u.x<v.x;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		b[i].x=a[i].x;
	}
	sort(a+1,a+n+1,cmp1);
	b[n+1].x=a[1].x+a[1].y,b[n+1].y=1;
	sort(b+1,b+n+2,cmp2);
	int cnt=m/(a[1].x+a[1].y)*2,sum=0;
	// cout<<cnt<<" "<<a[1].x<<" "<<a[1].y<<endl;
	for(int i=1;i<=n+1;i++){
		if(b[i].y==0){
			sum+=b[i].x;
			cnt=max(cnt,i+(m-sum)/(a[1].x+a[1].y)*2);
		}
		else{
			break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}