#include<bits/stdc++.h>
using namespace std;
int n;
long long m,mn,mnn;
long long ans,last;
struct candy{
	long long x,y;
}a[100005];
bool cmp(candy p,candy q){
	if(p.x!=q.x){
		return p.x<q.x;
	}
	return p.y<q.y;
}
bool f;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i==1||mn>a[i].x+a[i].y){
			mn=a[i].x+a[i].y;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].x+last<mn&&m>=a[i].x){
			m-=a[i].x;
			ans++;
			if(a[i].x+a[i].y==mn){
				if(!mnn){
					mnn=a[i].y;
				}else{
					mnn=min(mnn,a[i].y);
				}
			}else{
				last=a[i].x;
			}
		}else{
			if(a[i].x+a[i].y==mn){
				if(!mnn){
					mnn=a[i].x;
				}else{
					mnn=min(mnn,a[i].x);
				}
			}
		}
	}
	int ans1=ans,ans2=ans-1;
	int m1=m,m2=m+last;
	ans1+=2*(m1/mn);
	ans2+=2*(m2/mn);
	m1-=mn*(m1/mn);
	m2-=mn*(m2-mn);
	if(m1>=mnn){
		ans1++;
	}
	if(m2>=mnn){
		ans2++;
	}
	cout<<max(ans1,ans2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
