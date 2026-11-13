/* unit_088DB488: 0x088DB488-0x088DB49C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

void func_088DB488(s32 arg0, char *arg1, s32 arg2) {
    ((char **)((char *)arg0 + 0xC))[arg2] = arg1;
    *(s8 *)(arg1 + 0x1E4) = arg2;
}
