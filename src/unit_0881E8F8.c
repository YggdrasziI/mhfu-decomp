/* unit_0881E8F8: 0x0881E8F8-0x0881E92C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

s32 func_0881E8F8(char *arg0) {
    *(s8 *)(arg0 + 0x57E) = 0;
    *(s8 *)(arg0 + 0x57F) = 0;
    *(s8 *)(arg0 + 0x5BB) = 0;
    *(s32 *)(arg0 + 0x5A8) = 0;
    *(s8 *)(arg0 + 0x5D9) = 0;
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) | 4);
    *(s8 *)(arg0 + 0x5FE) = 2;
    *(s16 *)(arg0 + 0x5FC) = 0;
    return 0;
}
