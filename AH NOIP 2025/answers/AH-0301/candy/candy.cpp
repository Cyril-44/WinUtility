#include<bits/stdc++.h>
using namespace std;
long long n,m,c[10001][3],s;
bool b[10001];
int a[10001],ta;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    c[0][0]=INT_MAX;
    c[0][1]=INT_MAX;
    long long t=0;
    for(int i=1;i<=n;i++){
        cin>>c[i][1]>>c[i][2];
        c[i][0]=(c[i][1]+c[i][2])/2.0;
        if(c[i][0]<c[t][0])t=i;
        if(c[i][0]=c[t][0])if(c[i][1]>c[t][1])t=i;
    }
    int tt=0;
    for(int j=1;j<=n;j++){
        tt=0;
        for(int i=1;i<=n;i++){
            if(b[i]==1)continue;
            if(c[i][1]<=c[tt][1])tt=i;
        }
        if(c[tt][1]>c[t][0])break;
        ta++;
        a[ta]=tt;
        b[tt]=1;
    }
    for(int i=1;i<=ta;i++){
        m-=c[a[i]][1];
        s+=1;
    }
    while(m>=2*c[t][0]){
        m-=2*c[t][0];
        s+=2;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==1)continue;
        if(c[i][1]<=m){s++;break;}
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
