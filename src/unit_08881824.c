/* unit_08881824: 0x08881824-0x08881840 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

void func_08881824(char *arg0) {
    *(s32 *)(arg0 + 0x8B94) = 0;
    *(s32 *)(arg0 + 0x8B98) = 0;
}
