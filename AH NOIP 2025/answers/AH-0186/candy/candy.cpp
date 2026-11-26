#include<bits/stdc++.h>
using namespace std;
int n,m;
struct candy{
	int x,y;
	double v;
	int id;
}a[100005];
double minn=1000000009;
bool cmp(candy x,candy y){
	return x.x<y.x;
}
int ans,flag;
bool f=false;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	
		a[i].v=(1.0*a[i].x+a[i].y)/2;
		if(minn>a[i].v){
			minn=a[i].v;
			flag=i;
		}
	}
	
	if(a[flag].x<a[flag].y){		
		ans--;
		m+=a[flag].x;
		f=true;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].x<minn){
			ans++;
			m-=a[i].x;
			int t=a[i].x;
			a[i].x=a[i].y;
			a[i].y=t;
		}else{
			break;
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			if(a[i].id==flag){
				int t=a[i].x;
				a[i].x=a[i].y;
				a[i].y=t;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	while(1){
	
		if(m<minn*2){
			for(int i=1;i<=n;i++){
				if(m>=a[i].x){
					ans++;
					m-=a[i].x;
				}
			}
			cout<<ans;
			break;
		}
		m-=minn*2;
		ans+=2;
	}
	
	return 0;
}
