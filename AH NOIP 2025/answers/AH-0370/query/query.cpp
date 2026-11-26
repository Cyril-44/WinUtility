#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
long long n,q,i,len,j,x,s[N],l,r,t,y,a[N],k[N],ma,ans;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x;
		s[i]=s[i-1]+x;
	}
	cin>>q;
	while(q--){
		cin>>l>>r;
		for(i=1;i<=n;i++)a[i]=k[i]=-1e15;
		for(i=1;i<=n;i++){
			for(len=l;len<=r;len++){
				j=i+len-1;
				if(j>n)break;
				a[j]=s[j]-s[i-1];
			}
			ma=-1e15;
			for(j=min(i+r-1,n);j>=i;j--){
				ma=max(a[j],ma);
				k[j]=max(k[j],ma);
			}
		}
		ans=0;
		for(i=1;i<=n;i++){
			ans=ans^(i*k[i]);
		}
		if(ans>0)cout<<ans<<"\n";
		else cout<<(unsigned long long)(ans+(1<<64))<<"\n";
	}
}
