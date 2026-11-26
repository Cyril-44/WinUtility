#include<bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001],c[100001],d[100001];
long long m,r=0;
void dg(long long y,long long sum){
	for(int i=1;i<=n;i++){
		if(c[i]<=y){
			swap(c[i],d[i]);
			dg(y-d[i],sum+1);
		}
		else{
			r=max(r,sum);
			return;
		}
	}
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	int o=1,s=100000000;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i]=a[i],d[i]=b[i];
		if(a[i]!=b[i]) o=0;
		s=min(s,a[i]);
	}
	if(o==1){
		cout<<int(m/s);
	}
	else{
		if(n==1){
			int ans=0;
			while(1){
				if(m>=a[1]){
					ans++;
					m-=a[1];
					if(m>=b[1]){
						ans++;
						m-=b[1];
					}
					else break;
				}
				else break;
			}
			cout<<ans;
		}
		else{
			dg(m,0);
			cout<<r;
		}
	}
    return 0;
}
