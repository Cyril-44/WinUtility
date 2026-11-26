#include <bits/stdc++.h>
using namespace std;
int n;
long long m,cy[100010];
long long minc=100000000000010;
long long c[100010],costx=0;
struct Node{
	long long val;
	int id;
}cx[100010];
void mergesort(int l,int r){
	if(l==r) return ;
	
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(cx[i].val<cx[j].val) c[k++]=cx[i++].val;
		else c[k++]=cx[j++].val;
	}
	while(i<=mid) c[k++]=cx[i++].val;
	while(j<=r) c[k++]=cx[j++].val;
	for(int x=l;x<=r;x++){
		cx[x].val=c[x];
	}
	
	return ;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	int tot=1;
	long long prex=0;
	for(int i=1;i<=n;i++){
		cin>>cx[i].val>>cy[i];
		cx[i].id=0;
		if((cx[i].val+cy[i]<minc)||(cx[i].val+cy[i]==minc&&cx[i].val>prex)){
			minc=cx[i].val+cy[i];
			++tot;
			cx[i].id=tot;
			prex=cx[i].val;
		}
	}
	int cnt=0;
	mergesort(1,n);
	for(int i=0;i<=n;i++){
		costx+=cx[i].val;
		if(costx>m) break;
		int tmp2=(m-costx)/minc;
		cnt=max(cnt,tmp2*2+i);
	}
	cout<<cnt;
	return 0;
}
