#include<bits/stdc++.h>
using namespace std;
long long n,m,b[100010],i,ans,mi=1000000000000000000,z,p,k;
struct A{
	long long x,y;
}a[100010];
bool cmp(A i,A j){
	if(i.x!=j.y)return i.x<j.y;
	return i.x<j.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		z=a[i].x+a[i].y;
	}
	sort(a+1,a+1+n,cmp);
	while(1){
		for(i=1;i<=n;i++){
			if(b[i]%2==0)z=a[i].x;else z=a[i].y;
			if(z<=mi){mi=z;p=i;}
		}
		if(m-mi>=0){
			m-=mi;
			ans++;
			b[p]++;
			mi=1000000000000000000;
		}
		else break;
	}
	cout<<ans;
	return 0;
}
