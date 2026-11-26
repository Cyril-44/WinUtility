#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[5010],i,j,u,prize1,prize2,x,w1,w2,ans,cnt,flag=1,o;
string k="";
struct A{
	long long x,y;
}p[5010];
struct B{
	long long zhi,jia,id,u2;
}q[5010];
bool cmp(B i,B j){
	if(i.zhi!=j.zhi)return i.zhi>j.zhi;
	else if(i.jia!=j.jia)return i.jia>j.jia;
	return i.id<j.id;
}
struct C{
	long long zhi2,jia2;
}b[5010];
bool bmp(C i,C j){
	return i.jia2>j.jia2;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	for(i=1;i<=t;i++){
		cin>>n>>m;
		flag=1;
		prize1=prize2=0;
		cnt=0;
		w1=w2=m;
		for(j=1;j<=n;j++){
			cin>>a[j];
			q[j].jia=a[j];
			b[j].jia2=a[j];
			q[j].id=j;
			p[j].x=a[j]/1;
			p[j].y=a[j]/2;
		}
		for(j=0;j<n;j++)k[j]='1';
		while(1){
			for(j=0;j<n;j++){
				u=k[j]-'0';
				q[j+1].u2=u;
				if(u==1)q[j+1].zhi=b[j+1].zhi2=p[j+1].x;
				else q[j+1].zhi=b[j+1].zhi2=p[j+1].y;
			}
			sort(q+1,q+1+n,cmp);
			sort(b+1,b+1+n,bmp);
			for(j=1;j<=n;j++){
				if(w1-=q[j].zhi>=q[j].u2){
					w1-=q[j].zhi;
					prize1+=q[j].jia;
				}
				if(w2-b[j].zhi2>=0){
					w2-=b[j].zhi2;
					prize2+=b[j].jia2;
				}
			}
			if(prize1>=prize2)ans++;
			if(flag==1){
				if(cnt%2!=0){k[n-1]='2';cnt++;}
				else{
					k[n-1]='1';cnt++;
					for(j=n-2;j>=0;j--){
						if(k[j]=='2')k[j]='1';
						else if(k[j]=='1'){k[j]='2';break;}
					}
				}
				for(j=0;j<n;j++)if(k[j]!='1')break;
				if(j==n)flag=2;
			}
			else if(flag==2){
				if(cnt%2!=0){k[n-1]='1';cnt++;}
				else{
					k[n-1]='2';cnt++;
					for(j=n-2;j>=0;j--){
						if(k[j]=='1')k[j]='2';
						else if(k[j]=='2'){k[j]='1';break;}
					}
				}	
			}
			for(j=1;j<n-1;j++)if(k[j]!='1')break;
			if(k[0]=='2'&&k[n-1]=='2'&&j==n-1)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
