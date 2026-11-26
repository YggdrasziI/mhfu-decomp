/* unit_08832204: 0x08832204-0x08832228 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

u16 func_08832204(char *arg0) {
    u8 s = *(u8 *)(arg0 + 0x52F);
    if (s == 0 || s == 6) return 0;
    return *(u16 *)(arg0 + 0x590);
}
