/* unit_08840F30: 0x08840F30-0x08841100 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off


typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern s16 D_0893B1BC[][4];

extern u8 func_088D6AC8(char *, s32);
extern s32 func_088DAE98(char *, s32);

static inline float cos_vfpu(float x) {
    float r;
    float *pr = &r;
    float *px = &x;
    asm {
        lv.s S000, 0(px)
        vcst.s S001, VFPU_2_PI
        vmul.s S000, S000, S001
        vcos.s S010, S000
        sv.s S010, 0(pr)
    }
    return r;
}

u32 func_08840F30(char *arg0, s16 arg1) {
    char *p;
    u32 col;
    s16 d;
    u8 k;
    u8 a;
    u8 b;

    p = *(char **)(arg0 + 0x530);
    col = 0xFFF0F000;
    d = 0;
    if (*(u16 *)(p + 0x626) == 0) {
        k = func_088D6AC8(p, 0x31);
        if (k != 0x7F) {
            if ((u8)func_088DAE98(p, 0x80) == 0) {
                switch (k) {
                case 0x7E: a = 0; break;
                case 0x80: a = 2; break;
                case 0x81: a = 3; break;
                default: a = 1; break;
                }
                switch (arg1) {
                case 3: b = 0; break;
                case 4: b = 1; break;
                }
                d = D_0893B1BC[b][a];
            }
        }
    }
    if (d != 0) {
        float ang;
        float c;
        ang = (s16)(*(s16 *)(arg0 + 0x11A2) += d);
        ang = 9.58738019e-05f * (float)ang;
        c = cos_vfpu(ang);
        col = ((s8)(58.0f * c) + 0xB6) << 16 | 0xFF000000 | ((s8)(102.0f * c) + 0x8A) << 8 |
              ((s8)(-21.0f * c) + 0x15);
    } else {
        *(s16 *)(arg0 + 0x11A2) = 0;
    }
    return col;
}
