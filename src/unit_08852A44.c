/* unit_08852A44: 0x08852A44-0x08852A50 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

s32 func_08852A44(char *arg0) {
    return (s32) *(u8 *)(arg0 + 0x38D) < 2;
}
