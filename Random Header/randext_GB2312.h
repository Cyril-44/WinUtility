#ifndef _RANDEXT_H_
#define _RANDEXT_H_

/*
 * Author: Hardsoft Cyril
 * Build Date: 15th Oct. 2022
 * Useful functions:
 *  - randU()
 *  - randL(ll, ll)
 *  - randI()
 *  - randF(double, double)
 *  - randS(char[])
 */

// The program includes some parts of testlib.
#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NO_VA_START_VALIDATION
#endif

/* Overrides random() for Borland C++. */
#define random __random_deprecated
#include <stdlib.h>
#include <cstdlib>
#include <climits>
#include <algorithm>
#undef random

#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>

#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__)
#if !defined(_MSC_VER) || _MSC_VER > 1400
#define NOMINMAX 1
#include <windows.h>
#else
#define WORD unsigned short
#include <unistd.h>
#endif
#include <io.h>
#define ON_WINDOWS
#else
#define WORD unsigned short
#endif

#ifndef LLONG_MIN
#define LLONG_MIN (-9223372036854775807LL - 1)
#endif

#ifndef ULLONG_MAX
#define ULLONG_MAX (18446744073709551615)
#endif

#ifdef ON_WINDOWS
#define I64 "%I64d"
#define U64 "%I64u"
#else
#define I64 "%lld"
#define U64 "%llu"
#endif

#ifdef _MSC_VER
#define NORETURN __declspec(noreturn)
#elif defined __GNUC__
#define NORETURN __attribute__((noreturn))
#else
#define NORETURN
#endif

static char __testlib_format_buffer[16777216];
static int __testlib_format_buffer_usage_count = 0;

#define FMT_TO_RESULT(fmt, cstr, result)                                           \
    std::string result;                                                            \
    if (__testlib_format_buffer_usage_count != 0)                                  \
        __testlib_fail("FMT_TO_RESULT::__testlib_format_buffer_usage_count != 0"); \
    __testlib_format_buffer_usage_count++;                                         \
    va_list ap;                                                                    \
    va_start(ap, fmt);                                                             \
    std::vsprintf(__testlib_format_buffer, cstr, ap);                              \
    va_end(ap);                                                                    \
    result = std::string(__testlib_format_buffer);                                 \
    __testlib_format_buffer_usage_count--;

const long long __TESTLIB_LONGLONG_MAX = 9223372036854775807LL;

NORETURN static void __testlib_fail(const std::string &message)
{
    puts("");
    puts("Error occured!");
    puts(message.c_str());
    exit(0x114514);
}

template <typename T>
static inline T __testlib_abs(const T &x)
{
    return x > 0 ? x : -x;
}

template <typename T>
static inline T __testlib_min(const T &a, const T &b)
{
    return a < b ? a : b;
}

template <typename T>
static inline T __testlib_max(const T &a, const T &b)
{
    return a > b ? a : b;
}

static std::string removeDoubleTrailingZeroes(std::string value)
{
    while (!value.empty() && value[value.length() - 1] == '0' && value.find('.') != std::string::npos)
        value = value.substr(0, value.length() - 1);
    return value + '0';
}

#ifdef __GNUC__
__attribute__((format(printf, 1, 2)))
#endif
std::string
format(const char *fmt, ...)
{
    FMT_TO_RESULT(fmt, fmt, result);
    return result;
}

std::string format(const std::string &fmt, ...)
{
    FMT_TO_RESULT(fmt, fmt.c_str(), result);
    return result;
}

static std::string __testlib_part(const std::string &s);

