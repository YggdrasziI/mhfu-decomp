/* unit_0888AFEC: 0x0888AFEC-0x0888B1C0 (ULES01213)
 *
 * func_0888AFEC: VFPU asm block for the 16-byte copies (notes/COMPILER.md,
 * "VFPU in asm blocks"). Other values of the state byte at +0x9C return an
 * unset result, as in the original.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

extern char *D_089CBBE4;
extern char *D_089CC438;
extern s32 D_08938234[];

extern s32 func_0888B1C0(char *);

static inline void vec_copy(char *src, char *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

s32 func_0888AFEC(char *arg0) {
    char *g = D_089CBBE4;
    char *s1 = arg0 + 0xA0;
    s32 ret;
    u8 st;

    if (*(u8 *)(arg0 + 0x13A) != 0 && (*(u16 *)(g + 0xA72) & 1) &&
        *(u8 *)(D_089CC438 + 0x480) == 0) {
        return 1;
    }
    st = *(u8 *)(arg0 + 0x9C);
    switch (st) {
    case 0:
        arg0[0x9C] = st + 1;
        if (*(u8 *)(s1 + 0x4E) != 0xFF) {
            *(s32 *)(s1 + 0x40) = D_08938234[*(u8 *)(s1 + 0x4E)];
        }
        vec_copy(g + 0x20, arg0);
        vec_copy(g + 0x20, s1);
        vec_copy(g + 0x20, s1 + 0x10);
        vec_copy(g + 0x30, arg0 + 0x10);
        vec_copy(g + 0x30, s1 + 0x20);
        vec_copy(g + 0x30, s1 + 0x30);
        *(f32 *)(arg0 + 0x80) = *(f32 *)(g + 0xA0);
        *(f32 *)(arg0 + 0x88) = *(f32 *)(g + 0xA8);
        *(s16 *)(s1 + 0x64) = *(s16 *)(s1 + 0x66) = (s16)(10430.3779f * *(f32 *)(arg0 + 0x80));
        *(s16 *)(s1 + 0x68) = *(s16 *)(s1 + 0x6A) = (s16)(10430.3779f * *(f32 *)(arg0 + 0x88));
        *(s16 *)(s1 + 0x6E) = *(s16 *)(s1 + 0x76) = *(s16 *)(s1 + 0x7E) = *(s16 *)(s1 + 0x86) = 0;
        *(s32 *)(s1 + 0x8C) = 0;
        s1[0x98] = 0;
        *(f32 *)(s1 + 0x94) = 1.0f;
        s1[0x48] = 1;
        s1[0x49] = 5;
        s1[0x4A] = 4;
        s1[0x4D] = 0;
        *(s16 *)(s1 + 0x5C) = 0;
        *(s16 *)(s1 + 0x60) = 0;
        *(s16 *)(s1 + 0x5E) = 0;
        *(s16 *)(s1 + 0x62) = 0;
        *(f32 *)(s1 + 0x54) = 512.0f;
        *(f32 *)(s1 + 0x58) = 512.0f;
        *(s16 *)(arg0 + 0x94) = *(s16 *)(arg0 + 0x96) = -1;
    case 1:
        ret = func_0888B1C0(arg0);
        if (ret > 0) {
            *(u8 *)(arg0 + 0x9C) += 1;
            goto one;
        }
        break;
    case 2:
    one:
        return 1;
    }
    return ret;
}
