#include <Windows.h>

#define kd(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)

const int SE_SHUTDOWN_PRIVILEGE = 0x13;

typedef enum _SHUTDOWN_ACTION
{
	ShutdownNoReboot,
	ShutdownReboot,
	ShutdownPowerOff
} SHUTDOWN_ACTION, * PSHUTDOWN_ACTION;

typedef long NTSTATUS;
typedef int (__stdcall *PFN_RtlAdjustPrivilege)( INT, BOOL, BOOL, INT*);
typedef int (__stdcall *PFN_ZwShutdownSystem)(INT);
typedef NTSTATUS(NTAPI* NTSHUTDOWNSYSTEM)(SHUTDOWN_ACTION);

inline bool privUp()
{
	HMODULE hModule = GetModuleHandleW(L"ntdll.dll");
	if (hModule) {
		auto pfnRtl = (PFN_RtlAdjustPrivilege)GetProcAddress( hModule, "RtlAdjustPrivilege");
		int en = 0;
		int nRet = pfnRtl( SE_SHUTDOWN_PRIVILEGE, TRUE, TRUE, &en);
		if( nRet == 0x0C000007C ) nRet = pfnRtl(SE_SHUTDOWN_PRIVILEGE, TRUE, FALSE, &en);
		return nRet == 0;
	}
	return false;
}

inline void reboot()
{
	HMODULE hModule = GetModuleHandleW(L"ntdll.dll");
	if (hModule) {
		auto proc = (NTSHUTDOWNSYSTEM)GetProcAddress(hModule, "NtShutdownSystem");
		if (proc) {
			proc(ShutdownReboot);
		}
	}
}

inline void shutdown() {
	HMODULE hModule = GetModuleHandleW(L"ntdll.dll");
	if (hModule) {
		auto proc = (NTSHUTDOWNSYSTEM)GetProcAddress(hModule, "NtShutdownSystem");
		if (proc) {
			proc(ShutdownNoReboot);
		}
	}
}

inline void color(const WORD &a) {
	/*
		a = 0x__ = x*16 + y
		    0 = Black       8 = Gray
			1 = Blue        9 = Light Blue
			2 = Green       A = Light Green
			3 = Aqua        B = Light Aqua
			4 = Red         C = Light Red
			5 = Purple      D = Light Purple
			6 = Yellow      E = Light Yellow
			7 = White       F = Bright White
		Put word with color X On background with color Y
	*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

int main(int argc, char **argv)
{
	if(!privUp()) {
		system("echo Can't adjust shutdown privilege, please Run As Administrator.");
		return 0x1;
	}
	
	if (argc == 2) {
		for (size_t i = 0; argv[1][i]; i++)
			switch (argv[1][i]) {
				case 's': shutdown(); break;
				case 'r': reboot(); break;
				default: continue;
			}
	}

	else {
		system("chcp 936 >nul");
		system("mode con lines=20 cols=80");

		color(0x4F);
		system("echo Warning: This program may cause your data lose!");

		color(0x6F);
		system("echo For security, the program will exit automaticly in 15s (without input).");

		color(0x07);

		size_t sPathLen = strlen(argv[0]);
		for (--sPathLen; argv[0][sPathLen] != '\\'; --sPathLen)
			argv[0][sPathLen] = '\0';

		char buf[sPathLen + 50] = {};
		strcat(buf, "type \"");
		strcat(buf, argv[0]);
		strcat(buf, "Helper.ReadMe\"");
		if(system(buf)) {
			color(0x6F);
			system("echo Helper file not found or not correct.");
		};
		
		for (unsigned short i = 0; i < 150; i++) { // 5s protection
			if (kd('Q')) break; // Quit
			if (kd('S')) {		// Shutdown
				shutdown();
				break;
			}
			if (kd('R')) {		// Reboot
				reboot();
				break;
			}
			Sleep(100);
		}
	}
	return 0;
}
