#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,res;
bool f;
struct node{
	long long x,y;
}a[100005];
bool cmp(node s,node t){
	return s.x+s.y<t.x+t.y;
}
bool cmp1(node s,node t){
	return s.x<t.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	long long tmp1=a[1].x,tmp2=a[1].y;
	ans=res=(m/(tmp1+tmp2))*2;
	m%=(a[1].x+a[1].y);
	sort(a+1,a+n+1,cmp1);
	for(long long i=1;i<=n;i++){
		if(m<a[i].x){
			long long tmp=a[i].x-m;
			res-=(tmp/(tmp1+tmp2));
			m+=(tmp/(tmp1+tmp2))*(tmp1+tmp2);
			tmp%=(tmp1+tmp2);
			if(m+(f?tmp1:tmp2)>=a[i].x){
				m+=(f?tmp1:tmp2);
				f=!f;
				res--;
			}else{
				m+=(tmp1+tmp2);
				res-=2;
			}
			if(res<0) break;
		}
		m-=a[i].x;
		res++;
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
