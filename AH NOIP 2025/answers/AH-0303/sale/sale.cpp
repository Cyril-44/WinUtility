#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m=0;
long long a[100100],b[100100],c2[100100]={0};
long long i,j,cnt,left;
long long spr[100100]={0};
long long answer(long long a){
    return a%998244353;
}
long long cmp(long long a,long long b){
    return a>b;
}
int main(){
freopen("sale.in","r",stdin);
freopen("sale.out","w",stdout);
cin>>c>>t;
while(t--){
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
        b[i]=a[i];
        c2[i]=a[i]/2;
        spr[i]=min(b[i],c2[i]);
	}
    sort(spr+0,spr+n,cmp);
    for(j=0;j<n;j++){
        if(m-a[j]>0){
            cnt++;
        }
    }
}
cout<<answer(spr[0]);
return 0;
}
