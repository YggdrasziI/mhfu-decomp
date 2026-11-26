/* unit_0884FB38: 0x0884FB38-0x0884FB6C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884FB38: tests bit (arg1 & 15) of the 16-bit word arg1 / 16 of the
 * flag array at offset 0x508. */

typedef unsigned short u16;

int func_0884FB38(char *arg0, int arg1) {
    u16 w = ((u16 *)(arg0 + 0x508))[arg1 / 16];
    return (w & (1 << (arg1 & 0xF))) != 0;
}
