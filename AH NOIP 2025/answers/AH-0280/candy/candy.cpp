#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,a[N],b[N],s,f,min_num = 2147483647,min_ad;
long long m;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i]  >> b[i];
		if(a[i]+b[i]<min_num){
			min_num = a[i]+b[i];
			min_ad = i;
			f = a[i];
			s = b[i];
		}
		if(a[i]+b[i] == min_num && a[i] < f){
			f = a[i];
			min_ad = i;
			s = b[i];
		}
	}
	int num = 0;
	if(f<=s){
		a[min_ad] = 2147483647,b[min_ad] = 2147483647;
		for(int i = 1;i<=n;i++){
			if(a[i]<f){
				m-=a[i];
				a[i] = b[i];
				//b[i][1] = 1;
				num++;
			}
		}
		if(m>=f){
			m-=f;
			num++;
		}
		if(m == 0){
			cout << num;
			return 0;
		}
		sort(a+1,a+n+1);
		int front = 1;
		while(a[front]+a[front+1]<s+f && front<n-1 && m >= a[front]+a[front+1]){
			m-=(a[front]+a[front+1]);
			front+=2;
			num+=2;
		}
		for(int i = 1;;i++){
			if(m<f&&m<s)break;
			if(i%2 == 1&&m>=s){
				num++;m-=s;
			}else if(i%2 == 0&&m>=f){
				num++;m-=f;
			}
		}
		cout << num;
	}else{
		a[min_ad] = 2147483647,b[min_ad] = 2147483647;
		for(int i = 1;i<=n;i++){
			if(a[i]<s){
				m-=a[i];
				a[i] = b[i];
				num++;
			}
		}
		sort(a+1,a+n+1);
		int front = 1;
		while(a[front]+a[front+1]<s+f && front<=n-2 && m >= a[front]+a[front+1]){
			m-=(a[front]+a[front+1]);
			front+=2;
			num+=2;
		}
		for(int i = 1;;i++){
			if(m<f&&m<s)break;
			if(i%2 == 0&&m>=s){
				num++;m-=s;
			}else if(i%2 == 1&&m>=f){
				num++;m-=f;
			}
		}
		cout << num;
	}
	return 0; 
}
