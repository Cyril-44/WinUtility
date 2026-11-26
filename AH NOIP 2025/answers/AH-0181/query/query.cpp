#include<bits/stdc++.h>
using namespace std;
int num[50010],sum[50010];
int n,q,r,l;
unsigned long long ans;
struct maxn{
	int m,ld,rd;
}now[50010];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+num[i];
	}
	cin>>q;
	for(int i=0;i<q;i++){
		for(int j=1;j<=n;j++)
			now[j].m=-1000000000;
		ans=0;
		cin>>l>>r;
		for(int j=1;j<=n-l+1;j++){
			for(int k=l;k<=min(r,n-j+1);k++){
				if(now[j].m<sum[j+k-1]-sum[j-1]){
					now[j].m=sum[j+k-1]-sum[j-1];
					now[j].rd=j+k-1;
					now[j].ld=j;
				}
			}
			if(now[j-1].rd>=j&&now[j-1].m>now[j].m)
				now[j]=now[j-1];
		}
		for(int j=n;j>=l;j--){
			for(int k=l;k<=min(r,j);k++){
				if(now[j].m<sum[j]-sum[j-k]){
					now[j].m=sum[j]-sum[j-k];
					now[j].rd=j;
					now[j].ld=j-k+1;
				}
			}
			if(now[j+1].ld<=j&&now[j+1].m>now[j].m)
				now[j]=now[j+1];
		}
		for(int j=1;j<=n;j++){
			unsigned long long mid=now[j].m*j;
			ans^=mid;
		}
		cout<<ans<<endl;
	}
	return 0;
}
