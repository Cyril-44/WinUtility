#include<bits/stdc++.h>
using namespace std;
long long const N=1e5+5;
long long n,m,a[N][3];
/*
struct cand{
	long long a,b,c;
	bool operator<(const cand &n){
		return a<n.a;
	}
};
*/
priority_queue<long long> candy;
map<long long,long long> cand;
long long num;
long long mn=0x3f3f3f3f;
long long fa_in;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
		if(a[i][1]+a[i][2]<mn){
			mn=a[i][1]+a[i][2];
			fa_in=i;
		}
		if(!cand[a[i][1]]&&!cand[a[i][2]]){
			cand[a[i][1]]=i;
			cand[a[i][2]]=i;
		}
		else if(cand[a[i][2]]!=0){//2chongle
			cand[a[i][1]]=i;
			if(a[i][1]<a[cand[a[i][2]]][1])
				cand[a[i][2]]=i;
		}
		else if(cand[a[i][1]]!=0){//1chongle
			cand[a[i][2]]=i;
			if(a[i][2]<a[cand[a[i][1]]][2])
				cand[a[i][1]]=i;
		}
		candy.push(a[i][1]*(-1));
		
	}
	//cout<<111111<<"\n";
	//cout<<mn<<" "<<fa_in<<"\n";
	while(m){
		//cout<<m<<" "<<mn<<" "<<num<<" "<<candy.top()*(-1)<<"\n";
		long long to=candy.top()*(-1);
		if(to*2>=mn&&m>=mn){
			m-=mn,num++,num++;
		}
		else if(m>=to){
			m-=to;
			long long flag=cand[to],too=to;
			candy.pop();
			if(too==a[flag][1])
				candy.push(a[flag][2]*(-1));
			else
				candy.push(a[flag][1]*(-1));
			num++;
		}
		else{
			break;
		}
	}
	cout<<num;
}
