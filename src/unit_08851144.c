/* unit_08851144: 0x08851144-0x0885115C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

s32 func_08851144(char *arg0) {
    return (*(s32 *)(arg0 + 0x6AF14) & 0x10) != 0;
}
