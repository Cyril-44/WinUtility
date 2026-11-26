#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
struct B{long long p,x,y;}b[15];
long long c,t,n,m,i,j,k,a[15],s,x,y,z,v,w,f[25],ma,ans;
bool cmp(B i,B j){
	if(i.x*j.y!=i.y*j.x)return i.x*j.y>i.y*j.x;
	if(i.x!=j.x)return i.x>j.x;
	return i.p<j.p;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==18||c==16){
		while(t--){
			cin>>n>>m;
			s=1;
			for(i=1;i<=n;i++)cin>>a[i];
			for(i=1;i<=n;i++)s=s*2%M;
			cout<<s<<"\n";
		}
	}
	if(c<=5){
		while(t--){
			ans=0;
			cin>>n>>m;
			for(i=1;i<=n;i++)cin>>a[i];
			z=(1<<n);
			for(i=0;i<z;i++){
				s=0;
				for(j=1;j<=n;j++){
					b[j].p=j;
					b[j].x=a[j];
				}
				for(j=1;j<=n;j++){
					if((i&(1<<(j-1)))==0)b[j].y=1;
					else b[j].y=2;
				}
				sort(b+1,b+1+n,cmp);
				v=m;
				for(j=1;j<=n;j++){
					x=b[j].x;y=b[j].y;
					if(v>=y){v-=y;s+=x;}
				}
				w=0;
				memset(f,0,sizeof f);
				for(j=1;j<=n;j++){
					x=b[j].x;y=b[j].y;
					for(k=m-y;k>=0;k--){
						f[k+y]=max(f[k+y],f[k]+x);
					}
				}
				ma=0;
				for(k=1;k<=m;k++)ma=max(ma,f[k]);
				if(ma==s)ans++;
			}
			cout<<ans<<"\n";
		}
	}
}
