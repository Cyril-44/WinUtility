#include<bits/stdc++.h>
using namespace std;
int t,n,m,fa[8005],mn[8005],mx[8005],nn[8005],nxt,ans,jih[8005][8005],anss,typ[8005],mxtyp;
vector<int> vec[8005];
int dfsqh(int idx){
	int ret=0;
	for(int i=0;i<vec[idx].size();i++)
		ret=max(ret,dfsqh(vec[idx][i])+1);
	return ret;
}
void dfsqm(int idx,int m,int mm){
	mn[idx]=m;mx[idx]=mm;
	for(int i=0;i<vec[idx].size();i++)
		dfsqm(vec[idx][i],m-1,mm-1);
}
void dfs2(int idx){
	jih[idx][nn[idx]]=1;
	for(int i=0;i<vec[idx].size();i++){
		dfs2(vec[idx][i]);
		for(int j=0;j<=mx[vec[idx][i]];j++)
			jih[idx][j]|=jih[vec[idx][i]][j];
	}
	for(int i=0;i<=mx[idx]+1;i++)
		if(jih[idx][i]==0){
			anss+=i;
			break;
		}
}
void dfs(int idx){
	if(idx==n+1){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=mx[i];j++)
				jih[i][j]=0;
		}
		anss=0;
		dfs2(1);
		ans=max(ans,anss);
		return ;
	}
	int nt=mx[idx];
	if(fa[idx]<idx&&idx!=1)
		nt=min(nt,nn[fa[idx]]-1);
	for(int i=mn[idx];i<=nt;i++){
		nn[idx]=i;
		dfs(idx+1);
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++)
			for(int j=0;j<=n+1;j++)
				jih[i][j]=0;
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			vec[i].clear();
		}
		for(int i=2;i<=n;i++){
			cin>>fa[i];
			vec[fa[i]].push_back(i);
		}
		m=dfsqh(1);
		if(m!=2){
			dfsqm(1,m,n-1);
			dfs(1);
			cout<<ans<<'\n';
		}else if(m==2){
			mxtyp=0;
			for(int i=2;i<=n;i++){
				typ[i]=vec[i].size();
				mxtyp=max(mxtyp,typ[i]+2);
				ans++;
				if(typ[i]!=0)
					ans++;
			}
			cout<<ans+mxtyp<<'\n';
		}else if(m==1){
			cout<<vec[1].size()+2<<'\n';
		}
	}
	return 0;
}
