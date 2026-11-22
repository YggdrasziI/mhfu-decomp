/* unit_08883FF0: 0x08883FF0-0x088840A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D84;

extern s32 func_0887FBBC(s32);
extern void func_088851C8(char *, s32, s32, s32 *, float *);
extern void func_08884E44(char *, s32, s32, s32 *, s32 *);
extern s32 func_08880884(char *, s32, s32);

void func_08883FF0(char *arg0, s32 arg1, s32 arg2) {
    s32 val;
    float fval;
    s32 val2;

    if (func_0887FBBC(D_08A62D84) == 2) {
        func_088851C8(arg0, arg1, arg2, &val, &fval);
        val = func_08880884(arg0, val, *(s32 *)(arg0 + 0x5623D0));
    } else {
        func_08884E44(arg0, arg1, arg2, &val, &val2);
        val = func_08880884(arg0, val, *(s32 *)(arg0 + 0x5623D0));
    }
}
