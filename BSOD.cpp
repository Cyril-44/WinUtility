#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR ipCmdLine, int nCmdShow)
{
    HWND hWnd = GetForegroundWindow();
    ShowWindow(hWnd, SW_HIDE);
    if (MessageBox(NULL, "此程序会使你的电脑蓝屏，确定继续吗？", "警告", MB_YESNO | MB_ICONWARNING) == IDNO)
        return 0;
    if (MessageBox(NULL, "你疯了？？？", "FBI Warning", MB_YESNO | MB_ICONWARNING) == IDNO)
        return 0;
    HMODULE ntdll = LoadLibrary("ntdll.dll");
    FARPROC RtlAdjPriv = GetProcAddress(ntdll, "RtlAdjustPrivilege");
    FARPROC NtRaiseHardErr = GetProcAddress(ntdll, "NtRaiseHardError");
    unsigned char ErrKill;
    long unsigned int HDErr;
    ((void (*)(DWORD, DWORD, BOOLEAN, LPBYTE))RtlAdjPriv)(0x13, true, false, &ErrKill);
    ((void (*)(DWORD, DWORD, DWORD, DWORD, DWORD, LPDWORD))NtRaiseHardErr)(0xc0000233, 0, 0, 0, 6, &HDErr);
    return 0;
}
