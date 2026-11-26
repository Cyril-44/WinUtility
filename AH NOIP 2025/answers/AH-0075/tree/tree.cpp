#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N = 8010;
int p[N];
vector<int> son[N];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			son[i].clear();
		}
		for(int i=2;i<=n;i++){
			scanf("%d",&p[i]);
			son[p[i]].push_back(i);
		}
		if(m == 2){
			int ans = 0,ms = 0;
			int len1 = son[1].size();
			for(int i=0;i<len1;i++){
				int v = son[1][i],lenv = son[v].size();
				ms = max(ms, lenv);
				ans += lenv + 2;
				if(lenv == 0) ans--;
			}
			ans += ms + 2;
			printf("%d\n",ans);
		}else{
			int ans = 0,ms = 0;
			int len1 = son[1].size();
			for(int i=0;i<len1;i++){
				int v = son[1][i],lenv = son[v].size();
				ms = max(ms, lenv);
				ans += lenv + 2;
				if(lenv == 0) ans--;
			}
			ans += ms + 2;
			printf("%d\n",ans + n);
		}
	}
	return 0;
}
