#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,x[2][N],h[N],jiou[N],ml[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=N;i++)ml[i]=m;
	for(int i=1;i<=n;i++){
		cin>>x[0][i]>>x[1][i];
		h[i]=x[0][i]+x[1][i];
	}
	int k=0;
	while(m>=0){
		int ans=INT_MAX,zb;
		for(int i=1;i<=n;i++){
			int t=x[jiou[i]][i];
			if(t<ans){
				zb=i;
				ans=t;
			}
			else if(t==ans){
				int z1=1-jiou[zb],z2=1-jiou[i];
				if(x[z1][zb]>=x[z2][i])zb=i;
			}
		}
		jiou[zb]=1-jiou[zb];
		if(m-ans<0)break;
		m-=ans;k++;
	}
	//k1;
	int k2=0;
	int zb=0;
	for(int i=1;i<=n;i++){
		int g=ml[i]/h[i];
		if(g*2>=k2){
			k2=g*2;
			zb=i;
		}
		else if(g*2==k2&&(ml[i]%h[i]-x[0][zb])>=x[0][i]){
			k2+=1;
			ml[i]-=x[0][zb];
		}
		if(g*2==k2&&ml[i]%h[i]>=x[0][i])k2+=1;
	}
	//k2
	int cnt=max(k,k2);
	cout<<cnt;
	return 0;
}
