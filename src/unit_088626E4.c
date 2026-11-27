/* unit_088626E4: 0x088626E4-0x08862710 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef float f32;

static inline void mtx_identity(f32 *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

void func_088626E4(char *p) {
    *(s32 *)(p + 0x4) = 3;
    *(s32 *)(p + 0x8) = 0;
    *(s32 *)(p + 0xC) = 0;
    mtx_identity((f32 *)(p + 0x10));
}
