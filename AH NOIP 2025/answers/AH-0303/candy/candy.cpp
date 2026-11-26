#include<bits/stdc++.h>
using namespace std;
long long n,m=0;
long long i,j=0;
long long a[100100][3]={0};
long long b[100100][3]={0};
long long tot,ans,minn1,minn2,minn3=0;
int minn(int a,int b){
	//if(a<=b) return a;
	return a<=b;
}
int main(){
freopen("candy.in","r",stdin);
freopen("candy.out","w",stdout);
cin>>n>>m;
for(i=0;i<n;i++){
    cin>>a[i][0]>>a[i][1];
    b[i][0]=a[i][0];
    b[i][1]=a[i][1];
    minn1=minn(a[j][0],a[j+1][0]);
}
for(j=0;j<n;j++){
	//the first time,it's an even(?) number
	//minn1=minn(a[j][0],a[j][1]);
	tot=tot+minn1;
	ans=1;
	while(tot<=m){
		ans++;
		//because of we've counted one time before,so the firet time should be the 2th(odd).
		if(ans%2==0){
			tot=tot+minn(b[j][0],b[j+1][0]);
		}
		else if(ans%2==1){
			tot=tot+minn(b[j][1],b[j+1][1]);
		}
	}
}
cout<<ans;
return 0;
}
/*
2 10
4 1
3 3
*/
