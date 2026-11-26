#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
struct code{
	int p1,p2,ans;
}a[100010];
long long mi=INT_MAX;
int t1,t2;
long long s;
int b[100010],t;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].p1>>a[i].p2;
		a[i].ans=a[i].p1+a[i].p2;
		if(a[i].ans<mi){
			mi=a[i].ans;
			t1=a[i].p1;
			t2=a[i].p2;
		}
		b[i]=a[i].p1;
	}
	s=m/mi*2-1;
	m=m%mi+t2;
	b[n+1]=t2;
	sort(b+1,b+2+n);
	for(int i=1;i<=n;i++){
		if(b[i]==t1&&t==0){t=1;continue;}
		if(b[i]<=m){
			m-=b[i];
			s++;
		}
	}
	cout<<s;
}
