#include<bits/stdc++.h>
using namespace std;
const int MAXN=8005;

int t;
int n,m;
int ans,cnt;
int f[MAXN];
bool used[MAXN];
bool flag[MAXN];
vector<int> e[MAXN];

void dfs(int x, int sum){
	if(x==f[x]) return ;
	ans+=sum;
	dfs(f[x],sum);
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	scanf("%d" ,&t);
	while(t--){
		memset(f,0,sizeof(f));
		memset(used,0,sizeof(used));
		memset(flag,0,sizeof(flag));
		memset(e,0,sizeof(e));
		cnt=ans=0;

		scanf("%d%d" ,&n,&m);
		for(int i=2; i<=n; i++){
			int x;
			scanf("%d" ,&x);
			e[x].push_back(i);
			f[i]=x;
		}
		f[1]=1;
		cnt=n;
		for(int i=1; i<=n; i++){
			if(e[i].size()==0) flag[i]=1;
		}
		for(int i=1; i<=n; i++){
			if(e[i].size()==0){
				cnt--;
				if(used[i]==1) continue;
				int fa=f[i];
				ans++;
				int sum1=0;
				for(int j=0; j<e[fa].size(); j++){
					if(flag[e[fa][j]]==1) sum1++,used[e[fa][j]]=1;
				}
				dfs(i,sum1);
			}
		}
		printf("%d\n" ,ans+cnt);	
	}
}
//!noip@Nov29,2025:dream
