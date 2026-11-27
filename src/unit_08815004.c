/* unit_08815004: 0x08815004-0x08815024 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

void func_08815004(char *arg0, s32 arg1) {
    char *p;

    p = arg0 + 0xB0;
    if (arg1 == 5) {
        arg1 = -1;
    }
    *(u8 *)(p + 0x92) = (arg1 >= 0) ? arg1 : 0xFF;
}
