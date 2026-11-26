#include<bits/stdc++.h>
using namespace std;
long long n,Q,a[100009],s[100009],ans[50009],L,R,p,cnt;
long long A(long long x){
	long long sum=1,a=2;
	while(x){
		if(x%2==1) sum*=a;
		a*=a,x/=2;
	}
	return sum;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n,p=A(31);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n*2;i++) s[i]=a[i]+s[i-1];
	cin>>Q;
	while(Q--){
		cin>>L>>R,ans[1]=s[L],cnt=ans[1];
		for(int i=2,j=L+1;i<=n;j++,i++) ans[i]=max(ans[i],s[j]-s[i-1]);
		for(int i=2;i<=n;i++) cnt=cnt^(ans[i]*i%p),ans[i]=0;
		cout<<cnt<<endl;
	}
	return 0;
}
