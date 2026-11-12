/* unit_08822990: 0x08822990-0x088229B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

s32 func_08822990(s32 arg0, char *arg1) {
    if (*(u8 *)(arg1 + 0x4E9) == 6) {
        return 1;
    }
    return (s32) *(u8 *)(arg1 + 0x5F2) >= 1;
}
