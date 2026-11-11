/* unit_0888664C: 0x0888664C-0x08886664 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

void func_0888664C(s32 arg0, s32 arg1) {
    char *temp_a0;

    temp_a0 = (char *) (arg0 + (arg1 * 0x10));
    *(u16 *)(temp_a0 + 0x3C) = 0xFFFF;
    *(s32 *)(temp_a0 + 0x38) = 0;
}
