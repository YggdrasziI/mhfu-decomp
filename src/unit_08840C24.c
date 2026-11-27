/* unit_08840C24: 0x08840C24-0x08840E30 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

extern u8 func_088D6AC8(char *, s32);
extern s32 func_088DAE98(char *, s32);
extern s32 func_08840BC0(char *);
extern s16 D_0893B1BC[][4];

static inline f32 cos_vfpu(f32 x) {
    f32 r;
    f32 *pr = &r;
    f32 *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vcos.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

u32 func_08840C24(char *arg0, s32 arg1) {
    char *p = *(char **)(arg0 + 0x530);
    u32 col = 0xFF10C010;
    s16 step = 0;
    u8 k;
    u8 a;
    u8 b;
    f32 c;

    if (*(u16 *)(p + 0x624) == 0) {
        k = func_088D6AC8(p, 0x30);
        if (k != 0x7B) {
            if ((u8)func_088DAE98(p, 0x100) == 0) {
                switch (k) {
                case 0x7A: a = 0; break;
                case 0x7C: a = 2; break;
                case 0x7D: a = 3; break;
                default: a = 1; break;
                }
                switch ((s16)arg1) {
                case 0: a = (u8)(b = 0); break;
                case 1: b = 0; break;
                case 2: b = 1; break;
                }
                step = D_0893B1BC[b][a];
            }
        }
    }
    if (step == 0) {
        if ((u8)func_08840BC0(arg0) == 1) {
            step = 0x100;
        }
    }
    if (step != 0) {
        *(s16 *)(arg0 + 0x11A0) += step;
        c = cos_vfpu(0.0000958738f * (f32)*(s16 *)(arg0 + 0x11A0));
        col = ((u32)((s8)(c * -28.0f) + 0x2D) << 16) | 0xFF000000 | ((s8)(c * 15.0f) + 0xB1) << 8 | ((s8)(c * -72.0f) + 0x58);
    } else {
        *(s16 *)(arg0 + 0x11A0) = 0;
    }
    return col;
}
