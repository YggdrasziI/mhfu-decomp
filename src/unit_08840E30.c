/* unit_08840E30: 0x08840E30-0x08840F30 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off


typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern s32 func_08840BC0(char *arg0);

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

u32 func_08840E30(char *arg0) {
    u32 col = 0xFF10C010;
    float c;

    if ((func_08840BC0(arg0) & 0xFF) == 1) {
        *(s16 *)(arg0 + 0x11A0) += 0x100;
        c = cos_vfpu(9.58738e-05f * *(s16 *)(arg0 + 0x11A0));
        col = ((s8)(-72.0f * c) + 0x58) | (((s8)(-28.0f * c) + 0x2D) << 16 | 0xFF000000 | (((s8)(15.0f * c) + 0xB1) << 8));
    } else {
        *(s16 *)(arg0 + 0x11A0) = 0;
    }
    return col;
}
