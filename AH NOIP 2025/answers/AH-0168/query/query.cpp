#include <bits/stdc++.h>
using namespace std;
__int128 mod;
long long a[100001],s[100001],b[5001][5001],sum[100001];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	//mod=18446744073709551616;
	memset(b,-0x7f,sizeof(b));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==1){
				b[i][j]=sum[j];
			}
			else{
				int k,kk;
				k=i+j-1;
				kk=i-j+1;
				if(k<=n){
					b[i][j]=max(b[i][j],sum[k]-sum[i-1]);
				}
				if(kk>=1){
					b[i][j]=max(b[i][j],sum[i]-sum[kk-1]);
				}
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//		cout<<b[3][i]<<" ";
	//	}
	int m;
	scanf("%d",&m);
	while(m--){
		memset(s,-0x7f,sizeof(s));
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=x;i<=y;i++){
			for(int j=1;j<=n;j++){
				s[j]=max(s[j],b[j][i]);
			}
		}
		//for(int i=1;i<=n;i++){
		//	cout<<s[i]<<" ";
		//}
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=(ans^(i*s[i]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
