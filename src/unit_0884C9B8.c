/* unit_0884C9B8: 0x0884C9B8-0x0884CB24 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef float f32;

extern s32 D_089CBBE4;
extern s32 func_088160E8(s32, float *, f32);
extern s32 func_0884CBD8(s32, s32, char *, char *, s32);

static inline void vec_set(float *dst, float x, float y, float z, float w) {
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

void func_0884C9B8(s32 arg0, s32 arg1, char *arg2, s32 arg3) {
    float v[4] __attribute__((aligned(16)));
    f32 r;
    *(s32 *)(arg2 + 4) = (s32)(*(s32 *)(arg2 + 4) & ~2);
    if (!(arg3 & 0xFF)) {
        r = *(f32 *)(arg2 + 0x220);
        if (r < *(f32 *)(arg2 + 0x224)) {
            r = *(f32 *)(arg2 + 0x224);
        }
        if (r < *(f32 *)(arg2 + 0x228)) {
            r = *(f32 *)(arg2 + 0x228);
        }
        vec_set(v, *(f32 *)(arg2 + 0x200),
                *(f32 *)(arg2 + 0x204) + 0.5f * (r * *(f32 *)(*(char **)(arg2 + 0x50) + 0x14)),
                *(f32 *)(arg2 + 0x208), 0.0f);
        if (!(func_088160E8(D_089CBBE4, v, r * *(f32 *)(*(char **)(arg2 + 0x50) + 0xC)) & 0xFF)) {
            return;
        }
    }
    if (*(u8 *)(arg2 + 0x230) != 0xFF && (arg1 & 0xFF) == 5) {
        arg1 = 7;
    }
    if ((func_0884CBD8(arg0, arg1, arg2, arg2 + 0x200, arg3) & 0xFF) == 1) {
        *(s32 *)(arg2 + 4) = (s32)(*(s32 *)(arg2 + 4) | 2);
    }
}
