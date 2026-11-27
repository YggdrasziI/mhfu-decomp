/* unit_088623DC: 0x088623DC-0x08862510 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

extern s32 func_088627AC(char *);
extern char *func_0886272C(char *, s32);

static inline void vec_set(char *dst, float x, float y, float z, float w) {
    float *px = &x;
    float *py = &y;
    float *pz = &z;
    float *pw = &w;
    asm {
        lv.s S000, 0(px)
        lv.s S001, 0(py)
        lv.s S002, 0(pz)
        lv.s S003, 0(pw)
        sv.q C000, 0(dst)
    }
}

s32 func_088623DC(char *arg0, void *arg1, void *arg2, s32 arg3) {
    s32 i;
    s32 j;
    char *e;
    char *p;
    char *dst;
    char *src;

    p = arg2;
    *(char **)(arg0 + 0x0) = p;
    *(s32 *)(arg0 + 0x4) = arg3;
    vec_set(arg0 + 0x10, *(f32 *)(p + 0x10), *(f32 *)(p + 0x14),
            *(f32 *)(p + 0x18), 0.0f);
    dst = arg1;
    *(char **)(arg0 + 0x8) = dst;
    src = p + *(s32 *)(p + 0x30);
    for (i = 0; i < func_088627AC(p); i++) {
        *(s32 *)(dst + 0x0) = *(s32 *)(src + 0x0);
        *(s32 *)(dst + 0x4) = *(s32 *)(src + 0x4);
        *(u8 *)(dst + 0x8) = *(u8 *)(src + 0x8);
        dst += 0x10;
        src += 0x10;
    }
    *(char **)(arg0 + 0xC) = dst;
    e = func_0886272C(p, 0);
    for (j = 0; j < *(u16 *)(p + 0x1C); j++) {
        *(s32 *)(dst + 0x0) = *(s32 *)(e + 0x8);
        *(s32 *)(dst + 0x4) = *(s32 *)(e + 0xC);
        dst += 8;
        e += 0x18;
    }
    return 1;
}
