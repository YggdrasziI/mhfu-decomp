/* unit_0890CBC0: 0x0890CBC0-0x0890CD14 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890CBC0 (ULES01213), 0x154 bytes.
 *
 * C++: the iterator (0x18) and context copy (0x138) are one stack structure
 * whose address is passed to func_0890D4C4; that aliasing keeps the
 * word-by-word copies unscheduled. The jump table is jtbl_089331DC (16 words).
 */

typedef int s32;
typedef unsigned char u8;
typedef float f32;

typedef struct {
    s32 w0;
    s32 w4;
    u8 *action;
    s32 wC;
    s32 w10;
    f32 f14;
} Iter;

typedef struct {
    s32 w[2];
} Pair;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    char *base;
    s32 w1C;
    Pair regs[35];
} Ctx;

typedef struct {
    Iter it;
    Ctx c;
} State;

extern "C" {
extern void func_0890C224(void);
extern u8 func_0890D4C4(State *);
extern char *func_0890C490(char *, s32 *);

static inline u8 get_action(State *s) {
    return s->it.action ? (*s->it.action & 0x1F) : 0;
}

s32 *func_0890CBC0(Ctx *ctx, Iter *src) {
    State s;
    s32 off;
    s32 *p;
    u8 a;

    s.it = *src;
    s.c = *ctx;
    a = get_action(&s);
    for (;;) {
        switch (a) {
        default:
        case 1:
        case 14:
            func_0890C224();
            goto out;
        case 0: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
        case 9: case 10: case 11: case 12: case 15:
            a = func_0890D4C4(&s);
            continue;
        case 13:
            goto out;
        }
    }
out:
    func_0890C490((char *)s.it.action + 1, &off);
    p = (s32 *)(s.c.base + off);
    ctx->w0 = p[1];
    ctx->w4 = p[0];
    ctx->w8 = 0;
    ctx->wC = (s32)p;
    return p;
}
}
