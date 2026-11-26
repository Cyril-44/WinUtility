#include<bits/stdc++.h>
using namespace std;
int n,a[51111],q,l,r;
long long nnn;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	nnn=1;
	for(int i=1;i<=64;i++){
		nnn*=2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		int ans=sum;
		for(int i=1;i<=n;i++){
			ans=ans^((i*sum)%nnn);
		}
		cout<<ans;
	}
	
	return 0;
}