/*
 * Very simple regex-like pattern.
 * It used for two purposes: validation and generation.
 *
 * For example, pattern("[a-z]{1,5}").next(rnd) will return
 * random string from lowercase latin letters with length
 * from 1 to 5. It is easier to call rnd.next("[a-z]{1,5}")
 * for the same effect.
 *
 * Another samples:
 * "mike|john" will generate (match) "mike" or "john";
 * "-?[1-9][0-9]{0,3}" will generate (match) non-zero integers from -9999 to 9999;
 * "id-([ac]|b{2})" will generate (match) "id-a", "id-bb", "id-c";
 * "[^0-9]*" will match sequences (empty or non-empty) without digits, you can't
 * use it for generations.
 *
 * You can't use pattern for generation if it contains meta-symbol '*'. Also it
 * is not recommended to use it for char-sets with meta-symbol '^' like [^a-z].
 *
 * For matching very simple greedy algorithm is used. For example, pattern
 * "[0-9]?1" will not match "1", because of greedy nature of matching.
 * Alternations (meta-symbols "|") are processed with brute-force algorithm, so
 * do not use many alternations in one expression.
 *
 * If you want to use one expression many times it is better to compile it into
 * a single pattern like "pattern p("[a-z]+")". Later you can use
 * "p.matches(std::string s)" or "p.next(random_t& rd)" to check matching or generate
 * new string by pattern.
 *
 * Simpler way to read token and check it for pattern matching is "inf.readToken("[a-z]+")".
 */
class random_t;

class pattern
{
public:
    /* Create pattern instance by string. */
    pattern(std::string s);
    /* Generate new string by pattern and given random_t. */
    std::string next(random_t &rnd) const;
    /* Checks if given string match the pattern. */
    bool matches(const std::string &s) const;
    /* Returns source string of the pattern. */
    std::string src() const;

private:
    bool matches(const std::string &s, size_t pos) const;

    std::string s;
    std::vector<pattern> children;
    std::vector<char> chars;
    int from;
    int to;
};

/*
 * Use random_t instances to generate random values. It is preffered
 * way to use randoms instead of rand() function or self-written
 * randoms.
 *
 * Testlib defines global variable "rnd" of random_t class.
 * Use registerGen(argc, argv, 1) to setup random_t seed be command
 * line (to use latest random generator version).
 *
 * Random generates uniformly distributed values if another strategy is
 * not specified explicitly.
 */
class random_t
{
private:
    unsigned long long seed;
    static const unsigned long long multiplier;
    static const unsigned long long addend;
    static const unsigned long long mask;
    static const int lim;

    long long nextBits(int bits)
    {
        if (bits <= 48)
        {
            seed = (seed * multiplier + addend) & mask;
            return (long long)(seed >> (48 - bits));
        }
        else
        {
            if (bits > 63)
                __testlib_fail("random_t::nextBits(int bits): n must be less than 64");

            int lowerBitCount = (random_t::version == 0 ? 31 : 32);

            long long left = (nextBits(31) << 32);
            long long right = nextBits(lowerBitCount);

            return left ^ right;
        }
    }

public:
    static int version;

    /* New random_t with fixed seed. */
    random_t()
        : seed(3905348978240129619LL)
    {
    }

    /* Sets seed by command line. */
    void setSeed(int argc, char *argv[])
    {
        random_t p;

        seed = 3905348978240129619LL;
        for (int i = 1; i < argc; i++)
        {
            std::size_t le = std::strlen(argv[i]);
            for (std::size_t j = 0; j < le; j++)
                seed = seed * multiplier + (unsigned int)(argv[i][j]) + addend;
            seed += multiplier / addend;
        }

        seed = seed & mask;
    }

    /* Sets seed by given value. */
    void setSeed(long long _seed)
    {
        _seed = (_seed ^ multiplier) & mask;
        seed = _seed;
    }

#ifndef __BORLANDC__
    /* Random string value by given pattern (see pattern documentation). */
    std::string next(const std::string &ptrn)
    {
        pattern p(ptrn);
        return p.next(*this);
    }
#else
    /* Random string value by given pattern (see pattern documentation). */
    std::string next(std::string ptrn)
    {
        pattern p(ptrn);
        return p.next(*this);
    }
#endif

    /* Random value in range [0, n-1]. */
    int next(int n)
    {
        if (n <= 0)
            __testlib_fail("random_t::next(int n): n must be positive");

        if ((n & -n) == n) // n is a power of 2
            return (int)((n * (long long)nextBits(31)) >> 31);

        const long long limit = INT_MAX / n * n;

        long long bits;
        do
        {
            bits = nextBits(31);
        } while (bits >= limit);

        return int(bits % n);
    }

