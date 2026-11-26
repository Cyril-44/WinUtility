#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int n1=1e5+5;
const int INF=0x3f3f3f3f;
int n,mmin=INF;
ll m,ans1,ans,mm,ttt;
int w[3][n1],tw[3][n1];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%I64d",&n,&m);
	mm=m;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[1][i],&w[2][i]);
		if(w[1][i]==w[2][i]) ttt++;
		tw[1][i]=w[1][i];
		tw[2][i]=w[2][i];
		tw[0][i]=w[0][i]=w[1][i]+w[2][i];
		mmin=min(w[0][i],mmin);
	}
	if(ttt==n){
		while(m){
			int di=1;
			for(int i=2;i<=n;i++)
				if(w[1][di]>w[1][i])
					di=i;
			if(m<w[1][di]) break;
			int t=m/w[1][di];
			m-=t*w[1][di];
			ans+=t;
		}
		printf("%I64d\n",ans);
		return 0;
	}
	if(m>=1e6){
		while(m){
			int di=1;
			for(int i=2;i<=n;i++){
				if(w[1][di]>w[1][i]){
					di=i;
					continue;
				}
				if(w[1][di]==w[1][i])
					if(w[2][di]>w[2][i])
						di=i;
			}
			if(m<w[1][di]) break;
			m-=w[1][di];
			ans++;
			swap(w[1][di],w[2][di]);
		}
	}
	else{
		for(int k=0;k<=mm/mmin+1;k++){
			ans1=0;
			for(int i=1;i<=n;i++){
				w[0][i]=tw[0][i];
				w[1][i]=tw[1][i];
				w[2][i]=tw[2][i];
			}
			while(m>k*mmin){
				int di=1;
				for(int i=2;i<=n;i++)
					if(w[0][di]>w[0][i])
						di=i;
				if(m<w[0][di]) break;
				m-=w[0][di];
				ans1+=2;
			}
			while(m){
				int di=1;
				for(int i=2;i<=n;i++){
					if(w[1][di]>w[1][i]){
						di=i;
						continue;
					}
					if(w[1][di]==w[1][i])
						if(w[2][di]>w[2][i])
							di=i;
				}
				if(m<w[1][di]) break;
				m-=w[1][di];
				ans1++;
				swap(w[1][di],w[2][di]);
			}
			ans=max(ans,ans1);
			m=mm;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
