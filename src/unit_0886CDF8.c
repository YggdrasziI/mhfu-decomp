/* unit_0886CDF8: 0x0886CDF8-0x0886CE10 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 D_09A4F060;

u16 func_0886CDF8(s32 arg0, s32 arg1) {
    return *(u16 *)((char *)(((arg1 << 5) + D_09A4F060)) + 0x16);
}
