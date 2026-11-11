/* unit_08813560: 0x08813560-0x08813574 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

void func_08813560(char *arg0, s8 arg1, s32 arg2, s8 arg3) {
    *(s8 *)(arg0 + 0xAAA) = 0;
    *(s8 *)(arg0 + 0xA80) = arg1;
    *(s32 *)(arg0 + 0xA7C) = arg2;
    *(s8 *)(arg0 + 0xA7A) = arg3;
}
