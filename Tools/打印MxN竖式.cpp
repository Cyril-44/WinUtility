#include <cstdio>
#include <windows.h>
int cnt(int n){
	if(n<=0) return 0;
	return 1+cnt(n/10);
}
int main(){
	unsigned x=0,y=0;
	MessageBox(NULL,(LPCWSTR)"���������������ûس��������м���x������\n���磺\n1990x2000\n\nע�������������6�ڵ���������������᲻��ȷ������",(LPCWSTR)"��ܰ��ʾ",MB_OK | MB_ICONINFORMATION);
	scanf("%dx%d",&x,&y);
	unsigned sum=x*y;
	int lth=cnt(sum)+1;
	system("cls");
	printf("%ux%u=%u\n",x,y,sum);
	printf("%*u\n",lth,x);
	printf("x%*u\n",lth-1,y);
	for(int i=0;i<lth;i++) printf("_");
	for(int i=lth;y;i--,y/=10){
		unsigned b=y%10;
		unsigned t=x*b;
		printf("\n%*d",i,t);
	}printf("\n");
	for(int i=0;i<lth;i++) printf("_");
	printf("\n%*d\n",lth,sum);
	system("pause");
	return 0;
}