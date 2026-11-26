#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n, m, fa[8005], ocnt, k[8005], h[8005], out [8005], cnt;
struct node{
    int u, v, w, p;
}e[8005];
void add(int u, int v){
    e[++cnt].p=h[u];e[cnt].v=v;h[u]=cnt;
    out[u]++;
    return;
}
void init(){
	for (int i=1; i<=n; i++){
		if(!out[i]){
			k[i]=1;
		}
	}
	return;
}
int dfs(int u){
	//cout << e[u].v << ' ';
	if (!out[u]){
		return k[u];
	}
	for (int i=h[u]; i; i=e[i].p){
		int v=e[i].v;
		if (k[v]){
			k[u]=max(k[u], k[v]+1);
		}
		else k[u]=max(k[u], dfs(v)+1);
	}
	return k[u];
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        scanf("%d%d", &n, &m);
        cnt=0;
        memset(h, 0, sizeof(h));
        memset(out, 0, sizeof(out));
        memset(k, 0, sizeof(k));
        add(0, 1);
        for (int i=2; i<=n; i++){
            scanf("%d", &fa[i]);
            add(fa[i], i);
        }
        init();
        k[0]=dfs(1)+1;
        k[0]=0;
        for (int i=1; i<=n; i++){
			k[0]+=k[i];
		}
		printf("%d\n", k[0]);
	}
    return 0;
}
/*
2
5 2
1 1 2 2
7 2
1 1 2 2 2 3
*/
