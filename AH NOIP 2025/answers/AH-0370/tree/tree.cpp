#include<bits/stdc++.h>
using namespace std;
int t,n,m,i,u,s[8005],c,ma,h;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		h=1;
		memset(s,0,sizeof s);
		for(i=2;i<=n;i++){
			cin>>u;
			if(u!=1)h=2;
			s[u]++;
		}
		c=ma=0;
		for(i=2;i<=n;i++){
			if(s[i])c=c+s[i]+1;
			ma=max(ma,s[i]);
		}
		if(h==2)cout<<c+ma+1+s[1]+1<<"\n";
		else cout<<s[1]+1<<"\n";
	}
}
