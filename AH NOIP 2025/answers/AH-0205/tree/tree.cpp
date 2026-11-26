#include<bits/stdc++.h>
using namespace std;
int n,m,T,p[1001001];
vector<int> tree[8001];
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--){
        for(int i=0;i<=8000;i++) tree[i].clear();
        scanf("%d %d",&n,&m);
        for(int i=1;i<n;i++){
            scanf("%d",&p[i]);
            tree[p[i]].push_back(i);
        }
	}
	return 0;
}
