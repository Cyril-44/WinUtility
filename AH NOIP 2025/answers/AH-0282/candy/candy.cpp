#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m,w,c;
	int num,g,f;
	cin>>n>>m;
	int x[100001],y[100001],k[100001],t[100001];
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		t[i]=x[i];
		k[i]=x[i]+y[i];
		if(i>=2){
			if(k[i-1]>k[i]){
				w=k[i];
			}
			else{
				k[i]=k[i-1];
			}
			for(int j=i;j>1;j--){
				if(t[j-1]>t[j]){
					c=t[j-1];
					t[j-1]=t[j];
					t[j]=c;
				}
			}
		}
	}
	g=m%w;
	f=m/w;
	num=2*f;
	for(int i=1;i<=n;i++){
		if(g<t[i]){
			cout<<num;
			break;
		}
		else{
			g-=t[i];
			num++;
			continue;
		}
	}
	return 0;
}
