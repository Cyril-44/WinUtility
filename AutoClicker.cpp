#include <windows.h>
#include <thread>
#include <atomic>
#include <random>
#include <chrono>

// 原先的单一 clicking 改为两个独立的开关，分别控制左/右键
std::atomic<bool> leftClicking(false);
std::atomic<bool> rightClicking(false);

// 新增：延迟档（0/1/2），及双按 K 相关变量
std::atomic<int> delayPreset(1); // 默认档为 1

void clickLoop() {
    try {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist0(95, 145);
        std::uniform_int_distribution<int> dist1(75, 125);
        std::uniform_int_distribution<int> dist2(55, 95);

        while (true) {
            bool left = leftClicking.load();
            bool right = rightClicking.load();

            if (left || right) {
                // 如果左键开启，先发送左键按下/抬起
                if (left) {
                    INPUT input = {0};
                    input.type = INPUT_MOUSE;
                    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                    SendInput(1, &input, sizeof(INPUT));

                    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                    SendInput(1, &input, sizeof(INPUT));
                }

                // 如果右键开启，发送右键按下/抬起
                if (right) {
                    INPUT input = {0};
                    input.type = INPUT_MOUSE;
                    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
                    SendInput(1, &input, sizeof(INPUT));

                    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
                    SendInput(1, &input, sizeof(INPUT));
                }

                // 根据当前 preset 选择不同的分布
                int preset = delayPreset.load();
                int delay = 100;
                if (preset == 0) {
                    delay = dist0(gen);
                } else if (preset == 1) {
                    delay = dist1(gen);
                } else { // preset == 2
                    delay = dist2(gen);
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    } catch (const std::exception& e) {
        MessageBoxA(nullptr, e.what(), "Thread Exception", MB_OK | MB_ICONERROR);
    }
}

int main() {
    std::thread(clickLoop).detach(); // 后台线程运行点击逻辑

    // 双按 K 检测：记录上次按下时间
    auto lastK = std::chrono::steady_clock::time_point();
    const auto doublePressThreshold = std::chrono::milliseconds(500);

    while (true) {
        // G 切换左键自动点击
        if (GetAsyncKeyState('G') & 0x8000) {
            leftClicking = !leftClicking.load();
            Sleep(300); // 防止重复触发
        }
        // H 切换右键自动点击
        if (GetAsyncKeyState('H') & 0x8000) {
            rightClicking = !rightClicking.load();
            Sleep(300); // 防止重复触发
        }

        // 右侧 Ctrl + 0/1/2 切换三种 Delay 档
        if ((GetAsyncKeyState(VK_RCONTROL) & 0x8000) != 0) {
            if (GetAsyncKeyState('0') & 0x8000) {
                delayPreset = 0;
                Sleep(250); // 去抖
            } else if (GetAsyncKeyState('1') & 0x8000) {
                delayPreset = 1;
                Sleep(250);
            } else if (GetAsyncKeyState('2') & 0x8000) {
                delayPreset = 2;
                Sleep(250);
            }
        }

        // 双按 K 自毁（kill pid）
        if (GetAsyncKeyState('K') & 0x8000) {
            auto now = std::chrono::steady_clock::now();
            if (lastK == std::chrono::steady_clock::time_point()) {
                lastK = now;
            } else {
                auto diff = now - lastK;
                lastK = std::chrono::steady_clock::time_point(); // 重置，避免重复触发
                if (diff <= doublePressThreshold) {
                    // 尝试以 TerminateProcess 杀死当前进程（模拟 kill pid 自毁）
                    DWORD pid = GetCurrentProcessId();
                    HANDLE h = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
                    if (h) {
                        TerminateProcess(h, 1);
                        CloseHandle(h);
                    } else {
                        // 若无法打开进程句柄则直接退出
                        ExitProcess(1);
                    }
                    // 程序应已结束，此处为了安全再做一次退出
                    ExitProcess(1);
                }
            }
            Sleep(300); // 防止把单按也识别成多次
        }

        Sleep(50);
    }

    return 0;
}