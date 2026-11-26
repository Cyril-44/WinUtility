#include<bits/stdc++.h>
using namespace std;
    int t,n,m,s;
    vector<int>g[4010];
    int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
		cin>>n>>m;
		s=0;
    for(int i=1;i<=4000;i++)g[i].clear();
    for(int i=1;i<=n-1;i++){
		int x;
		cin>>x;
		g[x].push_back(i+1);	
		if(x==1)s++;
	}
	int ma=0;
	for(int i=2;i<=n;i++){
		int hj=g[i].size();
		ma=max(ma,hj);
	}
	int p1=n+ma+1;
	int p2=(n-s-1)+3+2*s;
	int p4=s+(n-s-1)+s+(ma+2);
	int p3=s+(n-s-1)+1+(ma+s+1);
	int pk=((p1,p2),max(p3,p4));
	cout<<pk<<endl;
    }
    return 0;
}
