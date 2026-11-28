/* func_0888B600: VFPU asm blocks (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef int s32;
typedef float f32;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec;

extern void func_08897BD8(Vec *arg0, Vec *arg1, Vec *arg2);

/* dst = src * s; the float goes through its own stack slot. */
static inline void vec_scale(Vec *src, Vec *dst, float s) {
    float *ps = &s;
    asm {
        lv.q C000, 0(src)
        lv.s S010, 0(ps)
        vscl.q C000, C000, S010
        sv.q C000, 0(dst)
    }
}

void func_0888B600(float s, s32 arg0, Vec *out, Vec *m) {
    vec_scale(m, out, s);
    func_08897BD8(out, out, m + 1);
    vec_scale(out, out, s);
    func_08897BD8(out, out, m + 2);
    vec_scale(out, out, s);
    func_08897BD8(out, out, m + 3);
}
