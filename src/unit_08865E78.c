/* func_08865E78: VFPU asm block (notes/COMPILER.md, "VFPU in asm blocks"). */

void func_08865E78(char *arg0) {
    char *a = arg0 + 0x200;
    char *b = arg0 + 0x240;
    asm {
        lv.q C000, 0(a)
        lv.q C010, 0(b)
        vadd.t C000, C000, C010
        sv.q C000, 0(a)
    }
}
