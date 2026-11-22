/* unit_08883DE4: 0x08883DE4-0x08883FF0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function after unit_08883B54.
 */

typedef int s32;
typedef unsigned char u8;

extern s32 D_08A62D84;

extern s32 func_088840A8(char *, s32, s32, s32, s32 *, float *);
extern s32 func_0887FBBC(s32);
extern void func_088851C8(char *, s32, s32, s32 *, float *);
extern void func_08884E44(char *, s32, s32, s32 *, s32 *);
extern s32 func_08880884(char *, s32, s32);
extern s32 func_088838B0(char *, s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_08883DE4(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, u8 arg10) {
    s32 val;
    float scale;
    s32 id;
    float fval;
    s32 val2;
    s32 base;
    s32 ret;

    scale = 1.0f;
    id = -1;
    if (arg2 == -1) {
        return 0;
    }
    base = func_088840A8(arg0, arg1, arg2, arg6, &id, &scale);
    if (id != -1) {
        arg7 = id;
    }
    *(s32 *)(arg0 + 0x562438) = arg9;
    if (func_0887FBBC(D_08A62D84) == 2) {
        func_088851C8(arg0, arg6, arg7, &val, &fval);
        val = func_08880884(arg0, val, *(s32 *)(arg0 + 0x5623D0));
        if (arg10 == 0 && val <= 0) {
            return -1;
        }
        ret = func_088838B0(arg0, arg1, arg2, arg3, arg4, arg5, val, 0x40, *(s32 *)(arg0 + 0x562438) + 0x2000, arg8 + base);
    } else {
        func_08884E44(arg0, arg6, arg7, &val, &val2);
        val = func_08880884(arg0, val, *(s32 *)(arg0 + 0x5623D0));
        if (arg10 == 0 && val <= 0) {
            return -1;
        }
        ret = func_088838B0(arg0, arg1, arg2, arg3, arg4, arg5, val, 0x40, *(s32 *)(arg0 + 0x562438) + 0x2000, arg8 + base);
    }
    return ret;
}
