/* unit_088D27CC: 0x088D27CC-0x088D27F4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

s32 func_088D27CC(char *arg0) {
    if (*(u8 *)(arg0 + 0x4E9) != 6) {
        return 0;
    }
    return (*(u16 *)(arg0 + 0x4EC) & 0x40) != 0;
}
