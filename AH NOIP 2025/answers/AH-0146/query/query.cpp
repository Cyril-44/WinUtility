#include<bits/stdc++.h>
using namespace std;
long long a[50005],w[50005];
bool er[1000005];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	long long n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1,in,ax;i<=m;i++){
		for(int i=1;i<=n;i++){
			w[i]=-100000000000;
		}
		cin>>in>>ax;
		for(int j=1;j<=n;j++){
			for(int l=j-ax+1;l<=j;l++){
				for(int r=j;r<=j+ax-1;r++){
					if(r-l+1>=in&&r-l+1<=ax&&l>0&&r>0){
						long long sum=0;
						for(int k=l;k<=r;k++){
							sum+=a[k];
						}
						w[j]=max(w[j],sum);
					}
				}
			}
		}
		unsigned long long sum=1;
		int cnt1=1;
		for(long long j=1;j<=n;j++){
			w[j]=w[j]*j;
			if(w[j]<0)w[j]=-w[j];
			int cnt=1;
			while(w[j]!=0){
				if(w[j]%2==er[cnt]){
					er[cnt]=0;
				}
				else{
					er[cnt]=1;
				}
				cnt++;cnt1=max(cnt1,cnt);
				w[j]/=2;
			}
		}
		long long s=2;
			for(int j=2;j<cnt1;j++){
				if(er[j]==1){
					sum*=s;
				}
				s*=s;
			}
		if(er[1]==1)sum+=1;
		cout<<sum<<endl;
	}
	return 0;
}
