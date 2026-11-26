#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
long long m,ans=0;
long long minn=2000000000;
long long pq[100005];
long long sw[100005];

struct node{
	long long x,y,zonghe,num;
};
node a[100005],b[100005];
long long cz(node p,node q){
	return p.zonghe<=q.zonghe;
}
long long cx(node p,node q){
	return p.x<=q.x;
}
long long cy(node p,node q){
	return p.y<=q.y;
}
//结构体

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i].num=i;
		pq[i]=0;
		cin>>a[i].x>>a[i].y;
		minn=min(minn,a[i].x+a[i].y);
		a[i].zonghe=a[i].x+a[i].y;
		if(a[i].x>=a[i].y){
			continue;
		}
		else{
			cnt++;
			b[cnt].x=a[i].x;
			b[cnt].y=a[i].y;
			b[cnt].num=i;
			//cout<<b[i].x<<" "<<b[i].y<<" "<<b[i].num<<" ";
		}
	}
	sort(a+1,a+1+n,cz);
	sort(b+1,b+1+cnt,cx);
	/*
	for(int i=1;i<=cnt;i++)
	{
		cout<<b[i].x<<" "<<b[i].y<<" "<<b[i].num<<endl;
	}
	*/
	for(int i=1;i<=cnt;i++){
		if(b[i].x*2<=minn){
			if(m-b[i].x>=0){
				pq[b[i].num]=1;
				m-=b[i].x;
				ans++;
				
				//cout<<pq[b[i].num]<<" "<<b[i].num<<" "<<b[i].x<<" "<<m<<" "<<ans<<endl;
				
			}
			else{
				break;
			}
		}
		else{
			break;
		}
	}
	
	//cout<<"qwertyuiop"<<endl;
	
	for(int i=1;i<=n;i++){
		if(pq[a[i].num]==0){
			sw[i]=a[i].x;
		}
		else{
			sw[i]=a[i].y;
		}
		
		//cout<<sw[i]<<endl;
	}
	sort(sw+1,sw+1+n);
	while(m>0){
		//减去x
		if(pq[a[1].num]==0){
			if(m-a[1].x>=0){
				pq[a[1].num]=1;
				m-=a[1].x;
				ans++;
				if(m-a[1].y<0){
					m+=a[1].x;
					if(m-sw[1]-sw[2]>=0){
						ans++;
						break;
					}
					else{
						break;
					}
				}
				continue;
			}
		}
		//减去y
		if(pq[a[1].num]==1){
			if(m-a[1].y>=0){
				pq[a[1].num]=0;
				m-=a[1].y;
				ans++;
				if(m-a[1].x<0){
					m+=a[1].x;
					if(m-sw[1]-sw[2]>=0){
						ans++;
						break;
					}
					else{
						break;
					}
				}
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