    /* Random value in range [0, n-1]. */
    unsigned int next(unsigned int n)
    {
        if (n >= INT_MAX)
            __testlib_fail("random_t::next(unsigned int n): n must be less INT_MAX");
        return (unsigned int)next(int(n));
    }

    /* Random value in range [0, n-1]. */
    long long next(long long n)
    {
        if (n <= 0)
            __testlib_fail("random_t::next(long long n): n must be positive");

        const long long limit = __TESTLIB_LONGLONG_MAX / n * n;

        long long bits;
        do
        {
            bits = nextBits(63);
        } while (bits >= limit);

        return bits % n;
    }

    /* Random value in range [0, n-1]. */
    unsigned long long next(unsigned long long n)
    {
        if (n >= (unsigned long long)(__TESTLIB_LONGLONG_MAX))
            __testlib_fail("random_t::next(unsigned long long n): n must be less LONGLONG_MAX");
        return (unsigned long long)next((long long)(n));
    }

    /* Random value in range [0, n-1]. */
    long next(long n)
    {
        return (long)next((long long)(n));
    }

    /* Random value in range [0, n-1]. */
    unsigned long next(unsigned long n)
    {
        if (n >= (unsigned long)(LONG_MAX))
            __testlib_fail("random_t::next(unsigned long n): n must be less LONG_MAX");
        return (unsigned long)next((unsigned long long)(n));
    }

    /* Returns random value in range [from,to]. */
    int next(int from, int to)
    {
        return int(next((long long)to - from + 1) + from);
    }

    /* Returns random value in range [from,to]. */
    unsigned int next(unsigned int from, unsigned int to)
    {
        return (unsigned int)(next((long long)to - from + 1) + from);
    }

    /* Returns random value in range [from,to]. */
    long long next(long long from, long long to)
    {
        return next(to - from + 1) + from;
    }

    /* Returns random value in range [from,to]. */
    unsigned long long next(unsigned long long from, unsigned long long to)
    {
        if (from > to)
            __testlib_fail("random_t::next(unsigned long long from, unsigned long long to): from can't not exceed to");
        return next(to - from + 1) + from;
    }

    /* Returns random value in range [from,to]. */
    long next(long from, long to)
    {
        return next(to - from + 1) + from;
    }

    /* Returns random value in range [from,to]. */
    unsigned long next(unsigned long from, unsigned long to)
    {
        if (from > to)
            __testlib_fail("random_t::next(unsigned long from, unsigned long to): from can't not exceed to");
        return next(to - from + 1) + from;
    }

    /* Random double value in range [0, 1). */
    double next()
    {
        long long left = ((long long)(nextBits(26)) << 27);
        long long right = nextBits(27);
        return (double)(left + right) / (double)(1LL << 53);
    }

    /* Random double value in range [0, n). */
    double next(double n)
    {
        return n * next();
    }

    /* Random double value in range [from, to). */
    double next(double from, double to)
    {
        if (from > to)
            __testlib_fail("random_t::next(double from, double to): from can't not exceed to");
        return next(to - from) + from;
    }

    /* Returns random element from container. */
    template <typename Container>
    typename Container::value_type any(const Container &c)
    {
        size_t size = c.size();
        if (size <= 0)
            __testlib_fail("random_t::any(const Container& c): c.size() must be positive");
        return *(c.begin() + next(size));
    }

    /* Returns random element from iterator range. */
    template <typename Iter>
    typename Iter::value_type any(const Iter &begin, const Iter &end)
    {
        int size = int(end - begin);
        if (size <= 0)
            __testlib_fail("random_t::any(const Iter& begin, const Iter& end): range must have positive length");
        return *(begin + next(size));
    }

    /* Random string value by given pattern (see pattern documentation). */
#ifdef __GNUC__
    __attribute__((format(printf, 2, 3)))
#endif
    std::string
    next(const char *format, ...)
    {
        FMT_TO_RESULT(format, format, ptrn);
        return next(ptrn);
    }

