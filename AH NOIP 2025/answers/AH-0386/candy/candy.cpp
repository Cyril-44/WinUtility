#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	long long x,y;
}a[100001],b[100001];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,mn=1;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if((a[mn].x+a[mn].y>a[i].x+a[i].y) || (a[mn].x+a[mn].y==a[i].x+a[i].y && a[i].x<a[mn].x)) mn=i;
	}
	long long ans=0,ans1=0,mx=0;
	int op=0;
	ans=ans1=m/(a[mn].x+a[mn].y)*2;
	m%=(a[mn].x+a[mn].y);
	for(int i=1;i<=n;i++){
		if(i==mn) continue;
		if(m>=a[i].x){
			m-=a[i].x;
			ans++;
		}else{
			if(op==0){
				m+=a[mn].y;
				ans--;
				op=1;
			}else{
				m+=a[mn].x;
				ans--;
				op=0;
			}
			if(m>=a[i].x){
				ans++;
				m-=a[i].x;
			}else i--;
		}
		mx=max(mx,ans);
		if(ans<0) break;
	}
	cout<<max(mx,ans1);
	return 0;
}
