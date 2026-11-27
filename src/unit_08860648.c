/* unit_08860648: 0x08860648-0x088606D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

void func_08860648(char *arg0) {
    char *c = arg0 + 0x50;
    char *a = arg0 + 0x10;
    char *b = arg0 + 0x90;
    asm {
        lv.q C100, 0(a)
        lv.q C110, 0x10(a)
        lv.q C120, 0x20(a)
        lv.q C130, 0x30(a)
        lv.q C200, 0(b)
        lv.q C210, 0x10(b)
        lv.q C220, 0x20(b)
        lv.q C230, 0x30(b)
        vmmul.q E000, E100, E200
        sv.q C000, 0(c)
        sv.q C010, 0x10(c)
        sv.q C020, 0x20(c)
        sv.q C030, 0x30(c)
    }
    if (*(char **)(arg0 + 0x14C) != 0) {
        func_08860648(*(char **)(arg0 + 0x14C));
    }
    if (*(char **)(arg0 + 0x148) != 0) {
        func_08860648(*(char **)(arg0 + 0x148));
    }
}