    /*
     * Weighted next. If type == 0 than it is usual "next()".
     *
     * If type = 1, than it returns "max(next(), next())"
     * (the number of "max" functions equals to "type").
     *
     * If type < 0, than "max" function replaces with "min".
     */
    int wnext(int n, int type)
    {
        if (n <= 0)
            __testlib_fail("random_t::wnext(int n, int type): n must be positive");

        if (abs(type) < random_t::lim)
        {
            int result = next(n);

            for (int i = 0; i < +type; i++)
                result = __testlib_max(result, next(n));

            for (int i = 0; i < -type; i++)
                result = __testlib_min(result, next(n));

            return result;
        }
        else
        {
            double p;

            if (type > 0)
                p = std::pow(next() + 0.0, 1.0 / (type + 1));
            else
                p = 1 - std::pow(next() + 0.0, 1.0 / (-type + 1));

            return int(n * p);
        }
    }

    /* See wnext(int, int). It uses the same algorithms. */
    long long wnext(long long n, int type)
    {
        if (n <= 0)
            __testlib_fail("random_t::wnext(long long n, int type): n must be positive");

        if (abs(type) < random_t::lim)
        {
            long long result = next(n);

            for (int i = 0; i < +type; i++)
                result = __testlib_max(result, next(n));

            for (int i = 0; i < -type; i++)
                result = __testlib_min(result, next(n));

            return result;
        }
        else
        {
            double p;

            if (type > 0)
                p = std::pow(next() + 0.0, 1.0 / (type + 1));
            else
                p = std::pow(next() + 0.0, -type + 1);

            return __testlib_min(__testlib_max((long long)(double(n) * p), 0LL), n - 1LL);
        }
    }

    /* See wnext(int, int). It uses the same algorithms. */
    double wnext(int type)
    {
        if (abs(type) < random_t::lim)
        {
            double result = next();

            for (int i = 0; i < +type; i++)
                result = __testlib_max(result, next());

            for (int i = 0; i < -type; i++)
                result = __testlib_min(result, next());

            return result;
        }
        else
        {
            double p;

            if (type > 0)
                p = std::pow(next() + 0.0, 1.0 / (type + 1));
            else
                p = std::pow(next() + 0.0, -type + 1);

            return p;
        }
    }

    /* See wnext(int, int). It uses the same algorithms. */
    double wnext(double n, int type)
    {
        if (n <= 0)
            __testlib_fail("random_t::wnext(double n, int type): n must be positive");

        if (abs(type) < random_t::lim)
        {
            double result = next();

            for (int i = 0; i < +type; i++)
                result = __testlib_max(result, next());

            for (int i = 0; i < -type; i++)
                result = __testlib_min(result, next());

            return n * result;
        }
        else
        {
            double p;

            if (type > 0)
                p = std::pow(next() + 0.0, 1.0 / (type + 1));
            else
                p = std::pow(next() + 0.0, -type + 1);

            return n * p;
        }
    }

    /* See wnext(int, int). It uses the same algorithms. */
    unsigned int wnext(unsigned int n, int type)
    {
        if (n >= INT_MAX)
            __testlib_fail("random_t::wnext(unsigned int n, int type): n must be less INT_MAX");
        return (unsigned int)wnext(int(n), type);
    }

    /* See wnext(int, int). It uses the same algorithms. */
    unsigned long long wnext(unsigned long long n, int type)
    {
        if (n >= (unsigned long long)(__TESTLIB_LONGLONG_MAX))
            __testlib_fail("random_t::wnext(unsigned long long n, int type): n must be less LONGLONG_MAX");

        return (unsigned long long)wnext((long long)(n), type);
    }

    /* See wnext(int, int). It uses the same algorithms. */
    long wnext(long n, int type)
    {
        return (long)wnext((long long)(n), type);
    }

