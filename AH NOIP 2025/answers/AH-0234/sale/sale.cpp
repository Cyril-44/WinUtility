#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c,t,n,m,a[114514];
long long ssm;
int main(){
freopen("sale.in","r",stdin);
freopen("sale.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>c>>t;
if(c>=1&&c<=3){
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ss=pow(2,n);
        ss*=(t+c);
        ssm=(ss-1)*1919810+(ss+1)*114514;
        cout<<ssm%mod<<endl;
    }
}
else{
    int ss=t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        ss+=t;
        ssm=ss*(ss-1)*1919810+ss*(ss+1)*114514;
        cout<<ssm%mod<<endl;
    }
}
return 0;
}
/*
It surprised me that this is the last time for me to join the competion.
With only 190 left,can I go to my favourite university?
How I wish I could get 680 or more.
What a excited day,I completely work out just ONE question.
PEKIDS
*/
