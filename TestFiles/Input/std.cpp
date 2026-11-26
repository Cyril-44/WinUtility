// big_stream_hash_solve.cpp
// 编译示例： g++ -O3 -march=native -DNDEBUG big_stream_hash_solve.cpp -o solve
// 运行：     ./solve < input.txt

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t IN_BUF = 1 << 20; // 1MB 输入缓冲
static unsigned char ibuf[IN_BUF];
static size_t ipos = 0, ilen = 0;

inline void refill() {
    ipos = 0;
    ilen = fread(ibuf, 1, IN_BUF, stdin);
    if (ilen == 0) ibuf[0] = 0;
}

inline bool nextChar(unsigned char &c) {
    if (ipos >= ilen) {
        refill();
        if (ilen == 0) return false;
    }
    c = ibuf[ipos++];
    return true;
}

// 解析无符号/有符号整数（空格与换行分隔）
template <typename T>
inline bool readInt(T &x) {
    x = 0;
    unsigned char c;
    bool neg = false;
    // 跳过非数字和非'-'
    do {
        if (!nextChar(c)) return false;
    } while (c != '-' && (c < '0' || c > '9'));
    if (c == '-') {
        neg = true;
        if (!nextChar(c)) return false;
    }
    // 累加
    while (c >= '0' && c <= '9') {
        x = (T)(x * 10 + (c - '0'));
        if (!nextChar(c)) break;
    }
    if (neg) x = -x;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    refill();

    uint64_t N = 0, M = 0, S = 0;
    if (!readInt<uint64_t>(N)) return 0;
    if (!readInt<uint64_t>(M)) return 0;
    if (!readInt<uint64_t>(S)) return 0;

    // 结果用 128 位累加避免中间溢出，再最终取模到 64 位
    unsigned long long H = 0ULL;

    // 逐项读取 A_i
    long long Ai;
    for (uint64_t i = 1; i <= N; ++i) {
        if (!readInt<long long>(Ai)) {
            // 若数据不足，提前结束（健壮性处理）
            break;
        }
        // (Ai + i*S) 可能超 64 位，先用 __int128 计算再截断到 64bit
        __int128 add = ( __int128)Ai + ( (__int128)i * ( __int128)S );
        unsigned long long add64 = (unsigned long long)(add); // 截断
        unsigned long long x = add64 ^ ( (unsigned long long)S ^ (unsigned long long)i );
        // 取模到 M，M <= 2e9，安全
        unsigned long long xm = (M ? (x % M) : x);
        H += xm;
        if (M) H %= M; // 流式取模，避免过大
    }

    // 输出最终结果
    if (M) H %= M;
    printf("%llu\n", (unsigned long long)H);
    return 0;
}
