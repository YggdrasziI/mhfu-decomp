/* unit_08843A7C: 0x08843A7C-0x0884424C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08843A7C (ULES01213), 0x08843A7C-0x0884424C
 *
 * The call passes the two base coordinates as plain expressions; bx and by
 * are assigned from the same expressions after the call (common
 * subexpressions), bx first.
 *
 * Optimized for speed: float constants are built with lui/ori.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern char *D_089CC438;
extern f32 D_08938A7C[];
extern f32 D_0893897C[];
extern f32 D_08938980[];
extern char *D_09A4F060;
extern u16 *D_09CE470C[];
extern char *D_09C121B0;
extern s32 D_09A4F0C4;

extern void func_088444A4(char *, char *);
extern void func_0884469C(char *);
extern void func_08832B98(char *, s32);
extern void func_0884558C(char *, s16, s16, s32, s32, s16, s16, s16, s16, s32);
extern s32 func_088446CC(char *, u16);
extern void func_0882A9DC(char *, u16, u16, s32);
extern s32 func_08844578(char *, char *);
extern void func_08844744(char *, char *, f32, f32, f32);
extern char *func_088DCEBC(s32, s32);
extern void func_08844FC8(char *, s32, s32, f32, f32, f32);

static inline char *get_entry(char *base, s32 i) {
    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(char **)(base + 0x1220 + i * 4);
}

void func_08843A7C(char *arg0, s16 arg1, s16 arg2, f32 scale) {
    s32 idx;
    char *obj;
    s32 i;
    f32 ox;
    f32 oy;
    f32 ax;
    s16 ix;
    f32 lim;
    s16 iy;
    s16 ix2;
    s16 iy2;
    f32 ay;
    s16 dx;
    s32 bx;
    s32 by;
    f32 fx;
    f32 fy;
    char *q;
    s32 j;
    char *o;
    f32 base;

    idx = *(u8 *)(D_089CC438 + 0x6AF10);
    base = 0.5f * (1.0f - D_08938A7C[idx]);
    obj = *(char **)(arg0 + 0x530);
    func_088444A4(arg0, obj);
    func_0884469C(arg0);
    ax = 150.0f * (base + *(f32 *)(obj + 0x260) * *(f32 *)(arg0 + 0x564));
    ay = 150.0f * (base + *(f32 *)(obj + 0x268) * *(f32 *)(arg0 + 0x568));
    func_08832B98(arg0, 0);
    lim = 15.2f * scale;
    if (ax < lim) {
        ox = 0.0f;
    } else if (ax < 150.0f - lim) {
        ox = ax - lim;
    } else {
        ox = 150.0f - 30.4f * scale;
    }
    if (ay < lim) {
        oy = 0.0f;
    } else if (ay < 150.0f - lim) {
        oy = ay - lim;
    } else {
        oy = 150.0f - 30.4f * scale;
    }
    ix = ox;
    iy = oy;
    ix2 = ix + (30.4f * scale);
    iy2 = iy + (30.4f * scale);
    if (*(u8 *)(arg0 + 0x578)) {
        ix &= ~1;
        dx = 5.0f * scale * (ox - ix);
    } else {
        dx = 5.0f * scale * (ox - ix);
    }
    func_0884558C(arg0, arg1 - dx, arg2 - (s16)(5.0f * scale * (oy - iy)), (s32)(152.0f * scale), (s32)(152.0f * scale), ix, iy, ix2, iy2, 0xA0);
    bx = arg1 - dx;
    by = arg2 - (s16)(5.0f * scale * (oy - iy));
    func_08832B98(arg0, 1);
    if (*(u8 *)(arg0 + 0x578) == (u8)func_088446CC(arg0, *D_09CE470C[*(s32 *)(D_09A4F060 + 0x284) * 2])) {
        fx = 150.0f * (base + *(f32 *)(arg0 + 0x564) * D_0893897C[idx * 2]) - ix;
        if (fx >= 0.0f && fx <= (30.4f * scale)) {
            fy = 150.0f * (base + *(f32 *)(arg0 + 0x568) * D_08938980[idx * 2]) - iy;
            if (fy >= 0.0f && fy <= (30.4f * scale)) {
                fx = 152.0f * (5.0f * fx) / 150.0f + bx;
                fy = 152.0f * (5.0f * fy) / 150.0f + by;
                func_0882A9DC(arg0, fx - 6.0f, fy - 6.0f, 0x94);
            }
        }
    }
    for (i = 0; i < 20; i++) {
        q = get_entry(D_09C121B0, i);
        if ((u8)func_08844578(arg0, q)) {
            fx = 150.0f * (base + *(f32 *)(q + 0x260) * *(f32 *)(arg0 + 0x564)) - ix;
            if (fx < 0.0f || fx > (30.4f * scale)) {
                continue;
            }
            fy = 150.0f * (base + *(f32 *)(q + 0x268) * *(f32 *)(arg0 + 0x568)) - iy;
            if (fy < 0.0f || fy > (30.4f * scale)) {
                continue;
            }
            func_08844744(arg0, q, 152.0f * (5.0f * fx) / 150.0f + bx,
                          152.0f * (5.0f * fy) / 150.0f + by, 1.2f * scale);
        }
    }
    for (j = 0; j < 4; j++) {
        o = func_088DCEBC(D_09A4F0C4, j);
        if (o == 0) {
            continue;
        }
        if ((s32)((*(u32 *)(o + 4) & 1) != 0) == 0) {
            continue;
        }
        if (j == *(u8 *)(D_089CC438 + 0x28)) {
            continue;
        }
        if (*(u8 *)(arg0 + 0x578) != (u8)func_088446CC(arg0, *(u16 *)(o + 0x29A))) {
            continue;
        }
        fx = 150.0f * (base + *(f32 *)(o + 0x260) * *(f32 *)(arg0 + 0x564)) - ix;
        if (fx < 0.0f || fx > (30.4f * scale)) {
            continue;
        }
        fy = 150.0f * (base + *(f32 *)(o + 0x268) * *(f32 *)(arg0 + 0x568)) - iy;
        if (fy < 0.0f || fy > (30.4f * scale)) {
            continue;
        }
        func_08844FC8(arg0, *(u16 *)(o + 0x1F4), *(u16 *)(o + 0x1E6),
                      152.0f * (5.0f * fx) / 150.0f + bx,
                      152.0f * (5.0f * fy) / 150.0f + by, 1.0f);
    }
    obj = *(char **)(arg0 + 0x530);
    func_08844FC8(arg0, *(u16 *)(obj + 0x1F4), *(u16 *)(obj + 0x1E6),
                  (f32)arg1 + 152.0f * (5.0f * (ax - ox)) / 150.0f,
                  (f32)arg2 + 152.0f * (5.0f * (ay - oy)) / 150.0f, 1.2f);
    func_08832B98(arg0, 0);
}
