#include <stdio.h>
#include <windows.h>
bool Start(){
	system("title Virtual CD Installer");
	printf("English 6A Virtual CD Installer\n");
	printf("Copyright (C) Hardsoft Coporation\n");
	// if(MessageBox(NULL,"Do you really want to start English 6A Ebook?","English 6A Virtual CD Installer",MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	//	return 0;
	/*else*/ return 0;
	;
}
void Load(){
	system("start explorer En6A.iso >NUL 2>NUL");
	for(int i=0;i<=100;i++){
		HANDLE hout;
		COORD coord;
		coord.X=0;
		coord.Y=2;
		hout=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout,coord);
		printf("["); int j;
		for(j=0;j<i;j+=5)
			printf("-");
		for(;j<100;j+=5)
			printf(" ");
		printf("]\n");
		coord.X=10;
		coord.Y=2;
		hout=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout,coord);
		printf("%03d%%\n",i);
		coord.X=0;
		coord.Y=3;
		hout=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout,coord);
		Sleep(10);
		if(i==40) system("taskkill /f /im explorer.exe >nul");
	}
	system("start explorer.exe");
}
void Search(){
	printf("Searching Virtual CD...");
	system("if exist D:\\En6A.txt start D:\\start.exe");
	system("if exist E:\\En6A.txt start E:\\start.exe");
	system("if exist F:\\En6A.txt start F:\\start.exe");
	system("if exist G:\\En6A.txt start G:\\start.exe");
	system("if exist H:\\En6A.txt start H:\\start.exe");
	system("if exist I:\\En6A.txt start I:\\start.exe");
	system("if exist J:\\En6A.txt start J:\\start.exe");
	system("if exist K:\\En6A.txt start K:\\start.exe");
	system("if exist L:\\En6A.txt start L:\\start.exe");
	printf("Done.\nOpening in progress...");
}
int main(){
	if(Start())
	return 0;
	Load();
	Search();
	Sleep(1000);
	return 0;
}
