#include <stdio.h>
#include <stdlib.h>

#ifdef ONLINE_JUDGE
#define debug(...) 114514
#else
#define debug(...) fprintf(stderr, __VA_ARGS__)
#endif

const int N = 100005, M = 1000005;

// struct long {
//     long *l, *r;
//     int n, mx, size, cnt;
// };
// typedef struct long long;

int top = 0;

inline void pushup(long *u)
{
    u->size = u->cnt;
    if (u->l)
        u->size += u->l->size;
    if (u->r)
        u->size += u->r->size, u->mx = u->r->mx;
    else
        u->mx = u->n;
}

inline void rotate_left(long *__u)
{
    long *r = u->r;
    u->r = r->l, r->l = u;
    pushup(u), pushup(u = r);
}

inline void rotate_right(long *__u)
{
    long *l = u->l;
    u->l = l->r, l->r = u;
    pushup(u), pushup(u = l);
}

enum NodeStatus
{
    ROOT,
    LEFT,
    RIGHT
};

#define _Do_L(func)           \
    switch (func(u->l, x))    \
    {                         \
    case LEFT:                \
        rotate_right(u);      \
        rotate_right(u);      \
        return ROOT;          \
    case RIGHT:               \
        rotate_left(u->l); \
        rotate_right(u);      \
        return ROOT;          \
    default:                  \
        return LEFT;          \
    }
#define _Do_R(func)            \
    switch (func(u->r, x))     \
    {                          \
    case LEFT:                 \
        rotate_right(u->r); \
        rotate_left(u);        \
        return ROOT;           \
    case RIGHT:                \
        rotate_left(u);        \
        rotate_left(u);        \
        return ROOT;           \
    default:                   \
        return RIGHT;          \
    }
#define splay(func, u, x) \
    switch (func(u, x))   \
    {                     \
    case LEFT:            \
        rotate_right(u);  \
        break;            \
    case RIGHT:           \
        rotate_left(u);  \
        break;            \
    }

inline int insert(long *__u, const int x)
{
    if (!u)
    {
        // u = new long{0, 0, x, x, 1, 1};
        return ROOT;
    }
    if (x < u->n)
        _Do_L(insert);
    if (x == u->n)
    {
        ++u->cnt, ++u->size;
        return ROOT;
    }
    _Do_R(insert);
}

inline enum NodeStatus mv2x(long *__u, const int x)
{
    // debug("%d %d %d %d %d %d %d\n", *u, tr[*u].cnt, tr[*u].size, tr[*u].n, tr[*u].mx, tr[*u].l, tr[*u].r);
    if (u->l && x <= u->l->mx)
        _Do_L(mv2x);
    if (x <= u->n || !u->r)
        return ROOT;
    _Do_R(mv2x);
}

inline enum NodeStatus mv2kth(long *__u, int x)
{
    // debug("%d %d %d %d %d %d %d\n", *u, tr[*u].cnt, tr[*u].size, tr[*u].n, tr[*u].mx, tr[*u].l, tr[*u].r);
    if (u->l && x <= u->l->size)
        _Do_L(mv2kth);
    if (u->l)
        x -= u->l->size;
    if (x <= u->cnt)
        return ROOT;
    x -= u->cnt;
    _Do_R(mv2kth);
}

inline void erase(long *u, const int x)
{
    splay(mv2x, u, x);
    --u->cnt;
    if (!u->cnt)
    {
        splay(mv2kth, u->r, 1);
        u->r->l = u->l;
        long *to_delete = u;
        u = u->r;
        delete(to_delete);
    }
}

inline void in(int *x)
{
    register char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    for (*x = 0; ch >= '0' && ch <= '9'; ch = getchar())
        *x = (*x << 3) + (*x << 1) + (ch ^ '0');
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("P6136_11.in", "r", stdin);
    freopen("debug.txt", "wt", stderr);
#endif
    long *cur = nullptr;
    // cur = new long{0, 0, -1, -1, 1, 1};
    // cur = new long{cur, 0, 0x7fffffff, 0x7fffffff, 1, 0};
    pushup(cur);
    int n, m, ans = 0;
    in(__n), in(__m);
    for (int i = 1, ai; i <= n; i++)
    {
        in(__ai);
        splay(insert, cur, ai);
    }
    for (int opt, x, last_ans = 0; m--;)
    {
        in(__opt), in(__x), x ^= last_ans;
        switch (opt)
        {
        case 1:
            splay(insert, cur, x);
            break;
        case 2:
            erase(cur, x);
            break;
        case 3:
            splay(mv2x, cur, x);
            ans ^= last_ans = cur->l->size;
            break;
        case 4:
            splay(mv2kth, cur, x + 1);
            ans ^= last_ans = cur->n;
            break;
        case 5:
            splay(mv2x, cur, x);
            debug("%d %d ", cur, cur->n);
            splay(mv2x, cur->l, 0x7fffffff);
            ans ^= last_ans = cur->l->n;
            break;
        case 6:
            splay(mv2x, cur, x + 1);
            ans ^= last_ans = cur->n;
            break;
        }
        debug("(%d %d): ans=%d cur=%d\n", opt, x, last_ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}