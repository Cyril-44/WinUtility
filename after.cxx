#include <stdio.h>
#include <stdlib.h>

#ifdef ONLINE_JUDGE
#define debug(...) 114514
#else
#define debug(...) fprintf(stderr, __VA_ARGS__)
#endif

const int xFCT_wKK = 100005, xH6vXdI0 = 1000005;

struct Node {
    Node *x2mWNv76, *xTLR0NfX;
    int xcm870N2, xn4kUY2s, size, cnt;
};
typedef struct Node Node;

int xR0YsDxl = 0;

inline void x3ds9x_f(Node *xpcOUXx1)
{
    xpcOUXx1->size = xpcOUXx1->cnt;
    if (xpcOUXx1->x2mWNv76)
        xpcOUXx1->size += xpcOUXx1->x2mWNv76->size;
    if (xpcOUXx1->xTLR0NfX)
        xpcOUXx1->size += xpcOUXx1->xTLR0NfX->size, xpcOUXx1->xn4kUY2s = xpcOUXx1->xTLR0NfX->xn4kUY2s;
    else
        xpcOUXx1->xn4kUY2s = xpcOUXx1->xcm870N2;
}

inline void xZJqGmBa(Node *xpcOUXx1)
{
    Node *xTLR0NfX = xpcOUXx1->xTLR0NfX;
    xpcOUXx1->xTLR0NfX = xTLR0NfX->x2mWNv76, xTLR0NfX->x2mWNv76 = xpcOUXx1;
    x3ds9x_f(xpcOUXx1), x3ds9x_f(xpcOUXx1 = xTLR0NfX);
}

inline void x1weO6Lf(Node *xpcOUXx1)
{
    Node *x2mWNv76 = xpcOUXx1->x2mWNv76;
    xpcOUXx1->x2mWNv76 = x2mWNv76->xTLR0NfX, x2mWNv76->xTLR0NfX = xpcOUXx1;
    x3ds9x_f(xpcOUXx1), x3ds9x_f(xpcOUXx1 = x2mWNv76);
}

