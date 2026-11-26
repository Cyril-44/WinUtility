#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n,T,m;
int v[N];
struct Edge{
	int v,nxt;
}e[N<<1];
int head[N],en=0;
void add(int u,int v){
	e[++en].v=v;
	e[en].nxt=head[u];
	head[u]=en;
}
int Sta[N][N];
int dfs(int u,int fa){
	int ans=0;
	for(int j=head[u];j;j=e[j].nxt){
		int v=e[j].v;
		if(v!=fa){
			ans+=dfs(v,u);
			for(int l=0;l<n;l++){
				Sta[u][l]|=Sta[v][l];
			}
		}
	}
	Sta[u][v[u]]=1;
	int ad=0;
	while(Sta[u][ad]){	
		ad++;
	}
	ans+=ad;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		en=0;
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		for(int i=2;i<=n;i++){
			int fa;
			cin>>fa;
			add(i,fa);
			add(fa,i);
		}
		int f=1;
		for(int i=1;i<=n;i++){
			f*=n;
		}
		//cout<<f<<endl;
		int ans=0;
		for(int sta=0;sta<f;sta++){
			//cout<<sta<<endl;
			int tsta=sta;
			for(int j=0;j<n;j++){
				v[j+1]=sta%n;
				sta/=n;
				for(int l=0;l<n;l++){
					Sta[j+1][l]=0;
				}
			}
			sta=tsta;
			//cout<<sta<<endl;
			ans=max(ans,dfs(1,0));
		}
		cout<<ans<<endl;
	}
	return 0;
}
