// big_stream_hash_gen.cpp
// 用法示例：
//   ./gen 100000000 1000000007 123456789 --mode rand --min -1000 --max 1000 > input.txt
//   ./gen 100000000 1000000007 123456789 --mode inc --start -500 --step 3 > input.txt
// 备注：1e8 行文件体积巨大，请确保磁盘与管道带宽。

#include <bits/stdc++.h>
using namespace std;

// 高速随机：SplitMix64（简单、快速、质量足够）
struct SplitMix64 {
    uint64_t x;
    explicit SplitMix64(uint64_t seed) : x(seed) {}
    uint64_t next() {
        uint64_t z = (x += 0x9e3779b97f4a7c15ULL);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        return z ^ (z >> 31);
    }
    int64_t nextInt64(int64_t lo, int64_t hi) {
        uint64_t r = next();
        __int128 span = (__int128)hi - (__int128)lo + 1;
        int64_t v = (int64_t)((__int128)(r % (uint64_t)span) + lo);
        return v;
    }
};

static constexpr size_t OUT_BUF = 1 << 20; // 1MB 输出缓冲

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (argc < 4) {
        cerr << "Usage: gen N M S [--mode rand|inc|zero] [--min MIN] [--max MAX] "
                "[--start START] [--step STEP]\n";
        return 1;
    }
    uint64_t N = strtoull(argv[1], nullptr, 10);
    uint64_t M = strtoull(argv[2], nullptr, 10);
    uint64_t S = strtoull(argv[3], nullptr, 10);

    string mode = "rand";
    int64_t mn = -1000000, mx = 1000000;
    int64_t start = 0, step = 1;

    for (int i = 4; i < argc; ++i) {
        string k = argv[i];
        auto nextArg = [&](const char* name) -> const char* {
            if (i + 1 >= argc) {
                cerr << "Missing value for " << name << "\n";
                exit(2);
            }
            return argv[++i];
        };
        if (k == string("--mode")) mode = nextArg("--mode");
        else if (k == string("--min")) mn = atoll(nextArg("--min"));
        else if (k == string("--max")) mx = atoll(nextArg("--max"));
        else if (k == string("--start")) start = atoll(nextArg("--start"));
        else if (k == string("--step")) step = atoll(nextArg("--step"));
    }

    // 输出使用 stdio 以获得更高吞吐
    // 首行
    {
        char header[128];
        int len = snprintf(header, sizeof(header), "%llu %llu %llu\n",
                           (unsigned long long)N,
                           (unsigned long long)M,
                           (unsigned long long)S);
        fwrite(header, 1, len, stdout);
    }

    vector<char> buf;
    buf.reserve(OUT_BUF);
    SplitMix64 rng(S ? S : 0x12345678ULL);

    auto flush = [&]() {
        if (!buf.empty()) {
            fwrite(buf.data(), 1, buf.size(), stdout);
            buf.clear();
        }
    };

    int64_t cur = start;
    for (uint64_t i = 0; i < N; ++i) {
        int64_t v;
        if (mode == "rand") {
            v = rng.nextInt64(mn, mx);
        } else if (mode == "inc") {
            v = cur;
            cur += step;
        } else if (mode == "zero") {
            v = 0;
        } else {
            v = rng.nextInt64(mn, mx);
        }
        // 写入："v " 或末尾换行以增强可读性。大量数据建议空格分隔降低换行开销。
        char tmp[32];
        int len = snprintf(tmp, sizeof(tmp), "%lld ", (long long)v);
        if (buf.size() + len > OUT_BUF) flush();
        buf.insert(buf.end(), tmp, tmp + len);
    }
    // 末尾换行
    buf.push_back('\n');
    flush();
    return 0;
}
