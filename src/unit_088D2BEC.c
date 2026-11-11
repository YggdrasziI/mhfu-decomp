/* unit_088D2BEC: 0x088D2BEC-0x088D2C14 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

s32 func_088D2BEC(char *arg0, s16 arg1) {
    return *(s32 *)(arg0 + 0x1090) + (arg1 * 0x250) + 0x90;
}
