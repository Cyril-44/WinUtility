#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<math.h>
using namespace std;
long long i,j,q,n,qz=0;
long long a[100100];
long long l[100100];
long long r[100100];
long long sum;
int main(){
freopen("query.in","r",stdin);
freopen("query.out","w",stdout);
cin>>n;
for(i=1;i<=n;i++){
    cin>>a[i];
}
cin>>q;
for(j=0;j<q;j++){
    cin>>l[j]>>r[j];
    if(l[j]>r[j]){
        return 0;
    }
        sum=a[j]*a[j+1];
}
for(j=0;j<q;j++){
    cout<<(sum*j)*(pow(2,64))<<endl;
}
return 0;
}
