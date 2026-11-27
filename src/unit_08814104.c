/* unit_08814104: 0x08814104-0x08814114 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

void func_08814104(char *arg0, float *arg1) {
    float *p = (float *)(arg0 + 0xB60);
    asm {
        lv.q C000, 0(p)
        sv.q C000, 0(arg1)
    }
}