    /* See wnext(int, int). It uses the same algorithms. */
    unsigned long wnext(unsigned long n, int type)
    {
        if (n >= (unsigned long)(LONG_MAX))
            __testlib_fail("random_t::wnext(unsigned long n, int type): n must be less LONG_MAX");

        return (unsigned long)wnext((unsigned long long)(n), type);
    }

    /* Returns weighted random value in range [from, to]. */
    int wnext(int from, int to, int type)
    {
        if (from > to)
            __testlib_fail("random_t::wnext(int from, int to, int type): from can't not exceed to");
        return wnext(to - from + 1, type) + from;
    }

    /* Returns weighted random value in range [from, to]. */
    int wnext(unsigned int from, unsigned int to, int type)
    {
        if (from > to)
            __testlib_fail("random_t::wnext(unsigned int from, unsigned int to, int type): from can't not exceed to");
        return int(wnext(to - from + 1, type) + from);
    }

    /* Returns weighted random value in range [from, to]. */
    long long wnext(long long from, long long to, int type)
    {
        if (from > to)
            __testlib_fail("random_t::wnext(long long from, long long to, int type): from can't not exceed to");
        return wnext(to - from + 1, type) + from;
    }

    /* Returns weighted random value in range [from, to]. */
    unsigned long long wnext(unsigned long long from, unsigned long long to, int type)
    {
        if (from > to)
            __testlib_fail("random_t::wnext(unsigned long long from, unsigned long long to, int type): from can't not exceed to");
        return wnext(to - from + 1, type) + from;
    }

    /* Returns weighted random value in range [from, to]. */
    long wnext(long from, long to, int type)
    {
        if (from > to)
            __testlib_fail("random_t::wnext(long from, long to, int type): from can't not exceed to");
        return wnext(to - from + 1, type) + from;
    }

    /* Returns weighted random value in range [from, to]. */
    unsigned long wnext(unsigned long from, unsigned long to, int type)
    {
        if (from > to)
            __testlib_fail("random_t::wnext(unsigned long from, unsigned long to, int type): from can't not exceed to");
        return wnext(to - from + 1, type) + from;
    }

    /* Returns weighted random double value in range [from, to). */
    double wnext(double from, double to, int type)
    {
        if (from > to)
            __testlib_fail("random_t::wnext(double from, double to, int type): from can't not exceed to");
        return wnext(to - from, type) + from;
    }

    /* Returns weighted random element from container. */
    template <typename Container>
    typename Container::value_type wany(const Container &c, int type)
    {
        size_t size = c.size();
        if (size <= 0)
            __testlib_fail("random_t::wany(const Container& c, int type): c.size() must be positive");
        return *(c.begin() + wnext(size, type));
    }

    /* Returns weighted random element from iterator range. */
    template <typename Iter>
    typename Iter::value_type wany(const Iter &begin, const Iter &end, int type)
    {
        int size = int(end - begin);
        if (size <= 0)
            __testlib_fail("random_t::any(const Iter& begin, const Iter& end, int type): range must have positive length");
        return *(begin + wnext(size, type));
    }
};

const int random_t::lim = 25;
const unsigned long long random_t::multiplier = 0x5DEECE66DLL;
const unsigned long long random_t::addend = 0xBLL;
const unsigned long long random_t::mask = (1LL << 48) - 1;
int random_t::version = -1;

/* Pattern implementation */
bool pattern::matches(const std::string &s) const
{
    return matches(s, 0);
}

static bool __pattern_isSlash(const std::string &s, size_t pos)
{
    return s[pos] == '\\';
}

#ifdef __GNUC__
__attribute__((pure))
#endif
static bool
__pattern_isCommandChar(const std::string &s, size_t pos, char value)
{
    if (pos >= s.length())
        return false;

    int slashes = 0;

    int before = int(pos) - 1;
    while (before >= 0 && s[before] == '\\')
        before--, slashes++;

    return slashes % 2 == 0 && s[pos] == value;
}

static char __pattern_getChar(const std::string &s, size_t &pos)
{
    if (__pattern_isSlash(s, pos))
        pos += 2;
    else
        pos++;

    return s[pos - 1];
}

