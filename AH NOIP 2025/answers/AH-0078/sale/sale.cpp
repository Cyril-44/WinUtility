#include <bits/stdc++.h>
#define maxn 5000+10
using namespace std;
int f[maxn][maxn];
int a[maxn];
struct node{
	int v;
	double w;
};
node b[maxn];
bool cmp(node a,node b){ return a.w<b.w;}
bool chos[maxn];
int ans=0;
int n,m;
bool check(){
	for(int i=1;i<=n;i++) {
		if(chos[i]==1){
			b[i].v=2;
			b[i].w=a[i]*1.0/2;
		}else{
			b[i].v=1;
			b[i].w=a[i]*1.0;
		}
	}
	sort(b+1,b+1+n,cmp);
	int k=m;
	for(int i=n;i>=1;i--){
		if(k==1 && b[i].v==2){
			if(b[i].w * 2<= b[i+1].w+b[i-1].w) return 1;
			else return 0;
		}
		k-=b[i].v;
		if(k==0) return 1;
	}
	return 1;
}
void dfs(int pos){
	if(pos==n+1){
		if(check()) ans++;
		return ;
	}
	chos[pos]=0;
	dfs(pos+1);
	chos[pos]=1;
	dfs(pos+1);
	return ;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int test_number,t;
	scanf("%d%d",&test_number,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		//candy's numver & coin's number
		//int k=m/2;
		//max cuting number
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		dfs(1);
		printf("%d\n",ans);
		/*
		for(int i=1;i<=n;i++) f[n+1][i]=1;
		for(int i=n;i>=1;i--){//pos
			for(int j=n-m+1+n-i;j>=n-m+1;j--){//the first bo chosen
				//[n-m+1,n-m+1+(n-i)
				if(i<j){// not be chosen at all
					f[i][j]=f[i+1][j]+f[i+1][j];
				}else{// if don't cut,in the chosen
					double c=a[i]*1.0/2;
					int to=upper_bound(a,a+1+n,c)-a;
					to++;
					// the last position that <=c
					f[i][j]=f[i+1][j]; // don't cut
					if(to<j-1){ f[i][j]+=f[i+1][j-1];
					}else if(to==j-1){
						if(c<=(double)(a[j]+a[j-2])/2)
							f[i][j]+=f[i+1][j+2];
					}else f[i][j]+=f[i+1][j-1];
				}
				
			}
		}
		int ans=0;
		for(int j=n-m+1+n-1;j>=n-m+1;j--) ans=max(ans,f[1][j]);
		printf("%d",ans);
		* 
		* if(j==0){
					f[i][j]=f[i+1][j];
					continue;
				}
				double c=a[i]*1.0/2;
				int to=upper_bound(a,a+1+n,c)-a;
				// the last position that <=c
				int pos=n-(m-j)+1; //the first ont that be chosen
				if(to==pos){
					if((double)a[pos]/2<=(double)(a[pos+1]+a[pos-1])/2)
						f[i][j]=f[i+1][j]*2;
				}else if(to<pos){ 
					f[i][j]=f[i+1][j]*2;
				}else f[i][j]=f[i+1][max(0,j-1)]+f[i+1][j];
				
				
				if(to<j-1){ f[i][j]=f[i+1][j]+f[i+1][j];
				}else if(to==j-1){
					if((double)a[to]/2<=(double)(a[j+1]+a[j-1])/2)
						f[i][j]=f[i+1][j]*2;
					else f[i][j]=f[i+1][j];
				}else f[i][j]=f[i+1][j-1]+f[i+1][j];
				
				if(j==to+1){
						if(c<=(double)(a[j]+a[j-2])/2)
							f[i][j]=f[i+1][j]+f[i+1][j];
						else f[i][j]=f[i+1][j];
					}else if(j<to+1){
						f[i][j]=f[i+1][j]+f[i+1][j+1];
					}else{
						f[i][j]=f[i+1][j-1]+f[i+1][j];
					}
		* */
	}
	return 0;
}
