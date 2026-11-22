/* unit_08880350: 0x08880350-0x08880378 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;

extern void func_0889EA8C(void *p);

void func_08880350(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   s32 arg6) {
    *(s8 *)(arg0 + 0x158) = 1;
    *(s32 *)(arg0 + 0x15C) = arg1;
    *(s32 *)(arg0 + 0x160) = arg2;
    *(s32 *)(arg0 + 0x164) = arg3;
    *(s32 *)(arg0 + 0x168) = arg4;
    *(s32 *)(arg0 + 0x16C) = arg5;
    *(s32 *)(arg0 + 0x170) = arg6;
    func_0889EA8C(arg0 + 0x15C);
}
