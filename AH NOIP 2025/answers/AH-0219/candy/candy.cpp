#include<bits/stdc++.h>
using namespace std;
#define ll long long

long long n, m, p[100000][4], *pp[2][100000], ans = 0;
bool cmpa(ll*, ll*);
bool cmpb(ll*, ll*);
bool cmpc(ll*, ll*);

/////////////////////////
ll e(ll);
int main(){
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	cin>>n>>m;
	for(int i = 0 ; i < n ; i ++){
		cin>>p[i][1];//!!!! 0 2, 1 1
		cin>>p[i][0];
		p[i][3] = i;
		if(p[i][1] == p[i][0]){
			p[i][2] = 1;
		}
		pp[0][i] = p[i];
		pp[1][i] = p[i];
	}
	
	sort(pp[0], pp[0] + n, cmpa);
	sort(pp[1], pp[1] + n, cmpb);
	
	int stop = 0;
	
	for (int i = 0; i < n; i++)
	{
		if(pp[1][0][1] + pp[0][i][1] <= pp[1][0][1] + pp[1][0][0] && m >= pp[0][i][1]){
			ans ++;
			m -= pp[0][i][1];
			
			//cout<<"i:"<<pp[0][i][3]<<"v:"<<pp[0][i][1]<<" "<<pp[0][i][0]<<endl;
			
		}else{
			stop = i;
			break;
		}
	}
	
	if(pp[1][0][2] == 1){
		ans += m / pp[1][0][1];
		m %= pp[1][0][1];
	}else{
	
		for (int i = 1; m >= pp[1][0][i % 2]; i++)
		{
			ans ++;
			m -= pp[1][0][i%2];
			//cout<<"min_i:"<<pp[1][0][3]<<" min_"<<pp[1][0][i % 2]<<endl;
		}
	}
	
	
	if(m>0){
		int remain_n = pp[1][0][1];
		//cout<<"remain:"<<m<<endl;
		
		int case_a = 0, ma = m;
		for (int i = stop; i < n; i++)
		{
			if(remain_n >= pp[0][i][1] &&ma >= pp[0][i][1]){
				ma -= pp[0][i][1];
				case_a ++;
				//cout<<"i1:"<<pp[0][i][3]<<"v:"<<pp[0][i][1]<<" "<<pp[0][i][0]<<endl;
			}else{
				break;
			}
		}
		//cout<<"remain_a:"<<ma<<endl;
		
		sort(pp[0], pp[0] + stop+1, cmpc);
		
		//cout<<"remain:"<<m<<endl;
		
		int case_b = 0, mb = m;
		for (int i = 0; i < stop; i++)
		{
			//cout<<"min_i0:"<<pp[0][i][0]<<endl;
			if (mb >= pp[0][i][0]){
				mb -= pp[0][i][0];
				case_b ++;
				//cout<<"i0:"<<pp[0][i][3]<<"v:"<<pp[0][i][1]<<" "<<pp[0][i][0]<<endl;
			}else{
				break;
			}
		}
		ans += max(case_a, case_b);
		
	}
	cout<<ans;
	return 0;
}

bool cmpa(ll* a, ll* b){
	return a[1] < b[1];
}

bool cmpb(ll* a, ll* b){
	if((a[1] + a[0]) != (b[1] + b[0])){
		return (a[1] + a[0]) < (b[1] + b[0]);
	}
	return e(a[1] - a[0]) < e(b[1] - b[0]);
	
}

bool cmpc(ll* a, ll* b){
	return a[0] < b[0];
}


ll e(ll a){
	if(a < 0){
		return a * -1;
	}
	return a;
}
