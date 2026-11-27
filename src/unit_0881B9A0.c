/* unit_0881B9A0: 0x0881B9A0-0x0881BF80 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881B9A0 (ULES01213)
 *
 * Speed setting (the 2*pi/65536 constant is built with lui/ori) and
 * opt_strength_reduction off (the 6-byte inner loops recompute e + i).
 * The sine is VFPU code in an asm block (static inline helper). Register
 * allocation: one s16 local (x) reused for the first row x, the row y of the
 * entry loop and the column x of the grid; the 5-entry loop counter reused
 * for the first inner loop; declaration order from a scripted search.
 */

#pragma optimize_for_size off
#pragma opt_strength_reduction off
typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_08A631A8;
extern char *D_08A631A0;
extern char *D_089CC438;
extern u16 D_089AC8D8;
extern u16 D_089AC8DC;
extern char D_08938478[];
extern u8 D_089385A0[];
extern char D_089385A8[];
extern char D_089385B0[];
extern u8 D_0893AEAC[];
extern s32 D_0893AEB8[];
extern u16 D_089ACC70[];

extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern char *func_0885151C(char *, u16);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);
extern s32 func_0883029C(char *, u8 *, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern int func_088915B0(char *, s16, s16, s8, char *, ...);
extern void func_0889183C(char *, s16, s16, s8, char *, ...);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_0882D8DC(char *, u16, u16, u16, u16, s32, s32, s32, s32);

static inline float sin_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vsin.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

void func_0881B9A0(char *arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, s32 arg5, u8 arg6) {
    s32 m2;
    u8 *e;
    s16 x;
    s32 i;
    s16 hidden;
    s16 shown;
    s32 y0;
    s32 *t;
    s32 total;
    s32 j;
    s32 n;
    s32 m3;
    s16 cx1;
    s16 cx2;
    s16 y;
    s8 c;
    float s;
    u8 a;
    u32 phase;
    float ang;

    func_08890DE8(D_08A631A8, 0xC, 0xE);
    func_08890E38(D_08A631A8, 5);
    func_08891474(D_08A631A8, arg1, arg2, D_08938478, func_0885151C(D_089CC438, D_089AC8D8));
    x = arg1 + 0x45;
    y = arg2 - 2;
    if (arg6 < 7) {
        phase = (u16)((*(s32 *)(D_08A631A0 + 0xF7A554) & 0x1F) << 11);
        ang = phase;
        ang = 9.58737992e-05f * (float)ang;
        s = sin_vfpu(ang);
        a = (s8)(31.0f * s) + 0xDF;
        func_0882BE60(arg0, (s16)(x - 3 + D_089385A0[arg6] * 24), y + 1, 0x17, 0x11, a, a,
                      (s8)(32.0f * s) + 0x20, 0x1A6);
    }
    func_0882A9DC(arg0, x, y, func_0883029C(arg0, (u8 *)(arg0 + 0xE1C), 1));
    for (i = 0, t = D_0893AEB8; i < 5; i++, t++) {
        x += 0x18;
        func_0882A9DC(arg0, x, y, D_0893AEAC[*t + 5]);
    }
    shown = hidden = 0;
    e = (u8 *)(arg0 + arg3 * arg5 * 18 + 0x684);
    y0 = arg2 + 0x10;
    x = (s16)y0;
    for (j = 0; j < arg5; j++, e += 0x12) {
        if (e[2] == 0) {
            break;
        }
        if (!(e[2] & 2)) {
            shown++;
            func_08890DE8(D_08A631A8, 0xC, 0xE);
            if (e[2] & 1) c = 3; else c = 0;
            func_088915B0(D_08A631A8, arg1, x, c, D_08938478, func_0885151C(D_089CC438, D_089ACC70[e[3]]));
            func_08890DE8(D_08A631A8, 0xE, 0xE);
            cx1 = arg1 + 0x42;
            for (i = 0; i < 6; i++, cx1 += 0x18) {
                if (((s8 *)e)[4 + i] != 0) {
                    func_0889183C(D_08A631A8, cx1, x, ((s8 *)e)[0xB + i], D_089385A8, ((s8 *)e)[4 + i]);
                }
            }
            func_0889183C(D_08A631A8, cx1, x, ((s8 *)e)[0x11], D_089385B0, ((s8 *)e)[0xA]);
        } else {
            hidden++;
            func_08890E38(D_08A631A8, -1);
            func_08890DE8(D_08A631A8, 0xC, 0xE);
            func_088920A8(D_08A631A8, arg1, x, D_08938478, func_0885151C(D_089CC438, D_089ACC70[e[3]]));
            func_08890DE8(D_08A631A8, 0xE, 0xE);
            cx2 = arg1 + 0x42;
            for (m2 = 0; m2 < 6; m2++, cx2 += 0x18) {
                if (((s8 *)e)[4 + m2] != 0) {
                    func_08891474(D_08A631A8, cx2, x, D_08938478, func_0885151C(D_089CC438, D_089AC8DC));
                }
            }
        }
        x += 0x10;
    }
    total = shown;
    if (total > 0) {
        y = (s16)y0;
        for (n = total + hidden; n > 0; n--) {
            x = arg1 + 0x40;
            for (m3 = 7; m3 > 0; m3--) {
                func_0882D6F0(arg0, x, y, 1, 0xB, 0x50, 0x50, 0x50);
                x += 0x18;
            }
            y += 0x10;
        }
        if (arg4 == 1) {
            func_0882D8DC(arg0, arg1 + 0x71, (s16)y0 - 2, 0x17, total << 4, 0, 0x3E, 0x74, 0xB2);
        }
    }
}
