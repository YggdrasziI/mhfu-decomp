/* unit_08865E94: 0x08865E94-0x08865EC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08865E94: VFPU asm block (notes/COMPILER.md, "VFPU in asm blocks"). */

void func_08865E94(char *arg0) {
    char *a = arg0 + 0x200;
    char *b = arg0 + 0x240;
    char *c = arg0 + 0x250;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        lv.q C020, 0(c)
        vadd.t C010, C010, C020
        vadd.t C000, C000, C010
        sv.q C010, 0(b)
        sv.q C000, 0(a)
    }
}
