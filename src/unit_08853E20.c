/* unit_08853E20: 0x08853E20-0x088542EC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

/* func_08853E20: fills 31 per-slot records (value, two scaled values, two
 * 2-bit ranks against D_08930BDC thresholds, a flag), then a 0..6 grade.
 * D_0899CB60 is const: its reloaded byte is scheduled before the bit-field
 * store only then.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    s16 lo;
    s16 mid;
    s16 hi;
    u8 pad[4];
} Entry;

typedef struct {
    u8 got : 1;
    u8 rankA : 2;
    u8 rankB : 2;
    u8 : 3;
    u8 pad1;
    u16 val : 14;
    u16 : 2;
    u16 a;
    u16 b;
} Rec;

typedef struct {
    u8 id;
    u8 pad;
} Key;

typedef struct {
    char pad[0x678A8];
    Rec rec[31];
} Big;

extern const Key D_0899CB60[];
extern u8 D_0899CBA0[];
extern Entry D_08930BDC[];
extern char *D_089CC438;

extern u16 func_08850520(char *, u8);
extern u16 func_0885028C(char *, u8, u8 *);
extern u16 func_08850338(char *, u8, u8 *);
extern float func_08850238(char *, u8, u16);
extern s32 func_08852F1C(char *, u8);
extern s32 func_088552E0(char *);

void func_08853E20(char *p) {
    s32 i;
    u16 v;
    u16 w;
    s32 r;
    u8 buf;
    Rec *rec;

    *(u16 *)(p + 0x6776A) = *(u8 *)(p + 0x4C1);
    *(u16 *)(p + 0x6776C) = *(u16 *)(p + 0x4C2);
    *(u16 *)(p + 0x6776E) = *(u16 *)(p + 0x4CE);
    *(u16 *)(p + 0x67770) = *(u16 *)(p + 0x4DA);
    *(u16 *)(p + 0x67772) = *(u16 *)(p + 0x4E6);
    *(u16 *)(p + 0x67774) = *(u16 *)(p + 0x4F2);
    *(u16 *)(p + 0x67776) = *(u16 *)(p + 0x4FE);
    for (i = 0; i < 31; i++) {
        ((Big *)p)->rec[i].val = func_08850520(p, D_0899CB60[i].id);
        v = func_0885028C(p, D_0899CB60[i].id, &buf);
        ((Big *)p)->rec[i].a = (u32)((func_08850238(p, buf, v) + 0.05f) * 10.0f);
        if (v <= D_08930BDC[D_0899CBA0[i]].hi) {
            ((Big *)p)->rec[i].rankA = 3;
        } else if (v >= D_08930BDC[D_0899CBA0[i]].mid) {
            ((Big *)p)->rec[i].rankA = 2;
        } else if (v >= D_08930BDC[D_0899CBA0[i]].lo) {
            ((Big *)p)->rec[i].rankA = 1;
        } else {
            ((Big *)p)->rec[i].rankA = 0;
        }
        w = func_08850338(p, D_0899CB60[i].id, &buf);
        ((Big *)p)->rec[i].b = (u32)((func_08850238(p, buf, w) + 0.05f) * 10.0f);
        if (w <= D_08930BDC[D_0899CBA0[i]].hi) {
            ((Big *)p)->rec[i].rankB = 3;
        } else if (w >= D_08930BDC[D_0899CBA0[i]].mid) {
            ((Big *)p)->rec[i].rankB = 2;
        } else if (w >= D_08930BDC[D_0899CBA0[i]].lo) {
            ((Big *)p)->rec[i].rankB = 1;
        } else {
            ((Big *)p)->rec[i].rankB = 0;
        }
        if (func_08852F1C(D_089CC438, D_0899CBA0[i])) {
            ((Big *)p)->rec[i].got = 1;
        }
    }
    *(u8 *)(p + 0x677EF) = *(u8 *)(p + 0x44BC);
    r = func_088552E0(p);
    if (r >= 0x164) {
        *(u8 *)(p + 0x677F0) = 6;
    } else if (r >= 0x10F) {
        *(u8 *)(p + 0x677F0) = 5;
    } else if (r >= 0xC0) {
        *(u8 *)(p + 0x677F0) = 4;
    } else if (r >= 0xA7) {
        *(u8 *)(p + 0x677F0) = 3;
    } else if (r >= 0x7A) {
        *(u8 *)(p + 0x677F0) = 2;
    } else if (r >= 0x46) {
        *(u8 *)(p + 0x677F0) = 1;
    } else {
        *(u8 *)(p + 0x677F0) = 0;
    }
}
