/* unit_08857A34: 0x08857A34-0x08857A80 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

s32 func_08857A34(char *arg0) {
    u32 flags = *(u32 *)(arg0 + 0x6ADF8);

    if ((s32)((flags & 1) != 0) == 1 || (s32)((flags & 2) != 0) == 1 ||
        (s32)((flags & 4) != 0) == 1) {
        return 1;
    }
    return 0;
}
