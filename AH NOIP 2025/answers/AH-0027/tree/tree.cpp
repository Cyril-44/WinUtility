#include<bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
const int N=4e3+10;
int n,m,t;
vector<int> e[N];
int sz[N];
void df(int nw,int fa){
	for(auto i : e[nw]){
		if(i==fa)continue;
		df(i,nw);
		sz[nw]+=sz[i];
	}
	sz[nw]++;
}
int val[N],tott=0,pd[N][N],anss=0;
void df2(int nw,int fa){
	pd[nw][val[nw]]=1;
	for(auto i : e[nw]){
		df2(i,nw);
		forr(j,1,n)pd[nw][j]|=pd[i][j];
	}
	forr(i,0,n){
		if(pd[nw][i]==0){
			tott+=i;break;
		}
	}
}
void df3(int dp){
	if(dp>n){
		tott=0;df2(1,1);
		anss=max(anss,tott);
		forr(i,1,n)forr(j,0,n)pd[i][j]=0;
		return ;
	}
	forr(i,0,n)val[dp]=i,df3(dp+1);
}
void work(){
	cin>>n>>m;
	forr(i,2,n){
		int x;cin>>x;
		e[x].push_back(i);
		e[i].push_back(x);
	}
	if(m==2){
		df(1,0);
		int tot=0,mx=0;
		for(auto i : e[1]){
			if(sz[i]==1)tot++;
			else tot+=sz[i]+1;
			mx=max(mx,sz[i]);
		}
		tot+=mx+1;
		cout<<tot<<endl;
	}else{
		anss=0;
		df3(1);
		cout<<anss<<endl;
	}
	forr(i,1,n)e[i].clear(),sz[i]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--)work();
	return 0;
}
