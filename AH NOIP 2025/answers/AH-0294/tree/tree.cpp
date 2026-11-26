#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>q[N];
int deep[N],fa[N],d[N];
priority_queue<int,vector<int>,greater<int> > Q1[N];
priority_queue<int>Q2[N];
void find(int x){
	if(x!=1&&(Q1[fa[x]].size())==0){
		d[x]=0;
		int t=x;
		while(t!=fa[t]){
			Q1[fa[t]].push(d[x]);
			Q2[fa[t]].push(d[x]);
			t=fa[t];
		}
	}
	else if(x!=1&&q[x].size()==0&&deep[x]==2){
		d[x]=0;
		int t=x;
		while(t!=1){
			Q1[fa[t]].push(d[x]);
			Q2[fa[t]].push(d[x]);
			t=fa[t];
		}
	}
	else if(x!=1){
		d[x]=Q2[fa[x]].top()+1;
		int t=x;
		while(t!=1){
			Q1[fa[t]].push(d[x]);
			Q2[fa[t]].push(d[x]);
			t=fa[t];
		}
	}
	else d[x]=Q2[1].top()+1;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	int t,x,n,m,ans=0,l=0;
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			while(Q1[i].size())Q1[i].pop(),Q2[i].pop();
		}
		l=0;
		ans=0;
		memset(fa,0,sizeof(fa));
		memset(d,0,sizeof(d));
		cin>>n>>m;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=2;i<=n;i++){
			cin>>x;fa[i]=x;
			q[x].push_back(i);
		}
		deep[1]=1;
		for(int i=1;i<=n;i++){
			for(int st:q[i]){
				deep[st]=deep[i]+1;
				l=max(l,deep[st]);
			}
		}
		
		for(int i=n;i>=1;i--){
			find(i);
		}
		for(int i=1;i<=n;i++){
			ans=ans+1+d[i];
		}
		cout<<ans<<'\n';
	}	
	return 0;
}
