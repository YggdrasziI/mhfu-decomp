/* unit_088303A0: 0x088303A0-0x088303B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_0893AF20;

u8 func_088303A0(s32 arg0, s32 arg1) {
    return *(&D_0893AF20 + (arg1 & 0xFF));
}
