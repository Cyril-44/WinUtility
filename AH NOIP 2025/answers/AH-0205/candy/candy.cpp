#include<bits/stdc++.h>
using namespace std;
int n,m,a[100101][2];
bool F[100101],fl;
map<int,int> dp;
int minn=INT_MAX;
int DFS(int sum){
    if(sum==0) return 0;
    int cnt=0,t;
    for(int i=1;i<=n;i++){
            if(sum-a[i][F[i]]>=0){
            t=sum-a[i][F[i]];
            F[i]=!F[i];
            cnt=max(cnt,DFS(t)+1);
            F[i]=!F[i];
        }
    }
    return cnt;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
        if(a[i][0]!=a[i][1]) fl=1;
        minn=min(a[i][0],minn);
    }
    if(!fl){
        cout<<m/minn;
        return 0;
    }
	cout<<DFS(m);
	return 0;
}