#ifdef __GNUC__
__attribute__((pure))
#endif
static int
__pattern_greedyMatch(const std::string &s, size_t pos, const std::vector<char> chars)
{
    int result = 0;

    while (pos < s.length())
    {
        char c = s[pos++];
        if (!std::binary_search(chars.begin(), chars.end(), c))
            break;
        else
            result++;
    }

    return result;
}

std::string pattern::src() const
{
    return s;
}

bool pattern::matches(const std::string &s, size_t pos) const
{
    std::string result;

    if (to > 0)
    {
        int size = __pattern_greedyMatch(s, pos, chars);
        if (size < from)
            return false;
        if (size > to)
            size = to;
        pos += size;
    }

    if (children.size() > 0)
    {
        for (size_t child = 0; child < children.size(); child++)
            if (children[child].matches(s, pos))
                return true;
        return false;
    }
    else
        return pos == s.length();
}

std::string pattern::next(random_t &rnd) const
{
    std::string result;
    result.reserve(20);

    if (to == INT_MAX)
        __testlib_fail("pattern::next(random_t& rnd): can't process character '*' for generation");

    if (to > 0)
    {
        int count = rnd.next(to - from + 1) + from;
        for (int i = 0; i < count; i++)
            result += chars[rnd.next(int(chars.size()))];
    }

    if (children.size() > 0)
    {
        int child = rnd.next(int(children.size()));
        result += children[child].next(rnd);
    }

    return result;
}

static void __pattern_scanCounts(const std::string &s, size_t &pos, int &from, int &to)
{
    if (pos >= s.length())
    {
        from = to = 1;
        return;
    }

    if (__pattern_isCommandChar(s, pos, '{'))
    {
        std::vector<std::string> parts;
        std::string part;

        pos++;

        while (pos < s.length() && !__pattern_isCommandChar(s, pos, '}'))
        {
            if (__pattern_isCommandChar(s, pos, ','))
                parts.push_back(part), part = "", pos++;
            else
                part += __pattern_getChar(s, pos);
        }

        if (part != "")
            parts.push_back(part);

        if (!__pattern_isCommandChar(s, pos, '}'))
            __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");

        pos++;

        if (parts.size() < 1 || parts.size() > 2)
            __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");

        std::vector<int> numbers;

        for (size_t i = 0; i < parts.size(); i++)
        {
            if (parts[i].length() == 0)
                __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");
            int number;
            if (std::sscanf(parts[i].c_str(), "%d", &number) != 1)
                __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");
            numbers.push_back(number);
        }

        if (numbers.size() == 1)
            from = to = numbers[0];
        else
            from = numbers[0], to = numbers[1];

        if (from > to)
            __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");
    }
    else
    {
        if (__pattern_isCommandChar(s, pos, '?'))
        {
            from = 0, to = 1, pos++;
            return;
        }

        if (__pattern_isCommandChar(s, pos, '*'))
        {
            from = 0, to = INT_MAX, pos++;
            return;
        }

        if (__pattern_isCommandChar(s, pos, '+'))
        {
            from = 1, to = INT_MAX, pos++;
            return;
        }

        from = to = 1;
    }
}

static std::vector<char> __pattern_scanCharSet(const std::string &s, size_t &pos)
{
    if (pos >= s.length())
        __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");

    std::vector<char> result;

    if (__pattern_isCommandChar(s, pos, '['))
    {
        pos++;
        bool negative = __pattern_isCommandChar(s, pos, '^');

        char prev = 0;

        while (pos < s.length() && !__pattern_isCommandChar(s, pos, ']'))
        {
            if (__pattern_isCommandChar(s, pos, '-') && prev != 0)
            {
                pos++;

                if (pos + 1 == s.length() || __pattern_isCommandChar(s, pos, ']'))
                {
                    result.push_back(prev);
                    prev = '-';
                    continue;
                }

                char next = __pattern_getChar(s, pos);
                if (prev > next)
                    __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");

                for (char c = prev; c != next; c++)
                    result.push_back(c);
                result.push_back(next);

                prev = 0;
            }
            else
            {
                if (prev != 0)
                    result.push_back(prev);
                prev = __pattern_getChar(s, pos);
            }
        }

        if (prev != 0)
            result.push_back(prev);

        if (!__pattern_isCommandChar(s, pos, ']'))
            __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");

        pos++;

        if (negative)
        {
            std::sort(result.begin(), result.end());
            std::vector<char> actuals;
            for (int code = 0; code < 255; code++)
            {
                char c = char(code);
                if (!std::binary_search(result.begin(), result.end(), c))
                    actuals.push_back(c);
            }
            result = actuals;
        }

        std::sort(result.begin(), result.end());
    }
    else
        result.push_back(__pattern_getChar(s, pos));

    return result;
}

