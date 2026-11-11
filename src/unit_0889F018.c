/* unit_0889F018: 0x0889F018-0x0889F07C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 D_09A0B5B0;
extern int func_0889EF04(s32);
extern int sceKernelStartVTimer(s32);

s32 func_0889F018(void) {
    sceKernelStartVTimer(D_09A0B5B0);
    return 0;
}

s32 func_0889F03C(s32 arg0, s32 arg1, s32 arg2, char *arg3) {
    *(s32 *)(arg3 + 8) = (s32) (*(s32 *)(arg3 + 8) + 1);
    func_0889EF04(2);
    func_0889EF04(0);
    return *(s32 *)(arg3 + 4);
}
