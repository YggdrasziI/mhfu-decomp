/* unit_0884FAFC: 0x0884FAFC-0x0884FB38 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;

void func_0884FAFC(char *arg0, int arg1) {
    u16 mask = ~(1 << (arg1 & 0xF));
    ((u16 *)(arg0 + 0x508))[arg1 / 16] &= mask;
}
