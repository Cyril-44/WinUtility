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

		size_t sPathLen = strlen(argv[0]);
		for (--sPathLen; argv[0][sPathLen] != '\\'; --sPathLen)
			argv[0][sPathLen] = '\0';

		char buf[sPathLen + 50] = {};
		strcat(buf, "type \"");
		strcat(buf, argv[0]);
		strcat(buf, "Helper.ReadMe\"");
		system(buf);
		
		while (1) {
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
