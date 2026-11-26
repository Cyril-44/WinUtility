#include<bits/stdc++.h>
using namespace std;
int x[100001],y[100001],z[100001],a[100001],n,m,ans,fg;
int minz=1e5;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		if(minz>x[i]+y[i]){
			minz=x[i]+y[i];
			fg=i;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==0){
			if(minz>=2*x[i]){
				m-=x[i];
				ans++;
				a[i]=1;
			}
		}else{
			if(minz>=2*y[i]){
				m-=y[i];
				ans++;
				a[i]=0;
			}
		}
	}
	ans+=(m/minz)*2;
	m-=(m/minz)*minz;
	if(m>=0){
		for(int i=0;i<n;i++){
			if(a[i]==0)z[i]=x[i];
			if(a[i]==1)z[i]=y[i];
		}
		for(int j=0;j<n;j++){
			minz=1e5;	
			for(int i=0;i<n;i++){
				if(minz>=z[i]){
					minz=z[i];
					fg=i;
				}
			}
			z[fg]=1e5;
			if(m-minz>=0){
				m-=minz;
				ans++;
				if(m<minz)break;
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}
