/* unit_088846F4: 0x088846F4-0x08884748 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_08885088(char *, s32, s32, s32, s32 *, s32);
extern s32 func_08880884(char *, s32, s32);

void func_088846F4(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, float arg5) {
    s32 sp1C;

    *(float *)(arg0 + 0x562460) = arg5;
    func_08885088(arg0, arg1, arg2, arg3, &sp1C, arg4 + 1);
    sp1C = func_08880884(arg0, sp1C, *(s32 *)(arg0 + 0x5623D0));
}
