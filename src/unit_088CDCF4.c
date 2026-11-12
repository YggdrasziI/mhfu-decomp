/* unit_088CDCF4: 0x088CDCF4-0x088CDD24 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

s32 func_088CDCF4(char *arg0) {
    if (*(u8 *)arg0 != 0) {
        return (*(u8 *)((*(char **)((char *)((arg0 + (*(u8 *)(arg0 + 1) << 5))) + 0x20)) + 0xA) & 1) != 0;
    }
    return 0;
}
