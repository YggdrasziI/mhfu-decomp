/* unit_088655E0: 0x088655E0-0x088655F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Writes the 4x4 identity matrix to dst (VFPU).
 */

void func_088655E0(float *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}
