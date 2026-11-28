/* unit_088C8360: 0x088C8360-0x088C83F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between other units.
 */

/* func_088C8360: builds a translation matrix from a vector (identity by
 * VFPU `vmidt.q` in an `asm` block, notes/COMPILER.md), applies it, then
 * calls func_0886171C and applies the matrix at 0x10 of the object.
 */

typedef int s32;

typedef struct Mtx {
    float m[16];
} Mtx;

extern void func_08862354(float *, char *);
extern void func_0886171C(char *, s32, char *, s32);

static inline void mtx_identity(Mtx *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void mtx_translate(Mtx *dst, float x, float y, float z) {
    mtx_identity(dst);
    dst->m[12] = x;
    dst->m[13] = y;
    dst->m[14] = z;
}

void func_088C8360(char *arg0, char *arg1, float *arg2, s32 arg3) {
    Mtx m;

    mtx_translate(&m, arg2[0], arg2[1], arg2[2]);
    func_08862354(m.m, arg1 + 0x10);
    func_0886171C(arg1, 0, arg0 + 0x70, arg3);
    func_08862354((float *)(arg0 + 0x10), arg1 + 0x10);
}
