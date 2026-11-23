/* unit_08865C88: 0x08865C88-0x08865CB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08865C88: test a flag bit; bit 31 selects the second flag word. */
typedef unsigned int u32;

u32 func_08865C88(char *arg0, u32 arg1) {
    if (arg1 & 0x80000000) {
        return *(u32 *)(arg0 + 0x28C) & (arg1 & 0x7FFFFFFF);
    }
    return *(u32 *)(arg0 + 0x288) & arg1;
}