pattern::pattern(std::string s) : s(s), from(0), to(0)
{
    std::string t;
    for (size_t i = 0; i < s.length(); i++)
        if (!__pattern_isCommandChar(s, i, ' '))
            t += s[i];
    s = t;

    int opened = 0;
    int firstClose = -1;
    std::vector<int> seps;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (__pattern_isCommandChar(s, i, '('))
        {
            opened++;
            continue;
        }

        if (__pattern_isCommandChar(s, i, ')'))
        {
            opened--;
            if (opened == 0 && firstClose == -1)
                firstClose = int(i);
            continue;
        }

        if (opened < 0)
            __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");

        if (__pattern_isCommandChar(s, i, '|') && opened == 0)
            seps.push_back(int(i));
    }

    if (opened != 0)
        __testlib_fail("pattern: Illegal pattern (or part) \"" + s + "\"");

    if (seps.size() == 0 && firstClose + 1 == (int)s.length() && __pattern_isCommandChar(s, 0, '(') && __pattern_isCommandChar(s, s.length() - 1, ')'))
    {
        children.push_back(pattern(s.substr(1, s.length() - 2)));
    }
    else
    {
        if (seps.size() > 0)
        {
            seps.push_back(int(s.length()));
            int last = 0;

            for (size_t i = 0; i < seps.size(); i++)
            {
                children.push_back(pattern(s.substr(last, seps[i] - last)));
                last = seps[i] + 1;
            }
        }
        else
        {
            size_t pos = 0;
            chars = __pattern_scanCharSet(s, pos);
            __pattern_scanCounts(s, pos, from, to);
            if (pos < s.length())
                children.push_back(pattern(s.substr(pos)));
        }
    }
}
/* End of pattern implementation */
random_t rnd;

/// @brief  在 [0, 2147483647] 范围内生成一个整数
/// @return 一个int正数范围内的随机整数
inline int randU() { return rnd.next(2147483648); }

/// @brief    在[fr, to]生成一个整数
/// @param fr int64类型，左区间 [fr
/// @param to int64类型，右区间 to]
/// @return   [fr, to]区间的一个随机整数
inline long long randL(const long long &fr, const long long &to) { return rnd.next(fr, to); }

/// @brief  在 int [-2147483648, 2147483647] 生成一个整数
/// @return 一个int范围内的随机整数
inline int randI() { return (int)rnd.next(-2147483648ll, 2147483647ll); }

/// @brief    在[fr, to)范围内生成一个实数
/// @param fr double类型，左区间 [fr
/// @param to double类型，右区间 to)
/// @return   [fr, to)区间的一个随机实数
inline double randF(const double &fr, const double &to) { return rnd.next(fr, to); }

/// @brief        自定义生成字符串
/// @param format 字符串生成规则 1) "ABC|CBA|ABCBA" 返回 "ABC" "CBA" "ABCBA" 中的任何一个;  2) "23{1,20}" 返回 "2333..333" ("3"的个数为1~20随机);  3) "[a-z, A-Z, 0-9, +-*/=]{1, 50}" 返回由字母数字和运算符组成的字符串(e.g. "az2+3lCDE=12/2/-3")
/// @return       根据format生成的随机字符串
inline std::string randS(const char *format) { return rnd.next(format); }

#endif