enum xZ99Lymw
{
    xX_1VE41,
    xiMsjGM2,
    xgAXKOsi
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

inline int xDt_xPd2(Node *xiFHILMt, const int xhzo2JzL)
{
    if (!xpcOUXx1)
    {
        // u = new Node{0, 0, x, x, 1, 1};
        return xX_1VE41;
    }
    if (xhzo2JzL < xpcOUXx1->xcm870N2)
        _Do_L(xDt_xPd2);
    if (xhzo2JzL == xpcOUXx1->xcm870N2)
    {
        ++xpcOUXx1->cnt, ++xpcOUXx1->size;
        return xX_1VE41;
    }
    _Do_R(xDt_xPd2);
}

inline enum xZ99Lymw xOjyyXT5(Node *xiFHILMt, const int xhzo2JzL)
{
    // debug("%d %d %d %d %d %d %d\n", *u, tr[*u].cnt, tr[*u].size, tr[*u].n, tr[*u].xn4kUY2s, tr[*u].l, tr[*u].r);
    if (xpcOUXx1->x2mWNv76 && xhzo2JzL <= xpcOUXx1->x2mWNv76->xn4kUY2s)
        _Do_L(xOjyyXT5);
    if (xhzo2JzL <= xpcOUXx1->xcm870N2 || !xpcOUXx1->xTLR0NfX)
        return xX_1VE41;
    _Do_R(xOjyyXT5);
}

inline enum xZ99Lymw x4IgA28E(Node *xiFHILMt, int xhzo2JzL)
{
    // debug("%d %d %d %d %d %d %d\n", *u, tr[*u].cnt, tr[*u].size, tr[*u].n, tr[*u].xn4kUY2s, tr[*u].l, tr[*u].r);
    if (xpcOUXx1->x2mWNv76 && xhzo2JzL <= xpcOUXx1->x2mWNv76->size)
        _Do_L(x4IgA28E);
    if (xpcOUXx1->x2mWNv76)
        xhzo2JzL -= xpcOUXx1->x2mWNv76->size;
    if (xhzo2JzL <= xpcOUXx1->cnt)
        return xX_1VE41;
    xhzo2JzL -= xpcOUXx1->cnt;
    _Do_R(x4IgA28E);
}

inline void xQ5iUWuR(Node *xpcOUXx1, const int xhzo2JzL)
{
    splay(xOjyyXT5, xpcOUXx1, xhzo2JzL);
    --xpcOUXx1->cnt;
    if (!xpcOUXx1->cnt)
    {
        splay(x4IgA28E, xpcOUXx1->xTLR0NfX, 1);
        xpcOUXx1->xTLR0NfX->x2mWNv76 = xpcOUXx1->x2mWNv76;
        Node *xtkyBOAU = xpcOUXx1;
        xpcOUXx1 = xpcOUXx1->xTLR0NfX;
        delete(xtkyBOAU);
    }
}

inline void xiHQf9GC(int *xhzo2JzL)
{
    register char x_G01r8N = xRWWsPpm();
    while (x_G01r8N < '0' || x_G01r8N > '9')
        x_G01r8N = xRWWsPpm();
    for (*xhzo2JzL = 0; x_G01r8N >= '0' && x_G01r8N <= '9'; x_G01r8N = xRWWsPpm())
        *xhzo2JzL = (*xhzo2JzL << 3) + (*xhzo2JzL << 1) + (x_G01r8N ^ '0');
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("P6136_11.in", "r", stdin);
    freopen("debug.txt", "wt", stderr);
#endif
    Node *xn1F8o0R = xGS6356I;
    // cur = new Node{0, 0, -1, -1, 1, 1};
    // cur = new Node{cur, 0, 0x7fffffff, 0x7fffffff, 1, 0};
    x3ds9x_f(xn1F8o0R);
    int xcm870N2, xe4sOO_5, xkNJvyYg = 0;
    xiHQf9GC(__n), xiHQf9GC(__m);
    for (int xpq65gvN = 1, xEkdWn6L; xpq65gvN <= xcm870N2; xpq65gvN++)
    {
        xiHQf9GC(__ai);
        splay(xDt_xPd2, xn1F8o0R, xEkdWn6L);
    }
    for (int xnAFhmlK, xhzo2JzL, x46XT3LT = 0; xe4sOO_5--;)
    {
        xiHQf9GC(__opt), xiHQf9GC(__x), xhzo2JzL ^= x46XT3LT;
        switch (xnAFhmlK)
        {
        case 1:
            splay(xDt_xPd2, xn1F8o0R, xhzo2JzL);
            break;
        case 2:
            xQ5iUWuR(xn1F8o0R, xhzo2JzL);
            break;
        case 3:
            splay(xOjyyXT5, xn1F8o0R, xhzo2JzL);
            xkNJvyYg ^= x46XT3LT = xn1F8o0R->x2mWNv76->size;
            break;
        case 4:
            splay(x4IgA28E, xn1F8o0R, xhzo2JzL + 1);
            xkNJvyYg ^= x46XT3LT = xn1F8o0R->xcm870N2;
            break;
        case 5:
            splay(xOjyyXT5, xn1F8o0R, xhzo2JzL);
            debug("%d %d ", xn1F8o0R, xn1F8o0R->xcm870N2);
            splay(xOjyyXT5, xn1F8o0R->x2mWNv76, 0x7fffffff);
            xkNJvyYg ^= x46XT3LT = xn1F8o0R->x2mWNv76->xcm870N2;
            break;
        case 6:
            splay(xOjyyXT5, xn1F8o0R, xhzo2JzL + 1);
            xkNJvyYg ^= x46XT3LT = xn1F8o0R->xcm870N2;
            break;
        }
        debug("(%d %d): ans=%d cur=%d\n", xnAFhmlK, xhzo2JzL, x46XT3LT, xn1F8o0R);
    }
    printf("%d\n", xkNJvyYg);
    return 0;
}
