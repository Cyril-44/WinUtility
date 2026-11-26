#include<bits/stdc++.h>
using namespace std;
int n,m,a[8005],ans,mm,v[8005],t[8005];
vector<int> k[8005];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		ans=0;
		memset(a,0,sizeof(a));
		memset(k,0,sizeof(k));
		memset(t,0,sizeof(t));
		memset(v,0,sizeof(v));
		for(int i=2;i<=n;i++){
			cin>>a[i];
			k[a[i]].push_back(i);
		}
		for(int i=2;i<=n;i++){
			if(k[i].empty()){
				if(t[a[i]]==0) ans++;
				v[i]=t[a[i]];
				t[a[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				int f=k[j].size();
				for(int h=0;h<f;h++){
					v[j]=max(v[j],v[k[j][h]]+1);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!k[i].empty()){
				ans+=v[i]+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

