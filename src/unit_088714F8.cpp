/* unit_088714F8: 0x088714F8-0x0887184C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08870D40 and text_0887184C).
 *
 * C++: virtual call. Optimized for speed (the getter's index becomes an
 * induction variable). The initializers of the three local tables
 * (0x089A82D0-0x089A853C) would be the unit's .data; they stay in the data
 * piece while the function does not match.
 *
 * NonMatching: func_088714F8 99.3 %. The two table searches: the original's
 * loop is `lhu; bnel id, v0, top` with the increment in the delay slot (no
 * guard); ours leaves with `bne` and steps back (this form), or adds a guard
 * (`while`), or exits through `beql` (`for`, `goto`, `do`, inline helper).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct V40 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); } V40;

typedef struct {
    u16 id;
    u16 pad;
    float pos[3];
    s32 v;
} Spot;

extern "C" {

extern char *D_089CC438;
extern char *D_09C121B0;

extern char *func_088697D4(char *, u16, s32, s8);
extern int func_09AB2958(char *, char *);
extern u16 func_0886B8DC(char *);
extern void func_09AB2DD8(char *, s32, float *, s32);

static inline V40 *get_obj(s32 i) {
    char *base = D_09C121B0;

    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(V40 **)(base + 0x1220 + i * 4);
}

static inline int in_first(char *p, u16 id) {
    if (!(*(u32 *)(p + 0x28) & 0x1000010) && (id == 0x29 || id == 0xC2 || id == 0x36 || id == 0x94 || id == 0x10 || id == 0x97 || id == 0x1 ||
        id == 0x6E || id == 0x5C || id == 0x65 || id == 0xCD || id == 0xE3)) {
        return 1;
    }
    return 0;
}

static inline int in_second(char *p, u16 id) {
    if ((*(u32 *)(p + 0x28) & 0x10) && (id == 0x15 || id == 0x8C || id == 0x97 || id == 0xA1 || id == 0x6E || id == 0x62 || id == 0xF7)) {
        return 1;
    }
    return 0;
}

void func_088714F8(char *arg0) {
    Spot t1[7] = {
        {0x15, 0, {10238.0f, 41.0f, 10233.0f}, 0x5A39},
        {0x8C, 0, {7800.0f, 4720.0f, 13710.0f}, 0x717A},
        {0x97, 0, {10411.0f, 400.0f, 8654.0f}, 0xBFEC},
        {0xA1, 0, {9038.0f, 1.0f, 7978.0f}, 0x65D2},
        {0x6E, 0, {10348.0f, -76.0f, 12031.0f}, 0x8158},
        {0x62, 0, {14798.0f, 1162.0f, 15296.0f}, 0xE91B},
        {0xF7, 0, {9280.0f, 14.0f, 11000.0f}, 0x9863},
    };
    Spot t2[12] = {
        {0x29, 0, {11044.0f, 20.0f, 10898.0f}, 0x38E4},
        {0xC2, 0, {11044.0f, 20.0f, 10898.0f}, 0x38E4},
        {0x36, 0, {6279.0f, 9.0f, 6038.0f}, 0xEE35},
        {0x94, 0, {6279.0f, 9.0f, 6038.0f}, 0xEE35},
        {0x97, 0, {6511.0f, -44.0f, 10372.0f}, 0x38E4},
        {0x10, 0, {6511.0f, -44.0f, 10372.0f}, 0x38E4},
        {0x1, 0, {10085.0f, 2664.0f, 9033.0f}, 0x1841},
        {0x6E, 0, {10085.0f, 2664.0f, 9033.0f}, 0x1841},
        {0x5C, 0, {11201.0f, 550.0f, 6665.0f}, 0x82DE},
        {0x65, 0, {11201.0f, 550.0f, 6665.0f}, 0x82DE},
        {0xCD, 0, {10250.0f, 0.0f, 8100.0f}, 0xFE70},
        {0xE3, 0, {10687.0f, 0.0f, 8568.0f}, 0xAB0},
    };
    Spot t3[12] = {
        {0x29, 0, {10230.0f, 20.0f, 9827.0f}, 0x38E4},
        {0xC2, 0, {10230.0f, 20.0f, 9827.0f}, 0x38E4},
        {0x36, 0, {7586.0f, -3.0f, 6021.0f}, 0x31B2},
        {0x94, 0, {7586.0f, -3.0f, 6021.0f}, 0x31B2},
        {0x97, 0, {8509.0f, -18.0f, 8174.0f}, 0x133D},
        {0x10, 0, {8509.0f, -18.0f, 8174.0f}, 0x133D},
        {0x1, 0, {10260.0f, 2780.0f, 10374.0f}, 0x5BF},
        {0x6E, 0, {10260.0f, 2780.0f, 10374.0f}, 0x5BF},
        {0x5C, 0, {9554.0f, 150.0f, 10634.0f}, 0x7E18},
        {0x65, 0, {9554.0f, 150.0f, 10634.0f}, 0x7E18},
        {0xCD, 0, {10300.0f, 0.0f, 9400.0f}, 0xA89C},
        {0xE3, 0, {11446.0f, 0.0f, 8113.0f}, 0xE32A},
    };
    s32 i;
    u16 id;
    V40 *obj;
    char *e;
    Spot *s;

    id = *(u16 *)(D_089CC438 + 0x6AF0E);
    for (i = 0; i < 20; i++) {
        obj = get_obj(i);
        if (obj != 0) {
            obj->vfunc_40();
        }
    }
    e = func_088697D4(arg0, id, 1, *(s8 *)(arg0 + 0x20));
    if (e != 0) {
        for (;;) {
            if (*(s16 *)e < 0) {
                break;
            }
            if (!(*(s16 *)(e + 0x2E) & 1)) {
                if (func_09AB2958(D_09C121B0, e) == 0) {
                    break;
                }
                *(u16 *)(e + 8) = *(u16 *)(D_089CC438 + 0x6AF0E);
            }
            e += 0x3C;
        }
    }
    if (in_first(arg0, id)) {
        s = (func_0886B8DC(arg0) & 1) ? t2 : t3;
        do {
        } while (id != (s++)->id);
        s--;
        func_09AB2DD8(D_09C121B0, 0xA, s->pos, s->v);
    }
    if (in_second(arg0, id)) {
        s = t1;
        do {
        } while (id != (s++)->id);
        s--;
        func_09AB2DD8(D_09C121B0, 0x4A, s->pos, s->v);
    }
}

}