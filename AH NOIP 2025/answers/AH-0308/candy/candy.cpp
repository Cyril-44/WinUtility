#include <bits/stdc++.h>
using namespace std;
int n,a[10000],zhong=1,k=1,h=100000000;
long long m,ji[10000],ou[10000],ans,lcm=0;
long long stu(){
	   for(int i=0;;i++)
   {
      if(i!=0);
     {
      ans++;
      a[zhong]++;
	   if(a[zhong]%2==0)
	   m-=ou[zhong];
	   else 
	     m-=ji[zhong];
	     if(zhong<n)
	      zhong++;
	 }
	   if(m<0)
	   {  ans--;
		   lcm=max(ans,lcm);
		   ans=0;
		   zhong--;
		   break;}
		if(k<n){ 
			k++;
	      zhong++;
	     stu();}
  }
  return lcm;
}
long long peo(int g){
	k=m;
	for(int i=1;i<=g;i++)
		  {  k=m;
			  ans++;
			  a[1]++;
			  if(a[1]%2==0)
	      m-=ou[1];
	       else 
	       m-=ji[1];
	       if(m<0){
			   ans--;
			   m=k;
			   lcm=max(ans,lcm);
		   break;}
		   h=ans;
	   }
	   return m;
}
int main()
{
  freopen("candy.in","r",stdin);
  freopen("candy.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
     cin>>ji[i]>>ou[i];
    if(n==1)
    {
		if(m<ji[1]){
			cout<<0;
			return 0;}
		for(int i=1;;i++)
		  {
			ans++;a[n]++;
		   if(a[n]%2==0) m-=ou[n];
	    else m-=ji[n];
	       if(m<0)
	      {ans--;
		   lcm=max(ans,lcm);
		   break;}
		  }	  
		cout<<lcm;
	}
	
   else  if(n==2){
     for(int i=0;;i++){
		m=peo(i);
     for(int j=0;;j++)
     {
		if(j!=0) {ans++;a[2]++;}
		if(a[2]%2==0) m-=ou[2];
	    else  m-=ji[2];
	     if(m<0)
	      {ans--;
		   lcm=max(ans,lcm);
		   ans=0;
		   break;}
		  }
		if(h<i) break;	  
	 }
	 cout<<lcm;
 }
	 else 
		 cout<<stu();
  return 0;
}
