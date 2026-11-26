#include<bits/stdc++.h>
using namespace std;
int x[114514];
int x1[114514];
int yy[114514];
int bj[114514];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;long long m; int ans=0;
	int mn=INT_MAX;
	cin>>n>>m;
	if(n>=5000){//AB
        for(int i=1;i<=n;i++){
            int xi,yi;
            scanf("%d%d",&xi,&yi);
            x[i]=xi;
            if(xi+yi<mn){
                mn=xi+yi;
            }
        }
        ans+=m/mn*2;
        m=m-mn*(m/mn);
        sort(x+1,x+n+1);
        for(int i=1;i<=n;i++){
            if(m-x[i]>=0){
                m=m-x[i];
                ans++;
            }else{
                break;
            }
        }
        cout<<ans;
	}else {
	    for(int i=1;i<=n;i++){
            cin>>x1[i]>>yy[i];
	    }
	   int ans=0;
        while(1){
            int mn=INT_MAX,minj;
            for(int i=1;i<=n;i++){
                int xx;
                if(bj[i]==0){
                    xx=x1[i];
                }else{
                    xx=yy[i];
                }
                if(xx<mn){
                    mn=xx;
                    minj=i;
                }
            }
            if(m>=mn){
                cout<<mn<<endl;
                m=m-mn;
                bj[minj]=1-bj[minj];
                ans++;
            }else{
                break;
            }
        }
        cout<<ans+1;
	}

	return 0;
}
