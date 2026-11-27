/* unit_08815D64: 0x08815D64-0x08815D84 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

void func_08815D64(char *arg0, float *arg1, float *arg2, float arg3) {
    float *p;
    float *q;
    p = (float *)(arg0 + 0x20);
    asm {
        lv.q C000, 0(arg1)
        sv.q C000, 0(p)
    }
    q = (float *)(arg0 + 0x30);
    asm {
        lv.q C000, 0(arg2)
        sv.q C000, 0(q)
    }
    *(float *)(arg0 + 0xA8) = arg3;
}
