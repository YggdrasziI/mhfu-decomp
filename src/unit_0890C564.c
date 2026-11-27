/* unit_0890C564: 0x0890C564-0x0890C6C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890C564 (ULES01213)
 *
 * The 32-bit value after the first byte of the record returned by
 * func_0890C6C8 is read byte by byte (little-endian) by a static inline
 * helper that returns the pointer past it; the first byte goes through a
 * u32 local to keep the `or` operand order.
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
} Info;

typedef struct {
    s32 unk0;
    s32 unk4;
} Pair;

typedef struct {
    char *unk0;
    s32 *unk4;
    s32 unk8;
    s32 unkC;
    u32 unk10;
    s32 unk14;
    char *unk18;
} State;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec;

extern void func_0890D7BC(u32, Info *);
extern void func_0890C224(void);
extern void func_0890DB88(State *, Info *);
extern s32 func_0890CBC0(State *, Info *);
extern u8 *func_0890C6C8(State *, Info *, Pair *);
extern s32 func_0890C3F4(s32, s32 *);
extern void func_0890C490(s32, s32 *);
extern void func_0890CD14(State *, Info *, u8 *);
extern void func_0890D95C(State *, Info *, u32);

static inline u8 *rd(u8 *q, s32 *out) {
    u32 lo = q[0];
    *out = lo | (q[1] << 8) | (q[2] << 16) | (q[3] << 24);
    return q + 4;
}

void func_0890C564(State *s) {
    Info info;
    s32 b;
    s32 a;
    Pair pr;
    u8 *p;
    u8 *q;
    Rec *r;
    s32 off;

    func_0890D7BC(s->unk10, &info);
    if (info.unk4 == 0) {
        func_0890C224();
    }
    func_0890DB88(s, &info);
    if (s->unk0 == 0) {
        s->unkC = func_0890CBC0(s, &info);
    } else {
        s->unkC = 0;
    }
    p = func_0890C6C8(s, &info, &pr);
    q = rd(p + 1, &pr.unk4);
    pr.unk4 = pr.unk4 != 0 ? pr.unk4 : 0;
    func_0890C490(func_0890C3F4((s32)q, &a), &b);
    func_0890CD14(s, &info, p);
    off = pr.unk0;
    r = (Rec *)((s32)b + s->unk18);
    r->unk0 = (s32)s->unk4;
    r->unk4 = (s32)s->unk0;
    r->unk8 = s->unk8;
    if (*s->unk0 == 42) {
        r->unkC = (s32)&r->unk10;
        r->unk10 = *s->unk4 + off;
    } else {
        r->unkC = (s32)s->unk4 + off;
    }
    func_0890D95C(s, &info, (u32)((char *)info.unk0 + a));
}
