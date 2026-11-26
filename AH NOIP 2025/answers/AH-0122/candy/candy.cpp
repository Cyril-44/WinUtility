#include <bits/stdc++.h>
using namespace std;


int n,m,w[101][2],ans=0;
int f[101][101][2];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i][1],&w[i][0]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j][0]=max(f[i-1][j][1],f[i-1][j][0]);
			if(j-w[i][1]==0) f[i][j][1]=1;
			else if(j-w[i][1]>0){
				if(f[i][ j-w[i][1] ][0]>0) f[i][j][1]=max(f[i][j][1],f[i][ j-w[i][1] ][0]+1);
			}
			if(j-w[i][0]>0){
				if(f[i][ j-w[i][0] ][1]>0) f[i][j][0]=max(f[i][j][0],f[i][ j-w[i][0] ][1]+1);
			}
		}
	}
	ans=max(f[n][m][1],f[n][m][0]);
	printf("%d",ans);
	
	return 0;
}
