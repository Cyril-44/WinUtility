#include<bits/stdc++.h>
using namespace std;
long long sum=0;
vector<int>v[1000005];
int t[1000005];
int n,m;
int fa;
int T;
int query(int x){
	if(v[x].size()==0){
		t[x]=1;
		return 1;
	}
	int s=0;
	for(int i=0;i<(int)v[x].size();i++){
		s+=query(v[x][i]);
	}
	t[x]=s+1;
	return s+1;
}
long long qsum(int x,bool op){
	if(v[x].size()==0)return 1;
	int maxid=0;
	long long s=0;
	for(int i=0;i<(int)v[x].size();i++){
		if(t[v[x][i]]>t[maxid]){
			maxid=v[x][i];
		}
	}
	for(int i=0;i<(int)v[x].size();i++){
		s+=qsum(v[x][i],0);
	}
	return t[maxid]+1+s;
}
int main(){
	freopen("tree4.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		memset(t,0,sizeof(t));
		cin>>n>>m;
		if(m==2){
			for(int i=2;i<=n;i++){
				cin>>fa;
				v[fa].push_back(i);
			}
			query(1);
			cout<<qsum(1,0)<<endl;
			for(int i=1;i<=n;i++){
				while(v[i].size())v[i].pop_back();
			}
		}
		else{
			cout<<(2*n-1)<<endl;
		}
	}
	return 0;
}
