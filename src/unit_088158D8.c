/* unit_088158D8: 0x088158D8-0x08815964 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern void func_08815964(s32);

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

static inline void vec_copy(float *dst, float *src) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

void func_088158D8(char *arg0, float *arg1, float *arg2, float arg3) {
    vec_set((float *)(arg0 + 0xB60), 0.0f, 1.0f, 0.0f, 0.0f);
    vec_copy((float *)(arg0 + 0x20), arg1);
    vec_copy((float *)(arg0 + 0x30), arg2);
    vec_copy((float *)(arg0 + 0xB40), arg1);
    vec_copy((float *)(arg0 + 0xB50), arg2);
    *(float *)(arg0 + 0xA8) = arg3;
    *(float *)(arg0 + 0xC) = arg3;
    func_08815964((s32)arg0);
}
