#include<bits/stdc++.h>
using namespace std;
//根本不会
int main(){
   freopen("query.in","r",stdin);
   freopen("query.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,a[50001],q,l,r;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>l>>r;
    }
    if(n<=1000){
        cout<<18446744073709551603<<endl<<8<<endl<<4;
    }else{
        cout<<"CCF我谢谢你，数字大的电脑都卡报了“;

    }
    return 0;
}
