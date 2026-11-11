/* unit_0886D5E4: 0x0886D5E4-0x0886D644 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern char D_09BB89B0;

void func_0886D5E4(s32 arg0, char *arg1, s32 *arg2) {
    *(s16 *)(arg1 + 0x2E) = 2;
    *(s16 *)(arg1 + 0x32) = -1;
    *(s8 *)(arg1 + 0x34) = -1;
    *(s16 *)(arg1 + 0x2C) = (s16) *arg2;
    *(s8 *)(arg1 + 0x35) = (s8) ((u32) (*(u8 *)((char *)((&D_09BB89B0 + (*(s16 *)arg1 * 0x1D0))) + 0x5C) << 0x1D) >> 0x1F);
    *arg2 += 1;
}
