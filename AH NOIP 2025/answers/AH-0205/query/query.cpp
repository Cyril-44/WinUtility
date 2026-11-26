#include<bits/stdc++.h>
using namespace std;
uint64_t n;
int a[1001001],T,K;
int64_t sum[1001001];
uint64_t Fantastic(int L,int R){
    uint64_t S=1;
    int64_t k;
    for(int i=1;i<=n;i++){
        k=LONG_LONG_MIN;
        for(int l=L;l<=R;l++)
            for(int j=max(i-l+1,1);j<=i;j++)
                k=max(sum[j+l-1]-sum[j-1],k);
        if(i==1) S=(k*i)%ULONG_LONG_MAX;
        else S=S^((k*i)%ULONG_LONG_MAX);
    }
    return S;
}
int L,R;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
	}
    cin>>T;
    while(T--){
        scanf("%d %d",&L,&R);
        cout<<Fantastic(L,R)<<endl;
    }
	return 0;
}
